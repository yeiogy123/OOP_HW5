all:Mixed.o main.o
	g++ -g Mixed.o main.o -o main
main.o:
	g++ -c main.cpp -o main.o
Mixed.o:
	g++ -c Mixed.cpp -o Mixed.o
clean:
	rm -f Mixed.o main.o main