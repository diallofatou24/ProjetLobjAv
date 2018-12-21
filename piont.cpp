#include "piont.hpp"
#include "type_piont.hpp"
#include <iostream>

using namespace std;

piont:: piont():val{0}{}

piont::piont(Case* c,int valeur,Couleur col,type_piont typ):case_piont{c},val{valeur},color{col},type{typ}{
}
piont:: ~piont(){}
