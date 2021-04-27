all: main_num.c main_string.c

main_num.c: sort_num.o
	gcc main_num.c sort_num.o -o main_num

main_string.c: sort_string.o
	gcc main_string.c sort_string.o -o main_string 

sort_num.o: sort_num.c sort_num.h
	gcc -c sort_num.c -o sort_num.o

sort_string.o: sort_string.c sort_string.h
	gcc -c sort_string.c -o sort_string.o

clean:
	rm -f sort_num.o sort_string.o main_num main_string