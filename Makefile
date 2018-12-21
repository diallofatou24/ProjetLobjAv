C= g++ --std=c++11 -Wall

Case.o: Case.cpp Case.cpp Couleur.hpp
	$(C) -c Case.cpp
