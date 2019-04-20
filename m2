2_7: 2_7.o list.o
2_7.o:2_7.c
	gcc -c 2_7.c -o 2_7.o
list.o:list.c
	gcc -c list.c -o list.o
clean:
	-rm -rf *.o	
      
