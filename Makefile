all: black_tiger.sgx black_tiger.iso

include ../Make_ex.inc

SRC = Black_Tiger.c

CFLAGS ?= -O2 --sgx -fno-recursive -gA -v
CDFLAGS = --scd
LIBS =

black_tiger.iso: $(SRC)
	$(CC) $(CFLAGS) $(CDFLAGS) $< $(LIBS)

black_tiger.sgx: $(SRC) black_tiger.iso
	$(CC) $(CFLAGS) $< $(LIBS)
