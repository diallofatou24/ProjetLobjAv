#ifndef  CASE_HPP
#define CASE_HPP
#include "Couleur.hpp"

/* classe case qui represente des cases du plateau
* elle est compose des attributs suivants;
la position X, Position Y, la couleur de la case: soit blanc ou noir pour la dames et autre couleur pour stratego
* un etat qui est true si elle contient un pion, false sion
*/
class Case{
private:
	int positionX;
	int positionY;
	Couleur couleur;
		bool etat;
	std::string valeur;

public:
     Case();
	Case(int px, int py, Couleur c, std::string);
	virtual ~Case();
	void affiche()const;
	void setEtat(bool e);
	void setValeur(std::string);
	int getPositionX();
	int getPositionY();
    void setPositionX(int x);
    void setPositionY(int y);
	Couleur getCouleur();
	bool getEtat();
	void setValEtat(std::string v , bool et);
};

#endif
