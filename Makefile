all:
	cc main.c linked_list.c -Wall -lm -o main
clean:
	 rm main
tidy: 
	clang-tidy main.c linked_list.c
install:
	 cp main /usr/local/bin 
