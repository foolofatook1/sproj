all:
	make clean
	rgbasm -o main.o main.asm
	rgblink -o play.gb main.o 
	rgbfix -v -p 0 play.gb
	make play

clean:
	rm *.o *.gb

play:
	sameboy play.gb
