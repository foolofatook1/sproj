all:
	gcc -c -Wimplicit-function-declaration ascii.c
	gcc -o test ascii.o
	#lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c ascii.c
	#lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -o ascii.gb ascii.o

clean:
	rm -f ascii.o .ascii.* ascii.map ascii.lst ascii.gb ascii.sym

go:
	./test
	#~/bgb/bgb.exe ascii.gb
