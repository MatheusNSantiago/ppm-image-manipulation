CFLAGS = -Wall
CC = gcc

OBJDIR = objects
BINDIR = bin

SRC := $(shell find . -name '*.c')
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: objfolder main

main: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

objfolder:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%main.o: src/main.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: %.c %.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -Rf bin objects main