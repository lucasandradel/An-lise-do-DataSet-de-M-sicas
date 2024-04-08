all: lista_dup.o
	gcc main.c lista_dup.o -o prog
	./prog


lista_dup.o: lista_dup.c
	gcc -c lista_dup.c

clean:

	rm *.o prog