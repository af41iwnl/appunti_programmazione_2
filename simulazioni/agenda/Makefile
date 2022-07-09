compito: compito.o liste.o tipo.o
	g++ -o compito compito.o liste.o tipo.o
compito.o:
	g++ -c compito.cc
liste.o:
	g++ -c liste.cc
tipo.o:
	g++ -c tipo.cc
.PHONY clean cleanall:
clean: 
	rm -f *.o
cleanall: 
	rm -f compito *.o