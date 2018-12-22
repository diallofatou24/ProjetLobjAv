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
virtual ~Pion();
};
#endif // PION_HPP
 