
MRUBYROOT = /home/dyama/prog/ruby/mruby/mruby-iij
#MRUBYROOT = /home/dyama/prog/ruby/mruby/mruby-org

PROGRAM = mydebug
CC = g++
SRC = debug.cpp mirb.cpp
OBJ = debug.o mirb.o
CFLAGS = -m32 -Wall -Wno-write-strings -O2
LIBPATH = $(MRUBYROOT)/build/host/lib

.PHONY: all
all: $(OBJ)
	$(CC) -g $(CFLAGS) -I$(MRUBYROOT)/include -o $(PROGRAM) $(OBJ) $(LIBPATH)/libmruby.a

.cpp.o:
	$(CC) -c $(CFLAGS) -I$(MRUBYROOT)/include $<

.PHONY: clean
clean:
	-rm -f $(PROGRAM) $(OBJ)

