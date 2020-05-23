CC = clang

all: demo1 demo2 demo3 demo4 demo5_1 demo5_2 

compile: 
	$(CC) array.h array.c -c 
	ar rcs libarray.a array.o 
	
demo1: compile
	$(CC) demo1.c -o main1 array.o -L. -larray 

demo2: compile 
	$(CC) demo2.c -o main2 array.o -L. -larray 

demo3: compile 
	$(CC) demo3.c -o main3 array.o -L. -larray

demo4: compile 
	$(CC) demo4.c -o main4 array.o -L. -larray

demo5_1: compile 
	$(CC) demo5_1.c -o main5_1 array.o -L. -larray

demo5_2: compile 
	$(CC) demo5_2.c -o main5_2 array.o -L. -larray

clean: 
	rm -f main1 main2 main3 main4 main5_1 main5_2 libarray.a array.o array.h.gch 
