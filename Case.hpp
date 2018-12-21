#ifndef  CASE_HPP
#define CASE_HPP
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
public:
	Case(int px, int py, Couleur c);
	virtual ~Case();
	void affiche();
	void setEtat(bool e);
	int getPositionX();
	int getPositionY();
	Couleur getCouleur();
	bool getEtat();
}

#endif