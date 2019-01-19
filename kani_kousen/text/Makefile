all:
	rgbasm -o text.o text.asm
	rgblink -o write.gb text.o 
	rgbfix -v -p 0 write.gb

clean:
	rm *.o *.gb

write:
	sameboy write.gb
