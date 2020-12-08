run: octaveSim.o S2DE.o
	gcc -Wall -o run octaveSim.o S2DE.o -lm -lglut -lGL
	rm -f *.o



#octave simulator
octaveSim.o: octaveSim.c S2DE.h
	gcc -Wall -O2 -c octaveSim.c



#S2DE management (use S2DE.o/.h to access to 2D graphic engine)
S2DE.o: S2DE.c S2DE.h
	gcc -Wall -O2 -c S2DE.c -I/usr/include/GL

