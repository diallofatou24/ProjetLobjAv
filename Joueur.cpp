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
		for(int i(0); i<20;i++){
			std::cout << "J" << id << " " ;
		}
		std::cout << std::endl;
	}
	void Joueur::addPions(Couleur c, TypePion tp){
		for (int i(0);i < 20;i++){
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

		void Joueur::supprimerPion(int i){

		pions.erase(pions.begin()+i);
		}


//****************************************************************************************************

		void Joueur::restorer_pion_supprime(vector<Pion>& liste_sup,vector<vector<Case>>& cases){
//cout<<"listeeee"<<liste_sup.size()<<endl;
		for(int i=0;i<liste_sup.size();i++){
		//cout<<"pion supprimerrr de"<<this->getId()<<endl;

		this->pions.push_back(liste_sup[i]);
			//cout<<"taille"<<this->getPions().size()<<endl;

		for(int s=0;s<cases.size();s++){

			for(int j=0;j<cases[s].size();j++){
if(cases[s][j].getPositionX()==liste_sup[i].getCasePion()->getPositionX() &&
cases[s][j].getPositionY()==liste_sup[i].getCasePion()->getPositionY() ){
if(liste_sup[i].getType()==TypePion::pion){
cases[s][j].setValEtat("P"+ std::to_string(this->getId()),true);}
else if(liste_sup[i].getType()==TypePion::dame){
cases[s][j].setValEtat("D"+ std::to_string(this->getId()),true);
}

}

			}

		}


		}





		}



//*******************************************************************************************************************

bool Joueur::deplacement(std::string cdepart,std::string cdest,std::vector<std::vector<Case>>& cases,bool verif){
int taille= cases.size();

Pion* p(this->verif_pion(cdepart));

if(p==0){
if(verif){
cout<<"DEPLACEMENT INVALIDE : ce n'est pas votre pion"<<endl; }

return false;}

           int n = std::stoi(cdest);
           bool t;
           if(p->getType()==TypePion::pion){

t=p->deplacement_de_pion(cases[n/taille][n%taille],this->getId(),cases.size(),verif);


}
else if(p->getType()==TypePion::dame){

t=p->deplacement_de_dame(cases[n/taille][n%taille],&cases,this->getId(),verif);



}



return t;


}

//*********************************************************************************************************************
bool Joueur::rafle(std::string cdepart,std::string cdest,std::vector<std::vector<Case>>& cases,
Joueur& j, Pion& p_adverse,bool verif){
Pion* p;

int taille=cases.size();

p=this->verif_pion(cdepart);
if(p==0){
if(verif){
cout<<"RAFLE INVALIDE : Ce n'est pas votre pion"<<endl; }return false;}

int n = std::stoi(cdest);
vector<Case> list_pion_adverse;


Pion* t=nullptr;


if(p->getType()==TypePion::pion){

if(!p->rafle_de_pion(cases[n/taille][n%taille],&cases,list_pion_adverse,verif)){ return false;}

}else if(p->getType()==TypePion::dame){


if(!p->rafle_de_dame(cases[n/taille][n%taille],&cases,list_pion_adverse,verif)){ return false;}

}

vector<Case> list_pion_diagonal=list_pion_adverse;
Pion* pion_rafle_joueur(verif_pion_rafle(*this,list_pion_diagonal));

//verif_pion_rafle(*this,list_pion_diagonal);

t=verif_pion_rafle(j,list_pion_adverse);

if(list_pion_adverse.size()>1){
if(verif){
cout<<"RAFLE INVALIDE : vous ne pouvez pas rafler deux piece sur la meme diagonale"<<endl;}
return false;

}else if(!(list_pion_adverse.size()==0)){

if(list_pion_diagonal.size()==0){


p_adverse=*t;
//cout<<"pass"<<endl;
//cout<<"pion ajoutééé a la liste de destruction"<<pion_a_detruire.size()<<endl;

p->mise_jour_rafle_plateau(cases[n/taille][n%taille],id,cases.size());
//cout<<"pass"<<endl;

return true;

}else{
if(verif){
cout<<"RAFLE INVALIDE : une de vos piéces est sur la diagonale"<<endl;}

return false;
}


}else{

if(verif){

cout<<"RAFLE INVALIDE: il n'ya pas de pion adverse à rafler "<<endl;}

return false;
//cout<<"ladversaire possede pas"<<case_depart->getPositionX()<<"jjj"<<case_depart->getPositionY()<<endl;

}

return false;

}

//***********************************************************************************************************************




//**********************************************************************************************************************
Pion* Joueur::verif_pion_rafle(Joueur& jj,vector<Case>& v){

Pion* reponse=nullptr;

for(int j=0;j<v.size();j++){
bool d =false;

for(int i=0 ;i<jj.getPions().size();i++){

if(jj.getPions()[i].getCasePion()->getPositionX()==v[j].getPositionX() &&
jj.getPions()[i].getCasePion()->getPositionY()==v[j].getPositionY()){
//cout<<"pion"<<jj.getPions()[i].getCasePion()->getPositionX()<<"yyy"<<jj.getPions()[i].getCasePion()->getPositionY()<<endl;

d=true;
reponse=&(jj.getPions()[i]);
}  }


if (d==false){
//cout<<"tailee de"<<endl;

v.erase(v.begin()+j);
j--;
}
}

//cout<<"tailee de la diago apre teste est"<<v.size()<<endl;
return reponse;



}
//*****************************************************************************************************************

bool Joueur::liste_coup_valide(std::vector<std::vector<Case> >& cases,Joueur& j,bool verif){
bool coup_valid=false;
if(verif){
cout<<endl;
cout<<"------------------------DEPLACEMENTS et RAFLE VALIDE--------------------------------"<<endl;}
for(int i=0;i<this->getPions().size();i++){
Pion& p=this->getPions()[i];
//cout<<"pion--------------------------------"<<p.getCasePion()->getPositionX()<<"yyy"<<p.getCasePion()->getPositionY()<<endl;
vector<Case> liste_case_valide=p.diagonale(*p.getCasePion(),&cases,1,1,1,1);
//cout<<"case valide"<<liste_case_valide.size()<<endl;
case_vide(liste_case_valide);
//cout<<"case valide apreeee"<<liste_case_valide.size()<<endl;
if(aide_deplace_valide(p,liste_case_valide,cases,verif)){
coup_valid=true;
if(verif){
cout<<endl;}


}
vector<Pion> list_destruction;
if(aide_rafle_valide(p,liste_case_valide,cases,j,list_destruction,verif)){

if(verif){
cout<<"+"<<list_destruction.size();}


j.restorer_pion_supprime(list_destruction,cases);


coup_valid=true;

if(verif){
cout<<endl;}}

}
if(verif){
cout<<endl;cout<<endl;}

return coup_valid;
}

//*******************************************************************************************************************
bool Joueur::aide_rafle_valide(Pion& p,vector<Case>& v,std::vector<std::vector<Case> >& cases,Joueur& j,vector<Pion>&
liste_destruction,bool verif){

vector<Pion> list_destruction_local;

int taille= cases.size();
bool t=false;
Pion pion_adverse;
string case_depart=""+std::to_string(p.getCasePion()->getPositionX())+std::to_string(p.getCasePion()->getPositionY());
for(int i =0;i<v.size();i++){
string case_arriv=""+std::to_string(v[i].getPositionX())+std::to_string(v[i].getPositionY());

if(rafle(case_depart,case_arriv,cases,j,pion_adverse,false)){

if(verif){

cout<<case_depart<<" * "<<case_arriv<<" ";}

liste_destruction.push_back(pion_adverse);
//cout<<"destruction de pionx"<<pion_adverse.getCasePion()->getPositionX()<<endl;
//cout<<"destruction de piony"<<pion_adverse.getCasePion()->getPositionY()<<endl;
list_destruction_local.push_back(pion_adverse);



j.destruction_pion(list_destruction_local);

Pion* suivant=this->verif_pion(case_arriv);

vector<Case> liste_case_valide=suivant->diagonale(*suivant->getCasePion(),&cases,1,1,1,1);

case_vide(liste_case_valide);

aide_rafle_valide(*suivant,liste_case_valide,cases,j,liste_destruction,verif);


int t_case= std::stoi(case_depart);
//cout<<"tttttttttttttttttttttttttt"<<t<<"hhhh"<<taille<<endl;
//cout<<"tttttttttttttttttttttttttt"<<p.getCasePion()->getPositionX()<<"hhhh"<<p.getCasePion()->getPositionY()<<endl;

suivant->mise_jour_rafle_plateau(cases[t_case/taille][t_case%taille],this->getId(),taille);


t=true;

}

}

return t;
}

//********************************************************************************************************************
bool Joueur::aide_deplace_valide(Pion& p,vector<Case>& v,std::vector<std::vector<Case> >& cases ,bool verif){
bool t=false;
string case_depart=""+std::to_string(p.getCasePion()->getPositionX())+std::to_string(p.getCasePion()->getPositionY());
for(int i =0;i<v.size();i++){
string case_arriv=""+std::to_string(v[i].getPositionX())+std::to_string(v[i].getPositionY());
if(deplacement(case_depart,case_arriv,cases,false)){
if(verif){
cout<<case_depart<<" - "<<case_arriv<<" ";}
t=true;
}
}
return t;

}

void Joueur::case_vide(vector<Case>& v){
for(int i =0;i<v.size();i++){
if(v[i].getEtat()){
v.erase(v.begin()+i);
i--;

}

}

}
//**************************************************************************************************************
void Joueur::destruction_pion(vector<Pion>& liste_detruite){
int ax;
int by;
for(int i=0;i<liste_detruite.size();i++){
for(int j=0;j<this->getPions().size();j++){
ax=this->getPions()[j].getCasePion()->getPositionX();
by=this->getPions()[j].getCasePion()->getPositionY();


if(ax==liste_detruite[i].getCasePion()->getPositionX() && by==liste_detruite[i].getCasePion()->getPositionY()){
//cout<<"a"<<ax<<"b"<<by<<endl;
this->getPions()[j].getCasePion()->setValEtat("XX",false);
this->supprimerPion(j);



//cout<< "detruiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"<<joueur1->getPions().size()<<endl;

//cout<< "detruiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"<<joueur2->getPions().size()<<endl;

//cases[ax][by].setValEtat("XX",false);
}
}
}
//JeuDameFrancais::affichePlateau();
}

//µ**********************************************************************************************************************

Pion* Joueur::verif_pion(string& valeur){

int n = std::stoi(valeur);




for(int i=0;i<pions.size();i++){

if(pions[i].getCasePion()->getPositionX()==n/10 && pions[i].getCasePion()->getPositionY()==n%10){


return &pions[i];
}

}

return nullptr;


		}

    Joueur::~Joueur(){
		pions.clear();
}