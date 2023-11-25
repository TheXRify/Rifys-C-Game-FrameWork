CC=gcc
LDFLAGS=-lm -lglfw3 -lGL -L../vendor/glad -lglad -L../vendor/cglm -lcglm -lX11 -lpthread -lXrandr -lXi -ldl
PPFLAGS=-std=c99 -c -ggdb -O3 -c -I./include -I../vendor/glad/include -I../vendor/stbimage/include -I../vendor/cglm/include

.SILENT:
libcomp: $(wildcard src/*.c)
	echo compiling...
	$(CC) $(PPFLAGS) $^ $(LDFLAGS)
	echo creating archive...
	sleep 2.5
	ar rcs ../build/rcgfw/librcgfw.a $(wildcard *.o)
	echo copying librcgfw...
	cp -r ../build/rcgfw/librcgfw.a ../vendor/rcgfw/librcgfw.a
	echo copying headers...
	cp -r ./include/*.h ../vendor/rcgfw/include/rcgfw/