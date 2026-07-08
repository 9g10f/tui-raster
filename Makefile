out = -o tui-raster.o
flags = -lm

build: src/main.c src/obj-loader.c
	gcc src/main.c src/obj-loader.c src/matrix-math.c $(out) $(flags)

clean: tui-raster.o
	rm tui-raster.o
	gcc src/main.c src/obj-loader.c src/matrix-math.c $(out) $(flags)

obj-loader.c: include/obj-loader.h
matrix-math.c: include/matrix-math.h