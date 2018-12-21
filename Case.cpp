#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>
using namespace std;

Case::Case(int x, int y, Couleur c):positionX{x},positionY{}, couleur{c},etat{false}{

}
Case::Case(){

}
Case::~Case(){

}
void Case::affiche()const{
	/*std::string e = (etat==true)?"true":"false";
	std::cout<< "px: " << std::to_string(positionX) << " py: "
	 << std::to_string(positionY) << " couleur: " << couleur << " etat: " << e << std::endl;*/

	 if(etat==false){


	 if( couleur == Couleur::blanc){
	 cout<<"- "; }

	 else {

	 cout<<"X ";
	 }

	 }else{
 cout<<"J ";


	 }



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
