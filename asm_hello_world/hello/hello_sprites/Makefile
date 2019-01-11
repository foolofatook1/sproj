all:
	rgbasm -o main.o main.asm
	rgblink -o hello_world.gb main.o 
	rgbfix -v -p 0 hello_world.gb

clean:
	rm *.o *.gb
