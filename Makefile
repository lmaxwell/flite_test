CFLAGS=-I../flite/include
LDFLAGS=-L../flite/build/x86_64-linux-gnu/lib/ -lflite_cmulex  -lflite -lm -lasound 
all:
	gcc -g -c $(CFLAGS)  test.c -o test.o
	gcc -g -o test  test.o $(LDFLAGS)   
