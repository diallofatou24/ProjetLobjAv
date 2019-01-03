
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
void restorer_pion_supprime(std::vector<Pion>& liste_sup,std::vector<std::vector<Case>>& cases);
	void supprimerPion(int i);
void affichePions()const;
void addPions(Couleur c, TypePion p);
Pion* verif_pion(std::string& valeur);


bool rafle(std::string cdepart,std::string cdest,std::vector<std::vector<Case>>& cases,Joueur& j,Pion& p_adverse,
bool verif);
bool deplacement(std::string cdepart,std::string cdest,std::vector<std::vector<Case>>& cases,bool verif);

Pion* verif_pion_rafle(Joueur& jj,std::vector<Case>& v);
bool liste_coup_valide(std::vector<std::vector<Case> >& cases,Joueur& j,bool verif);

void case_vide(std::vector<Case>& v);
bool aide_deplace_valide(Pion& p,std::vector<Case>& v,std::vector<std::vector<Case> >& cases,bool verif);
bool aide_rafle_valide(Pion& p,std::vector<Case>& v,std::vector<std::vector<Case> >& cases,Joueur& j,std::vector<Pion>&
liste_destruction,bool verif);

void destruction_pion(std::vector<Pion>& liste_detruite);

	virtual ~Joueur();

};
#endif
