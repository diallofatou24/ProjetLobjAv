#include "Pion.hpp"
#include "TypePion.hpp"
#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>

//using namespace std;

Pion::Pion():valeur{0}, casePion{nullptr}, color{Couleur::null},type{TypePion::null}{}
Pion::Pion(int val, Case* c, Couleur col,TypePion typ): valeur{val}, casePion{c}, color{col}, type{typ} {}

Pion::Pion(int val, Case& c, Couleur col,TypePion typ): valeur{val}, casePion{&c}, color{col}, type{typ} {}
Pion::~Pion(){}
int Pion::getValeur(){
	return valeur;
}
Case *  Pion::getCasePion(){
	return casePion;
}
Couleur Pion::getColor(){
	return color;
}
TypePion Pion::getType(){
	return type;
}
void Pion::setValeur(int v){
	valeur = v;
}
void Pion::setCasePion(Case * c){
	casePion = c;
}
void Pion::setColor(Couleur c){
	color = c;
}
void Pion::setType(TypePion p){
	type = p;
}

    void  Pion::aff()const{
    	std::cout << "valeur: " << valeur << " Case: ";
    	casePion->aff();
    	std::cout<< " Couleur: " << color << " type: "<< type << std::endl; 
    }
