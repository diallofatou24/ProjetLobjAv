
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
Pion* verif_pion(std::string& valeur);
bool deplacement(Pion* p,Case& c);
std::vector<Case> diagonale(Case c,std::vector<std::vector<Case> >* cases,bool haut,bool droite,bool gauche,
bool bas);


std::vector<Case> rafle_de_pion(Pion* p,Case& c,std::vector<std::vector<Case>>* cases);
void trouver_pion_adverse(std::vector<Case>& v,Case& c,bool haut,bool droite,bool gauche,
bool bas);

bool deplacement_de_pion(Pion* p,Case& c,int id);

std::vector<Case> rafle(Pion* p,Case& c,std::vector<std::vector<Case>>* cases);

	virtual ~Joueur();

};
#endif
