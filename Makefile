C= g++ --std=c++11 -Wall
all:dame

dame: main.o JeuDameFrancais.o Pion.o Case.o Joueur.o Case.hpp Couleur.hpp Joueur.hpp
	$(C) -o dame main.o JeuDameFrancais.o Pion.o Case.o Joueur.o 
main.o: main.cpp JeuDameFrancais.hpp 
	$(C) -c  main.cpp


JeuDameNationnale.o: JeuDameFrancais.cpp  JeuDameFrancais.hpp 
	$(C) -c JeuDameFrancais.cpp

Pion.o: Pion.cpp Pion.hpp TypePion.hpp Case.hpp Couleur.hpp
	$(C) -c Pion.cpp
Case.o: Case.cpp Case.cpp Couleur.hpp
	$(C) -c Case.cpp
Joueur.o: Joueur.cpp Joueur.hpp Pion.hpp
	$(C) -c Joueur.cpp



clean:
	rm -f *.o dame