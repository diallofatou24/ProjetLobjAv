#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "JeuDameFrancais.hpp"
#include <bits/stdc++.h>
#include <regex>


using namespace std;
int JeuDameFrancais::tour=1;
int JeuDameFrancais::nb_tour=0;
//JeuDameNationnale::colChoisi{Couleur::null}
JeuDameFrancais::JeuDameFrancais(){}
JeuDameFrancais::JeuDameFrancais(Couleur c1, Couleur c2):joueur1{createJoueur(1,20, c1)}, joueur2{createJoueur(2,20, c2)}{
if(c1==Couleur::blanc){tour=1;}else{tour=2;}
}

Joueur* JeuDameFrancais::getjoueur1(){
return joueur1;


};
    Joueur* JeuDameFrancais::getjoueur2(){
    return joueur2;
    };



int JeuDameFrancais::gettour(){
return tour;
       };


 void JeuDameFrancais::setnbtour(int i){
 nb_tour=i;

 }

int JeuDameFrancais::getnbtour(){
return nb_tour;
     }

Joueur* JeuDameFrancais::createJoueur(int id, int nbPions, Couleur colChoisi){
	string n;
	cout << "creation du joueur: " << to_string(id) << endl;
	cout << "Votre nom: " ;
	cin >> n;
	Joueur *j = new Joueur(id, n, nbPions);

		j->addPions(colChoisi,TypePion::pion);
		return j;
	}



	Couleur JeuDameFrancais::lectureCouleur(){
		int couleur;
		Couleur c;
		cout <<"choix de la couleur de pion pour joueur1:" << endl;
		do{
		cout << "Tapez 1 pour le blanc et 2 pour le noir: ";
		cin >> couleur;
		cin.clear();
         // discard 'bad' character(s)
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}while(couleur !=1 && couleur !=2);
		if(couleur ==1){
				c=Couleur::blanc;

		}else {
			c= Couleur::noir;

		}
		return c;
	}

	void JeuDameFrancais::affichePlateau(){
		for(int i(0);i<cases.size();i++){
			cout << i << " ";
			for(int j(0);j<(int)cases[i].size();j++){
				cases.at(i).at(j).affiche();
				cout << " ";
			}
			std::cout << endl;
		}
		cout << "   0 1  2  3  4  5  6  7  8  9" << endl;
	}

	void JeuDameFrancais::placePion(Joueur *jj, int nbligne,int position){
		int k(0);
		if(position==0){
			std::cout << "cases taille " <<  cases.size() << "cases[i] taille " << cases[0].size() << endl;
			for(int i(0);i< nbligne;i++){
				for(int j(0); j< (int)cases.at(i).size();j++){
					if(cases.at(i).at(j).getCouleur()==Couleur::noir){

						jj->setCasePions(k,cases[i][j]);
					    //cases.at(i).at(j).setEtat(true);
					    cases.at(i).at(j).setValEtat("J"+ std::to_string(jj->getId()),true);
						//cases.at(i).at(j).setValeur(("J"+ std::to_string(jj->getId())));//
						k++;
					}
				}

			}
		}else{
			k= 0;

			for(int i(position);i>(position-nbligne);i--){
				for(int j(0); j<(int)cases.at(i).size();j++){
					if(cases.at(i).at(j).getCouleur()==Couleur::noir){
						jj->setCasePions(k,cases.at(i).at(j));
						 cases.at(i).at(j).setValEtat("J"+ std::to_string(jj->getId()),true);
						/*cases.at(i).at(j).setEtat(true);
						cases.at(i).at(j).setValeur(("J"+ std::to_string(jj->getId())));*/
						k++;
					}
				}

			}

		}
	}
	void JeuDameFrancais::createCases(int hauteur, int largeur){
		cases.resize(hauteur);
		for(int i(0);i< (int)cases.size();i++)
			cases[i].resize(largeur);
		for(int i(0);i<(int)cases.size();i++){
			for(int j(0);j< (int) cases[i].size() ;j++){
				if((i+j)%2 ==0){
					Case c(i,j,Couleur::blanc,"--");
					cases[i][j] = c;
				}else{
					Case c(i,j,Couleur::noir,"XX");
					cases[i][j] = c;

				}

			}
		}



	}


	void JeuDameFrancais::debut_jeu(){


	cout<<"-------------Debut de partie---------"<<endl;
cout<<"----------------------"<<endl;
string coup;
cin.ignore();

while(nb_tour<25){

cout<<"Tour du joueur "<<tour<<endl;
cout<<"veuillez saisir un coup en utilisant la notation"<<endl;


getline(cin,coup);
cout << coup;

if(!verif_coup(coup)){


do{

cout<<"veuillez saisir un coup correct"<<endl;

getline(cin,coup);

}while(!verif_coup(coup));




}

if (tour==1){


while(!lecture_de_coup(joueur1,coup)){
cout<<"veuillez resaisir un coup correct"<<endl;
getline(cin,coup);
}
tour=2;
affichePlateau();
cout<<"jjjjjjjjj"<<nb_tour<<endl;
}else{
while(!lecture_de_coup(joueur2,coup)){
cout<<"veuillez resaisir un coup correct"<<endl;
getline(cin,coup);
}

affichePlateau();
tour=1;
}

}

	}//fin de jeu


bool JeuDameFrancais::lecture_de_coup(Joueur* j,string c){

vector<string> VecStr;

Case* case_depart;
vector<Pion> pion_a_detruire;

//----------------------------------mettre le coup dans un tableau de char------------------------

int nbTabl = Split(VecStr, c, ' ');
	for(int i = 0; i < nbTabl; ++i)
	{
// testéééééééééééééééééééééééééééééééééééééé
	if(VecStr[i]=="-"){

       Pion* p(j->verif_pion(VecStr[i-1]));


           int n = std::stoi(VecStr[i+1]);

return j->deplacement(p,cases[n/10][n%10]);

	}//fin du ------ tiret



else if(VecStr[i]=="*"){

if(i==1){
int t = std::stoi(VecStr[0]);
case_depart=&cases[t/10][t%10];
}



Pion* p(j->verif_pion(VecStr[i-1]));
int n = std::stoi(VecStr[i+1]);
vector<Case> list_pion_adverse =j->rafle(p,cases[n/10][n%10],&cases);


cout<<"la liste est la"<<list_pion_adverse.size()<<endl;

Pion* p_adverse;

if(tour==1){
Pion* p_adverse=verif_pion_rafle(joueur2,list_pion_adverse);

}else{Pion* p_adverse(verif_pion_rafle(joueur1,list_pion_adverse));
}
Pion* pion_rafle_joueur(verif_pion_rafle(j,list_pion_adverse));


if(p_adverse!=0 && pion_rafle_joueur==0){
cout<<"ladversaire possede rafle bonne"<<endl;
pion_a_detruire.push_back(*p_adverse);
cout<<"pion ajoutééé a la liste de destruction"<<endl;


mise_jour_rafle_plateau(p,cases[n/10][n%10]);

}else{
mise_jour_rafle_plateau(p,*case_depart);

cout<<"ladversaire possede pas"<<endl;}




	}//fin du ******************* rafle
else if(VecStr[i]=="+"){
int n_pion_rafle = std::stoi(VecStr[i+1]);
if(pion_a_detruire.size()==n_pion_rafle){

for(int i=0;i<pion_a_detruire.size();i++){

//methode destructionnn des pions du joueur
}

}else{

// retouur a la case de depard

}


}

	}

//----------------------------------traitement du coup dans le jeu------------------------













  //std::cout <<"convertion"<< n/10 << n%10 <<std::endl;




	}


void JeuDameFrancais::mise_jour_rafle_plateau(Pion* p,Case& c){
p->getCasePion()->setValEtat("XX",false);
c.setValEtat("J"+ std::to_string(tour),true);
p->setCasePion(&c);

	}



	// testéééééééééééééééééééééééééééééééééééééé
	Pion* JeuDameFrancais::verif_pion_rafle(Joueur* jj,vector<Case>& v){


for(int i=0 ;i<jj->getPions().size();i++){

for(int j=0;j<v.size();j++){

if(jj->getPions()[i].getCasePion()->getPositionX()==v[j].getPositionX() &&
jj->getPions()[i].getCasePion()->getPositionY()==v[j].getPositionY()){

return &jj->getPions()[i];


}

}

}

return nullptr;

	}

// testéééééééééééééééééééééééééééééééééééééé
bool JeuDameFrancais::verif_coup(string coup){



regex pattern_rafle { "[0-9]{2}(\\s[\\*]\\s[0-9]{2})+(\\s[\\+][0-9])" }; // on recherche le motif "abc"

regex pattern_dep { "[0-9]{2}(\\s[\\-]\\s[0-9]{2})" };
    //std::string target { "13 - 12 - 45+1"};

    if(regex_match(coup, pattern_dep)){
    return true;
    }else if(regex_match(coup, pattern_rafle)){
    return true;
    }else{return false;}

//    std::cout << std::boolalpha << result << std::endl;

};


// testéééééééééééééééééééééééééééééééééééééé
int JeuDameFrancais::Split(vector<string>& vecteur, string chaine, char separateur)
{
	vecteur.clear();

	string::size_type stTemp = chaine.find(separateur);



	while(stTemp != string::npos)

	{

		vecteur.push_back(chaine.substr(0, stTemp));
		chaine = chaine.substr(stTemp + 1);
		stTemp = chaine.find(separateur);
	}

	vecteur.push_back(chaine);

	return vecteur.size();
}



