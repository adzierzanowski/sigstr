#!/usr/bin/env python3

'''
This script demangles names in assembly output from swift compiler in order
to enable using `extern` in C easily.
It also comments out `.globl _main`.
'''

import logging
import os
import re
import subprocess
import sys

from typing import List


def load_assembly(fname):
  logging.debug(f'Loading assembly: `{fname}`')
  with open(fname, 'r') as f:
    data = [line.strip() for line in f.read().splitlines()]
  return data

def demangle_lines(lines: List[str], basename: str):
  logging.debug('Demangling lines')
  mangles = {}

  for i, line in enumerate(lines):
    try:
      spline = re.split(r'\s', line)

      if '_main' in spline:
        lines[i] = '#' + line

      # .private_extern is the first directive that a mangled name appears in
      if '.private_extern' in spline:
          _, mangled = spline

          sdm = subprocess.check_output(('swift', 'demangle', mangled)).decode('ascii')
          demangled = sdm.split('->')[1].strip()
          if basename in demangled:
            logging.debug(f'Found mangled name @ line #{i}: {mangled}')

            demangled = demangled.replace(basename, '')
            demangled = '_' + demangled.translate({ord(c): '' for c in '.()'})
            
            rejoined = line.replace(mangled, demangled)
            mangles[mangled] = demangled

            logging.debug(f'Adding demangled name: {demangled}')
      
      for m in mangles:
        if m in line:
          lines[i] = line.replace(m, mangles[m])

    except Exception as e:
      logging.error(f'@ ./{os.path.relpath(basename+".s")}:{i}: {e}')
      continue

def dump_lines(lines, fname):
  logging.debug('Writing the output assembly')
  with open(fname, 'w') as f:
    f.write('\n'.join(lines))

def main():
  logging.basicConfig(
    level=logging.DEBUG,
    format='%(msecs)d -- %(levelname)s: %(message)s'
  )

  asm_fname = sys.argv[1]
  asm_base = os.path.splitext(asm_fname)[0]

  data = load_assembly(asm_fname)
  demangle_lines(data, asm_base)
  dump_lines(data, asm_fname)

if __name__ == '__main__':
  main()
