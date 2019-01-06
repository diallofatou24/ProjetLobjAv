#include <iostream>
#include "Joueur.hpp"
#include "JeuDameFrancais.hpp"

using namespace std;


Joueur::Joueur():id{0},nom{"Joueur1"},score{0}{}
	Joueur::Joueur(int i, std::string ns, int size):id{i}, nom{ns}, score{0}{
		pions.resize(size);
	}
	int Joueur::getId(){
		return id;
	}
	std::string Joueur::getNom(){
		return nom;
	}
	std::vector<Pion> Joueur::getPions(){
		return pions;
	}
	int Joueur::getScore(){
		return score;
	}
	void Joueur::setCasePions(int idx, Case& c){
		pions.at(idx).setCasePion(&c);
	}
	void Joueur::setTypePions(int idx, TypePion tp){
		pions.at(idx).setType(tp);

	}
	void Joueur::setScore(int c){
		score = score + c;
	}
	void Joueur::affichePions()const{
		int taille = (int) pions.size();
		for(int i(0); i<taille;i++){
		std::cout << "J" << id << " " ;

		}
		//std::cout << std::endl;
	}
	void Joueur::addPions(Couleur c, TypePion tp){
		int taille = (int) pions.size();
		for (int i(0);i < taille;i++){
			Pion p(1,nullptr,c,tp);
			pions.at(i) =p;
		}
		//std::cout << pions.at(0).getColor();
		}

//--------------fonctions a ajouter pour regle git
		void Joueur::addPion(Pion p,int i){
	pions.at(i) = p;
}
void Joueur::resizePions(int size){
	pions.resize(size);
}

    void Joueur::aff()const{
    	cout << "id: "<< id << " nom: " << nom <<" score: " << score << endl;
    	int taille = (int) pions.size();
		for (int i(0);i < taille;i++){
			
			pions.at(i).aff();
		}
    }

//--------------------------------------------------------------rafle

    vector<Case> Joueur::rafle(Pion* p,Case& c,vector<std::vector<Case>>* cases){
    vector<Case> vide;
    //vector<Case> &list_pion_adverse=NULL;


    if(p!=0){


if(c.getEtat()==0 && c.getCouleur()==Couleur::noir){
//test des pion et damee selon le type
if(p->getType()==TypePion::pion){
cout<<"transmission"<<endl;

vector<Case> list_pion_adverse=rafle_de_pion(p,c,cases);



cout<<"liste methode refle"<<list_pion_adverse.size()<<endl;


return list_pion_adverse;

}





//finn test

}else{
cout<<"la case de destination est invalide"<<endl;



}

}else{

cout<<"vous ne pouvez pas bouger ce pion"<<endl;

//return false;

}

return vide;

		}



vector<Case> Joueur::rafle_de_pion(Pion* p,Case& c,vector<std::vector<Case>>* cases){
vector<Case> list_diagonal;


if(c.getPositionX()>p->getCasePion()->getPositionX()&& c.getPositionY()> p->getCasePion()->getPositionY()){

list_diagonal=diagonale(*p->getCasePion(),cases,0,1,0,1);
trouver_pion_adverse(list_diagonal,c,0,1,0,1);


}else if(c.getPositionX()>p->getCasePion()->getPositionX()&& c.getPositionY()< p->getCasePion()->getPositionY()){
 list_diagonal=diagonale(*p->getCasePion(),cases,0,0,1,1);
trouver_pion_adverse(list_diagonal,c,0,0,1,1);

}else if (c.getPositionX()<p->getCasePion()->getPositionX() && c.getPositionY()< p->getCasePion()->getPositionY()){
list_diagonal= diagonale(*p->getCasePion(),cases,1,0,1,0);
trouver_pion_adverse(list_diagonal,c,1,0,1,0);

}else{
list_diagonal= diagonale(*p->getCasePion(),cases,1,1,0,0);
trouver_pion_adverse(list_diagonal,c,1,1,0,0);

}



cout<<"liste pion adverse diagonal"<<list_diagonal.size()<<endl;
return list_diagonal;


}



void Joueur::trouver_pion_adverse(vector<Case>& list_diagonal,Case& c,bool haut,bool droite,bool gauche,
bool bas){


for(int i=0;i<(int)list_diagonal.size();i++){

if(list_diagonal[i].getPositionX()==c.getPositionX() && list_diagonal[i].getPositionY()==c.getPositionY())
{

list_diagonal.erase(list_diagonal.begin()+i);

if(haut){
for(int i=0;i<(int)list_diagonal.size();i++){
if(list_diagonal[i].getPositionX()<c.getPositionX()){
list_diagonal.erase(list_diagonal.begin()+i);

}
}
}else if(bas){

for(int i=0;i<(int)list_diagonal.size();i++){
//cout<<"element"<<list_diagonal[i].getPositionX()<<"yyy"<<list_diagonal[i].getPositionY()<<endl;
if(list_diagonal[i].getPositionX()>c.getPositionX()){
list_diagonal.erase(list_diagonal.begin()+i);
i--;
//cout<<"jeface"<<list_diagonal.size()<<endl;
}
}



}



cout<<"www"<<list_diagonal.size()<<endl;

return;

}

}

cout<<"La case de destination ne fait pas partie de la diagonale de votre pion"<<endl;

for(int i=0;i<(int)list_diagonal.size();i++){

list_diagonal.erase(list_diagonal.begin()+i);
i--;

}


}


//------------------------------------------------------------------------------------------------------------------------------
bool Joueur::deplacement(Pion* p,Case& c){


if(p!=0){


if(c.getEtat()==0 && c.getCouleur()==Couleur::noir){
//test des pion et damee selon le type
if(p->getType()==TypePion::pion){

return deplacement_de_pion(p ,c,id);
}

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


bool Joueur::deplacement_de_pion(Pion* p,Case& c,int id_joueur){



if(id_joueur==1 && p->getCasePion()->getPositionX()+1==c.getPositionX()&&(p->getCasePion()->getPositionY()-1==c.getPositionY() ||
p->getCasePion()->getPositionY()+1==c.getPositionY())){

p->getCasePion()->setValEtat("XX",false);
c.setValEtat("J"+ std::to_string(id),true);
p->setCasePion(&c);
JeuDameFrancais::setnbtour(JeuDameFrancais::getnbtour()+1);

return true;



}else if(id_joueur==2 && p->getCasePion()->getPositionX()-1==c.getPositionX()&&(p->getCasePion()->getPositionY()-1==c.getPositionY() ||
p->getCasePion()->getPositionY()+1==c.getPositionY())){

p->getCasePion()->setValEtat("XX",false);
c.setValEtat("J"+ std::to_string(id),true);
p->setCasePion(&c);
JeuDameFrancais::setnbtour(JeuDameFrancais::getnbtour()+1);

return true;

}else{

cout<<"Un Deplacement se fait qu'en diagonale et d'une seule case à la fois "<<endl;

return false;
}


return false;


}



		Pion* Joueur::verif_pion(string& valeur){

		int n = std::stoi(valeur);




for(int i=0;i<(int)pions.size();i++){

if(pions[i].getCasePion()->getPositionX()==n/10 && pions[i].getCasePion()->getPositionY()==n%10){


return &pions[i];
}

}

return nullptr;


		}

    Joueur::~Joueur(){
		pions.clear();
	}




std::vector<Case> Joueur::diagonale(Case c,std::vector<std::vector<Case>>* cases, bool haut,bool droite,bool gauche,
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
		cout <<  " je passe " << plateau.size() << endl;
	}
	}
	else if(haut && droite){
int sizej = plateau.at(0).size();
	//vert le haut driote
	   i =px;
	  j= py;
	  while(i>0 && j<sizej-1){
		i =i-1;
		j=j+1;
		v.at(k) = plateau.at(i).at(j);
		k++;
	}} else if(bas && gauche){
	//vers le bas gauche
	int sizei = plateau.size();
	i =px;
	  j= py;
	  while(i<sizei-1 && j>0){
		i =i+1;
		j=j-1;
		v.at(k) = plateau.at(i).at(j);
		k++;
	}}else if(bas && droite){
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
