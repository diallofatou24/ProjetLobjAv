#include "Pion.hpp"
#include "TypePion.hpp"
#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>

//using namespace std;

Pion::Pion():valeur{0}, casePion{nullptr}, color{Couleur::null},type{TypePion::null}{}

Pion::Pion(int val, Case* c, Couleur col,TypePion typ): valeur{val}, casePion{c}, color{col}, type{typ} {


}
Pion::~Pion(){}
