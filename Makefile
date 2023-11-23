CC=gcc
LDFLAGS=-lm -lglfw3 -lGL -L./vendor/glad -lglad -L./vendor/cglm -lcglm -lX11 -lpthread -lXrandr -lXi -ldl
PPFLAGS=-I./rcgfw/include -I./vendor/glad/include -I./vendor/stbimage/include -I./vendor/cglm/include
OUT=-o ./build/prototype

.SILENT:
libcomp: ./rcgfw/src/*.c
	echo compiling...
	gcc -std=c99 -c $(PPFLAGS) $^ $(LDFLAGS)
	echo creating archive...
	sleep 2.5
	ar rcs build/librcgfw.a $(wildcard *.o)
	echo copying dependencies
	cp -r vendor/cglm/include/cglm/ build/include/
	cp vendor/cglm/libcglm.a build/libcglm.a
	cp -r vendor/glad/include/glad/ build/include/
	cp -r vendor/glad/include/KHR/ build/include/
	cp vendor/glad/libglad.a build/libglad.a
	cp -r vendor/stbimage/include/stbimage/ build/include/
	cp rcgfw/include/*.h build/include/RCGFW/
	echo copying build to "GL Breakout"...
	rm -r /programming/c/glbreakout/vendor/*
	sleep 1
	cp -r build/* /programming/c/glbreakout/vendor
	echo done!