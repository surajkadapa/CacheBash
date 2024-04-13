CC = gcc

SRCDIR = src
BINDIR = bin
SRCFILES += src/main.c
SRCFILES += lib/hex_to_bin.c
SRCFILES += lib/directMapped.c
SRCFILES += lib/fullyAssociativeFIFO.c
SRCFILES += lib/utils.c

EXECUTABLE = cache_simulator

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC)  $(SRCFILES) -o $(BINDIR)/$(EXECUTABLE) -lm

clean:
	rm -rf $(BINDIR) $(EXECUTABLE)
