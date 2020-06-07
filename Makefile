DEMANGLER = "./demangle-asm"
ASM_SRC = sigstr.s
C_SRC = main.c wifi_helper.c
CFLAGS = -L /usr/lib/swift -O3 -Wall -Wpedantic
EXE = sigstr

all:
	swiftc -S sigstr.swift > $(ASM_SRC)
	$(DEMANGLER) $(ASM_SRC)
	$(CC) $(C_SRC) $(ASM_SRC) -L /usr/lib/swift -o $(EXE)

clean:
	rm $(ASM_SRC) $(EXE)
