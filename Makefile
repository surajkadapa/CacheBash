CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm

SRCDIR = src
BINDIR = bin
LIBDIR = lib

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

EXECUTABLE = cache_simulator

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) -o $(BINDIR)/$(EXECUTABLE) $(SRCDIR)/main.c $(LIBDIR)/hex_to_bin.c -lm
	$(BINDIR)/$(EXECUTABLE)
clean:
	rm -rf $(BINDIR) $(EXECUTABLE)