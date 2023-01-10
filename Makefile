all:
	cc main.c -Wall -lm -o main
clean:
	 rm main 
install:
	 cp main /usr/local/bin 
