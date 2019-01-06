#include "Pion.hpp"
#include "TypePion.hpp"
#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>

using namespace std;

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


//*********************************************************************************************************

bool Pion::deplacement_valid(Case& c,int id_joueur){

if(this!=0){


if(c.getEtat()==0 && c.getCouleur()==Couleur::noir){
//test des pion et damee selon le type
return true;

//finn test

}else{
cout<<"la case de destination est invalide"<<endl;

return false;


}

}else{

cout<<"vous ne pouvez pas bouger ce pion"<<endl;

//return false;

}
return false;


}

//****************************************************************************************************************

bool Pion::deplacement_de_pion(Case& c,int id_joueur,int taille_damier,bool verif){


if(deplacement_valid(c,id_joueur)){

if(id_joueur==1 && this->getCasePion()->getPositionX()+1==c.getPositionX()&&(this->getCasePion()->getPositionY()-1==c.getPositionY() ||
this->getCasePion()->getPositionY()+1==c.getPositionY())){

return true;

}else if(id_joueur==2 && this->getCasePion()->getPositionX()-1==c.getPositionX()&&(this->getCasePion()->getPositionY()-1==c.getPositionY() ||
this->getCasePion()->getPositionY()+1==c.getPositionY())){

return true;

}else{
if(verif){

cout<<"Un Deplacement se fait qu'en diagonale et d'une seule case à la fois "<<endl;}

return false;
}


return false;


}else{return false;}


}
//******************************************************************************************************************

bool Pion::deplacement_de_dame(Case& c,vector<vector<Case>>* cases,int id_joueur,bool verif){

if(deplacement_valid(c,id_joueur)){
vector<Case> list_case_diagonal;
bool condition;

//__________________________________

if(c.getPositionX()>this->getCasePion()->getPositionX()&& c.getPositionY()> this->getCasePion()->getPositionY()){
list_case_diagonal=diagonale(*this->getCasePion(),cases,0,1,0,1);
condition=trouver_pion_adverse(list_case_diagonal,c,0,1,0,1);


}else if(c.getPositionX()>this->getCasePion()->getPositionX()&& c.getPositionY()< this->getCasePion()->getPositionY()){
 list_case_diagonal=diagonale(*this->getCasePion(),cases,0,0,1,1);
 condition=trouver_pion_adverse(list_case_diagonal,c,0,0,1,1);


}else if (c.getPositionX()<this->getCasePion()->getPositionX() && c.getPositionY()< this->getCasePion()->getPositionY()){
list_case_diagonal= diagonale(*this->getCasePion(),cases,1,0,1,0);
condition=trouver_pion_adverse(list_case_diagonal,c,1,0,1,0);


}else if((c.getPositionX()<this->getCasePion()->getPositionX() && c.getPositionY()> this->getCasePion()->getPositionY())){
list_case_diagonal= diagonale(*this->getCasePion(),cases,1,1,0,0);
condition=trouver_pion_adverse(list_case_diagonal,c,1,1,0,0);

}else{
if(verif){
cout<<"Un Deplacement se fait qu'en diagonale"<<endl;}
return false;
}

if(condition){

for(int i=0;i<(int)list_case_diagonal.size();i++){

if(list_case_diagonal[i].getEtat())
{

if(verif){
cout<<"DEPLACEMENT INVALIDE : il ya des pieces sur la diagonale"<<endl;}
return false;
}

}




return true;

}

return false;


//----------------------------------------------------------

}else{



return false;
}

}


//***********************************************************************************************************************

bool Pion::rafle_de_pion(Case& c,vector<std::vector<Case>>* cases,vector<Case>& list_pion_adverse,bool verif){

if(deplacement_valid(c,0)){

if(c.getPositionX()>this->getCasePion()->getPositionX()&& c.getPositionY()> this->getCasePion()->getPositionY()){

list_pion_adverse=diagonale(*this->getCasePion(),cases,0,1,0,1);
trouver_pion_adverse(list_pion_adverse,c,0,1,0,1);



}else if(c.getPositionX()>this->getCasePion()->getPositionX()&& c.getPositionY()< this->getCasePion()->getPositionY()){
 list_pion_adverse=diagonale(*this->getCasePion(),cases,0,0,1,1);
trouver_pion_adverse(list_pion_adverse,c,0,0,1,1);


}else if (c.getPositionX()<this->getCasePion()->getPositionX() && c.getPositionY()< this->getCasePion()->getPositionY()){
list_pion_adverse= diagonale(*this->getCasePion(),cases,1,0,1,0);
trouver_pion_adverse(list_pion_adverse,c,1,0,1,0);


}else if (c.getPositionX()<this->getCasePion()->getPositionX() && c.getPositionY()> this->getCasePion()->getPositionY() ){
list_pion_adverse= diagonale(*this->getCasePion(),cases,1,1,0,0);
trouver_pion_adverse(list_pion_adverse,c,1,1,0,0);


}else{
if(verif){
cout<<"RAFLE INVALIDE: La rafle ne se fait qu'en diagonale"<<endl;}
return false;


}
//cout<<"liste pion adverse diagonal"<<list_diagonal.size()<<end
if(list_pion_adverse.size()>1 || list_pion_adverse.size()==0){
if(verif){
cout<<"RAFLE INVALIDE"<<endl;}
return false;


}else{return true;}

/*for(int i=0;i< list_diagonal.size();i++){
cout << list_diagonal[i].getPositionX()<<"y   "<< list_diagonal[i].getPositionY()<<endl;
}*/

}else{

return false;
}

}



//******************************************************************dame*************************************************
bool Pion::rafle_de_dame(Case& c,vector<std::vector<Case>>* cases,vector<Case>& list_pion_adverse,bool verif){
if(deplacement_valid(c,0)){

if(c.getPositionX()>this->getCasePion()->getPositionX()&& c.getPositionY()> this->getCasePion()->getPositionY()){

list_pion_adverse=diagonale(*this->getCasePion(),cases,0,1,0,1);
trouver_pion_adverse(list_pion_adverse,c,0,1,0,1);



}else if(c.getPositionX()>this->getCasePion()->getPositionX()&& c.getPositionY()< this->getCasePion()->getPositionY()){
 list_pion_adverse=diagonale(*this->getCasePion(),cases,0,0,1,1);
trouver_pion_adverse(list_pion_adverse,c,0,0,1,1);


}else if (c.getPositionX()<this->getCasePion()->getPositionX() && c.getPositionY()< this->getCasePion()->getPositionY()){
list_pion_adverse= diagonale(*this->getCasePion(),cases,1,0,1,0);
trouver_pion_adverse(list_pion_adverse,c,1,0,1,0);


}else if (c.getPositionX()<this->getCasePion()->getPositionX() && c.getPositionY()> this->getCasePion()->getPositionY() ){
list_pion_adverse= diagonale(*this->getCasePion(),cases,1,1,0,0);
trouver_pion_adverse(list_pion_adverse,c,1,1,0,0);


}else{
if(verif){
cout<<"RAFLE INVALIDE: La rafle ne se fait qu'en diagonale"<<endl;}
return false;


}

if(list_pion_adverse.size()==0){
if(verif){
cout<<"RAFLE INVALIDE: aucun pion à rafler"<<endl;}
return false;

}else{return true;}

}else{

return false;

}

}

//**************************************************************************************************************
void Pion::mise_jour_rafle_plateau(Case& c,int id_joueur,int taille_damier){
//cout<<"je suis dans mise a jouur"<<endl;
this->getCasePion()->setValEtat("XX",false);
//cout<<"je suis dans mise a jouur"<<endl;
if((c.getPositionX()==0 || c.getPositionX()==taille_damier-1) && this->getType()==TypePion::pion){

this->setType(TypePion::dame);
c.setValEtat("D"+std::to_string(id_joueur),true);
}else{
c.setValEtat("P"+ std::to_string(id_joueur),true);
}

//cout<<"je suis dans mise a jouur"<<c.getPositionX()<<"ggg"<<c.getPositionY()<<endl;
this->setCasePion(&c);

	}
//*********************************************************************************************************************

bool Pion::trouver_pion_adverse(vector<Case>& list_diagonal,Case& c,bool haut,bool droite,bool gauche,
bool bas){

//cout <<"jeface touuuut"<<c.getPositionX()<<c.getPositionY()<<endl;
for(int i=0;i<(int)list_diagonal.size();i++){

//cout <<"liste"<<list_diagonal[i].getPositionX()<<list_diagonal[i].getPositionY()<<endl;

if(list_diagonal[i].getPositionX()==c.getPositionX() && list_diagonal[i].getPositionY()==c.getPositionY())
{

list_diagonal.erase(list_diagonal.begin()+i);

if(haut){
for(int i=0;i<(int)list_diagonal.size();i++){
if(list_diagonal[i].getPositionX()<c.getPositionX()){
list_diagonal.erase(list_diagonal.begin()+i);
i--;

}
}
}else if(bas){

for(int i=0;i<(int)list_diagonal.size();i++){
//cout<<"element"<<list_diagonal[i].getPositionX()<<"yyy"<<list_diagonal[i].getPositionY()<<endl;
if(list_diagonal[i].getPositionX()>c.getPositionX()){
list_diagonal.erase(list_diagonal.begin()+i);
i--;
//cout<<"jeface le bntaaaa"<<list_diagonal.size()<<endl;
}
}



}



//cout<<"www"<<list_diagonal.size()<<endl;

return true;

}

}

cout<<"La case de destination ne fait pas partie de la diagonale de votre pion"<<endl;
return false;



}



//µµµµµµµµµµµµµµµµµµ***************************************************************************************************

std::vector<Case> Pion::diagonale(Case c,std::vector<std::vector<Case>>* cases, bool haut,bool droite,bool gauche,
bool bas){
	int px(c.getPositionX());
	int py(c.getPositionY());
	int i (px);
	int j(py);
	std::vector<Case> v(20);
	int k(0);

	vector<vector<Case>> plateau=*cases;


	//vert le haut cote gauche
	if(haut && gauche){
	while(i>0 && j> 0){
		i =i-1;
		j=j-1;
		v.at(k) = plateau[i][j];
		k++;
		//cout <<  " je passe " << plateau.size() << endl;
	}
	}
	if(haut && droite){
int sizej = plateau.at(0).size();
	//vert le haut driote
	   i =px;
	  j= py;
	  while(i>0 && j<sizej-1){
		i =i-1;
		j=j+1;
		v.at(k) = plateau.at(i).at(j);
		k++;
	}}
	 if(bas && gauche){
	//vers le bas gauche
	int sizei = plateau.size();
	i =px;
	  j= py;
	  while(i<sizei-1 && j>0){
		i =i+1;
		j=j-1;
		v.at(k) = plateau.at(i).at(j);
		k++;
	}}
	if(bas && droite){
	//vers le bas droite
	int sizej = plateau.at(0).size();
	int sizei = plateau.size();
	i =px;
	  j= py;
	  while(i<sizei-1 && j<sizej-1){
		i =i+1;
		j=j+1;
		v.at(k) = plateau.at(i).at(j);
		k++;
	}}
	v.resize(k);
	//cout <<  " je passe la fin" << v.size() << endl;
	return v;

}