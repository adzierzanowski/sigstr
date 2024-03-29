PY = python3
DEMANGLER = "./demangle-asm.py"
ASM_SRC = sigstr.s
C_SRC = main.c wifi_helper.c
CFLAGS = -L /usr/lib/swift -O3 -Wall -Wpedantic
EXE = sigstr

all:
	swiftc -O -S sigstr.swift > $(ASM_SRC)
	$(PY) $(DEMANGLER) $(ASM_SRC)
	$(CC) $(C_SRC) $(ASM_SRC) -L /usr/lib/swift -o $(EXE)

clean:
	rm $(ASM_SRC) $(EXE)
