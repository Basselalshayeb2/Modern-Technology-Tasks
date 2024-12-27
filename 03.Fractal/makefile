CC = gcc
CFLAGS = -Wall -O2 -lm

FRACTAL_OBJS = fractal.o image.o

all: fractal test_fractal

fractal: $(FRACTAL_OBJS) main.o
	$(CC) $(CFLAGS) -o fractal $(FRACTAL_OBJS) main.o

test_fractal: $(FRACTAL_OBJS) test_fractal.o
	$(CC) $(CFLAGS) -o test_fractal $(FRACTAL_OBJS) test_fractal.o

fractal.o: fractal.c fractal.h
	$(CC) $(CFLAGS) -c fractal.c

image.o: image.c image.h
	$(CC) $(CFLAGS) -c image.c

main.o: main.c fractal.h
	$(CC) $(CFLAGS) -c main.c

test_fractal.o: test_fractal.c fractal.h
	$(CC) $(CFLAGS) -c test_fractal.c

clean:
	rm -f *.o fractal test_fractal
