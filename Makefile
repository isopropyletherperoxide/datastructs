all:
	cc main.c linked_list.c -Wall -lm -o main
clean:
	 rm main 
install:
	 cp main /usr/local/bin 
