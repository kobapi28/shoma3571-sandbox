ALL: a.out

main.o: main.cpp
	c++ -c main.cpp

func.o: func.cpp
	c++ -c func.cpp

func1.o: func1.cpp
	c++ -c func1.cpp

libfunc.a: func.o func1.o
	ar r libfunc.a func.o func1.o

a.out: main.o libfunc.a
	c++ -o a.out main.o libfunc.a