PROGRAM = mage
CC      = gcc
CFLAGS  = -g -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
FILES = scena.o modeli.o timers.o
LDLIBS  = -lglut -lGLU -lGL -lm


$(PROGRAM): scena.o modeli.o timers.o main.o
	$(CC) $(LDFLAGS)  -o $(PROGRAM) main.o $(FILES) $(LDLIBS)
	
modeli.o: modeli.c
	$(CC) $(LDFLAGS) -c modeli.c $(LDLIBS)
	
scena.o: scena.c
	$(CC) $(LDFLAGS) -c scena.c $(LDLIBS)
	
timers.o: timers.c
	$(CC) $(LDFLAGS) -c timers.c $(LDLIBS)


.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
