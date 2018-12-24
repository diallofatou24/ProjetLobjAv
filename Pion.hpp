#ifndef PION_HPP
#define PION_HPP
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
virtual ~Pion();
};
#endif // PION_HPP
 