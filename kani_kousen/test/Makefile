all:
	rgbasm -o main.o main.asm
	rgblink -o play.gb main.o 
	rgbfix -v -p 0 play.gb

clean:
	rm *.o *.gb

play:
	sameboy play.gb
