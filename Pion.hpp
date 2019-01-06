#ifndef PION_HPP
#define PION_HPP
#include <vector>
#include "Case.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
class Pion{

private:

int valeur;
Case* casePion;
Couleur color;
TypePion type;

public:
Pion();
Pion(int val,Case* c, Couleur col,TypePion t);
Pion(int val,Case& c, Couleur col,TypePion t);
int getValeur();
Case *  getCasePion();
Couleur getColor();
TypePion getType();
void setValeur(int v);
void setCasePion(Case * c);
void setColor(Couleur c);
void setType(TypePion p);
  void aff()const;
bool deplacement_valid(Case& c,int id_joueur);
bool deplacement_de_pion(Case& c,int id_joueur,int taille_damier,bool verif);
bool deplacement_de_dame(Case& c,std::vector<std::vector<Case>>* cases,int id_joueur,bool verif);

bool rafle_de_pion(Case& c,std::vector<std::vector<Case>>* cases,std::vector<Case>& list_pion_adverse,bool verif);
bool rafle_de_dame(Case& c,std::vector<std::vector<Case>>* cases,std::vector<Case>& list_pion_adverse,bool verif);
std::vector<Case> diagonale(Case c,std::vector<std::vector<Case>>* cases, bool haut,bool droite,bool gauche,
bool bas);
bool trouver_pion_adverse(std::vector<Case>& list_diagonal,Case& c,bool haut,bool droite,bool gauche,
bool bas);
void mise_jour_rafle_plateau(Case& c,int id_joueur,int taille_damier);



virtual ~Pion();
};
#endif // PION_HPP