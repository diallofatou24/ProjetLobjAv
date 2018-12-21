#ifndef PIONT_H_INCLUDED
#define PIONT_H_INCLUDED
#include "Case.hpp"
#include "Couleur.hpp"
#include "type_piont.hpp"
class piont{

private:

int val;
Case* case_piont;
Couleur color;
type_piont type;



public:
piont();
piont(Case* c,int val,Couleur col,type_piont t);
virtual ~piont();



};

#endif // PIONT_H_INCLUDED
