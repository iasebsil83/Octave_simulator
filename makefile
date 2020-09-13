exe: octavesim.o libisentlib.a
	gcc -Wall -o octave octavesim.o libisentlib.a -lm -lglut -lGL -lX11
	rm -f *.o


#GfxLib management (use libisentlib.a to use access to graphic engine)
libisentlib.a: ESLib.o GfxLib.o
	ar r libisentlib.a ESLib.o GfxLib.o
	ranlib libisentlib.a

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	gcc -Wall -O2 -c ESLib.c

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	gcc -Wall -O2 -c GfxLib.c -I/usr/include/GL

clean:
	rm -f *~ *.o

deepclean: clean
	rm -f exe libisentlib.a

