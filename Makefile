all:
	#cat windows.h example.c > main.c
	#gcc main.c -o main
	gcc -g -DUNICODE -fms-extensions example.c -lSDL2 
	#valgrind --leak-check=full ./a.out 
	./a.out
	#sleep 2.3
	#akill