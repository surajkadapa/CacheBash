CC = gcc

SRCDIR = src
BINDIR = bin
SRCFILES += src/main.c
SRCFILES += lib/hex_to_bin.c

EXECUTABLE = cache_simulator

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(SRCFILES) -o $(BINDIR)/$(EXECUTABLE) -lm
	$(BINDIR)/$(EXECUTABLE)
clean:
	rm -rf $(BINDIR) $(EXECUTABLE)