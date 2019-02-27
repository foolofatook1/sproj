all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o text.o text.c
#	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -o text.gb text.o

clean:
	rm *.o *.lst

write:
	wine ../bgb/*.exe text.gb
