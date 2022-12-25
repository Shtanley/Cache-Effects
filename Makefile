all: exp1 exp2 exp3

exp1: exp1.o
	g++ -Wall -o exp1 exp1.o

exp1.o: exp1.cpp
	g++ -Wall -o exp1.o -c exp1.cpp

exp2: exp2.o
	g++ -Wall -o exp2 exp2.o

exp2.o: exp2.cpp
	g++ -Wall -o exp2.o -c exp2.cpp

exp3: exp3.o
	g++ -Wall -o exp3 exp3.o

exp3.o: exp3.cpp UList.h
	g++ -Wall -o exp3.o -c exp3.cpp

clean:
	rm -f exp1 exp2 exp3 *.o
	rm -f exp1 exp2 exp3*.exe