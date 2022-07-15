compito: compito.o coda.o grafi.o node.o
	g++ -o compito compito.o coda.o grafi.o node.o

compito.o:
	g++ -c compito.cpp
coda.o:
	g++ -c coda.cpp
grafi.o:
	g++ -c grafi.cpp
node.o:
	g++ -c node.cpp
.PHONY clean cleanall:
clean:
	rm -f *.o
cleanall:
	rm -f compito *.o