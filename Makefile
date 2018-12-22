C= g++ --std=c++11 -Wall
all:dame

dame: main.o Pion.o Case.o  
	$(C) -o dame main.o Pion.o Case.o 

main.o: main.cpp Case.hpp Couleur.hpp
	$(C) -c main.cpp

Pion.o: Pion.cpp Pion.hpp TypePion.hpp Case.hpp Couleur.hpp
	$(C) -c Pion.cpp
Case.o: Case.cpp Case.cpp Couleur.hpp
	$(C) -c Case.cpp



clean:
	rm -f *.o dame