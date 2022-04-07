all:
	#cat windows.h example.c > main.c
	#gcc main.c -o main
	gcc -g -DUNICODE example.c -lSDL2
	#valgrind --leak-check=full ./a.out 
	./a.out
	#sleep 2.3
	#akill