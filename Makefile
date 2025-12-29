all: black_tiger.sgx

include ../Make_ex.inc

SRC = Black_Tiger.c

CFLAGS ?= -O2 --sgx -fno-recursive -gA -v

black_tiger.sgx: $(SRC)
	$(CC) $(CFLAGS) $<
