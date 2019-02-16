a.out: main.o Book.o Library.o
	g++ main.o Book.o Library.o
Book.o: Book.cc Book.h
	g++ -c Book.cc
Library.o: Library.cc Library.h
	g++ -c Library.cc
main.o: main.cc
	g++ -c main.cc

