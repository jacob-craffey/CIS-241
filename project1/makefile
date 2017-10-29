all: functions.h functions.o p1.o
	gcc -o p functions.o p1.o

p1.o: functions.h p1.c
	gcc -c p1.c

functions.o: functions.h functions.c
	gcc -c functions.c

enc: 
	./p e XINLIWANG plain1 cipher1

dec: 
	./p d XINLIWANG cipher1 discoveredPlain1

test:
	./p e XINLIWANG plain1 cipher1
	./p d XINLIWANG cipher1 discoveredPlain1
	diff -s plain1 discoveredPlain1

clean:
	rm -f *.o p1 p discoveredPlain1 cipher1
