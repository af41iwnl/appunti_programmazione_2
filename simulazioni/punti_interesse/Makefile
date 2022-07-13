compito: compito.o grafo.o liste.o tipo.o
	g++ -o compito compito.o grafo.o liste.o tipo.o
compito.o:
	g++ -c compito.cpp
grafo.o:
	g++ -c grafo.cpp
liste.o:
	g++ -c liste.cpp
tipo.o:
	g++ -c tipo.cpp
.PHONY clean cleanall:
clean:
	rm -f *.o
cleanall:
	rm -f compito *.o