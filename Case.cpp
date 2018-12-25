#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>
using namespace std;

Case::Case(int x, int y, Couleur c, std::string val):positionX{x},positionY{y}, couleur{c},etat{false},valeur{val}{
	

}
Case::Case(){

}
Case::~Case(){

}
void Case::affiche()const{
	
std::cout << valeur ;
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
void Case::setValEtat(std::string v , bool et){
	valeur= v;
	etat = et;
}
void Case::setValeur(std::string v){
	valeur = v;
}
