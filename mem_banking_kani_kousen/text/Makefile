all:
	lcc -Wa-l -Wl-m -Wl-j -c -o text.o text.c

clean:
	rm *.o *.lst

write:
	wine ../bgb/*.exe text.gb
