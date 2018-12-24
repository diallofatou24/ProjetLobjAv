#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include "Pion.hpp"
#include <vector>

class Joueur
{private:
	int id;
	std::string nom;
	std::vector<Pion> pions;
	int score;
public:
	Joueur();
	Joueur(int id, std::string ns, int size);
	int getId();
	std::string getNom();
	std::vector<Pion> getPions();
	int getScore();
	void setCasePions(int idx, Case& c);
	void setTypePions(int idx, TypePion tp);
	void setScore(int c);
void affichePions()const;
void addPions(Couleur c, TypePion p);
	virtual ~Joueur();
	
};
#endif