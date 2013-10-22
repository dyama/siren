
MRUBYROOT = /home/dyama/prog/ruby/mruby/mruby-iij

PROGRAM = libmirb.so
CC = g++
OBJ = debug.o mirb.o
CFLAGS = -Wall -O2

.PHONY: all
all: $(OBJ)
	$(CC) -static -g -o mydebug -L$(MRUBYROOT)/build/host/lib $(MRUBYROOT)/build/host/lib/libmruby.a -lmruby $<

.cpp.o:
	$(CC) -c $(CFLAGS) -I$(MRUBYROOT)/include $<

.PHONY: clean
clean:
	-rm -f $(PROGRAM) $(OBJ) mydebug

