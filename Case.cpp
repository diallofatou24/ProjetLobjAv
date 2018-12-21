#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>

Case::Case(int x, int y, Couleur c):positionX{x},positionY{}, couleur{c} {

}
Case::~Case(){

}
void Case::affiche()const{
	std::string e = (etat==true)?"true":"false";
	std::cout<< "px: " << std::to_string(positionX) << " py: "
	 << std::to_string(positionY) << " couleur: " << couleur << " etat: " << e << std::endl;
}
void Case::setEtat(bool b){
	etat = b;
}
Couleur Case::getCouleur(){
	return couleur;
}
int Case::getPositionX(){
	return positionX;
}
int Case::getPositionY(){
	return positionY;
}
bool Case::getEtat(){
	return etat;
}
