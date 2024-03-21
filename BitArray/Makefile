bitarray: main7.o bitarray.o
	g++ -o bitarray main7.o bitarray.o

main7.o: main7.cpp sieve.h
	g++ -c main7.cpp

bitarray.o: bitarray.h bitarray.cpp
	g++ -c bitarray.cpp

clean: 
	rm *.o bitarray
