#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>
using namespace std;

Case::Case(int x, int y, Couleur c, std::string val):positionX{x},positionY{y}, couleur{c},etat{false},valeur{val}{


}
Case::Case(){

}
Case::Case(int x, int y, Couleur c, bool et,std::string val):positionX{x},positionY{y}, couleur{c},etat{et},valeur{val}{


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
std::string Case::getValeur(){return valeur;}
void Case::setValEtat(std::string v , bool et){
	valeur= v;
	etat = et;
}
void Case::setValeur(std::string v){
	valeur = v;
}

void Case::setPositionX(int x){

positionX=x;

}

void Case::setPositionY(int y){

positionY=y;
    }
    void  Case::aff(){
    	std::cout << positionX << ", "<< positionY << ", " <<couleur <<", " << boolalpha << etat << " valeur: " << valeur;

    }
