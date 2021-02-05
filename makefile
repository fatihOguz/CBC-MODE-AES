
main: main.c cbc.c cbc.h
	gcc main.c -o main 
	./main key.txt sbox.txt invSbox.txt IV.txt plainText1.txt plainText2.txt plainText3.txt 

clean: 
	rm main