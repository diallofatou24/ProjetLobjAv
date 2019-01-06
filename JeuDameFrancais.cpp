
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
bool JeuDameFrancais::abondon=false;
//JeuDameNationnale::colChoisi{Couleur::null}
JeuDameFrancais::JeuDameFrancais(){}
JeuDameFrancais::JeuDameFrancais(Couleur c1, Couleur c2,int nbpion):joueur1{createJoueur(1,nbpion, c1)}, joueur2{createJoueur(2,nbpion, c2)}{
if(c1==Couleur::blanc){tour=1;}else{tour=2;}
}
JeuDameFrancais::JeuDameFrancais(Joueur* j1, Joueur*j2, std::vector<std::vector < Case > > v):joueur1{j1},joueur2{j2}, cases{v}{}
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
void JeuDameFrancais::settour(int i){
 	tour = i;
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
cout << "   ";
		for(int i(0);i<cases.size();i++){

			cout<<i<<"  ";
		}
		cout <<endl;

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
					    cases.at(i).at(j).setValEtat("P"+ std::to_string(jj->getId()),true);
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
						 cases.at(i).at(j).setValEtat("P"+ std::to_string(jj->getId()),true);
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

//-*****************************************************************************************************************
void JeuDameFrancais::debut_jeu(){


cout<<"-------------Debut de partie---------"<<endl;
cout<<"----------------------"<<endl;
string coup;
cin.ignore();

while(!fin_jeu()){
affichePlateau();
cout<<"TOUR DU JOUEUR : "<<tour;
if(tour==1){
cout<<" SCORE: "<<joueur1->getScore()<<"  NOMBRE DE PIECES: "<<joueur1->getPions().size()<<" A: ABONDONNER N: PASSER VOTRE TOUR H: AIDE"<<endl;
}else{
cout<<" SCORE: "<<joueur2->getScore()<< " NOMBRE DE PIECES: "<<joueur2->getPions().size()<<" A: ABONDONNER N: PASSER VOTRE TOUR H: AIDE"<<endl;
}

cout<<"veuillez saisir un coup en utilisant la notation"<<endl;


getline(cin,coup);
//cout << coup;

if(!verif_coup(coup)){


do{

cout<<"NOTATION INCORRECTE"<<endl;

getline(cin,coup);

}while(!verif_coup(coup));




}

if (tour==1){


while(!lecture_de_coup(*joueur1,coup)){
cout<<"------------------------------------RECOMMENCER"<<endl;
cout<<"JOUEUR1 "<<" SCORE : "<<joueur1->getScore()<<" NOMBRE DE PIECES: "<<joueur1->getPions().size()<<" A: ABONDONNER N: PASSER VOTRE TOUR H: AIDE"<<endl;
getline(cin,coup);
if(!verif_coup(coup)){
do{

cout<<"NOTATION INCORRECTE"<<endl;

getline(cin,coup);

}while(!verif_coup(coup));

}
}
tour=2;



}else{
while(!lecture_de_coup(*joueur2,coup)){
cout<<"------------------------------------RECOMMENCER"<<endl;
cout<<"JOUEUR2 "<<" SCORE : "<<joueur2->getScore()<<" NOMBRE DE PIECES: "<<joueur1->getPions().size()<<" A: ABONDONNER N: PASSER VOTRE TOUR H: AIDE"<<endl;
getline(cin,coup);
if(!verif_coup(coup)){
do{

cout<<"NOTATION INCORRECTE"<<endl;

getline(cin,coup);

}while(!verif_coup(coup));

}

}


tour=1;
}

}

	}//fin de jeu

//-**************************************************************************************************************************-----------------------

bool JeuDameFrancais::lecture_de_coup(Joueur& j,string c){

vector<string> VecStr;

Case* case_depart;
vector<Pion> pion_a_detruire;
Pion* p;
int taille = cases.size();



//----------------------------------mettre le coup dans un tableau de char------------------------

int nbTabl = Split(VecStr, c, ' ');
	for(int i = 0; i < nbTabl; ++i)
	{
// testéééééééééééééééééééééééééééééééééééééé
	if(VecStr[i]=="-"){

bool t=j.deplacement(VecStr[i-1],VecStr[i+1],cases,true);
if(t){
nb_tour=0;
p=j.verif_pion(VecStr[i-1]);
int n = std::stoi(VecStr[i+1]);


p->mise_jour_rafle_plateau(cases[n/taille][n%taille],j.getId(),cases.size());
}


return t;

	}//fin du ------ tiret



else if(VecStr[i]=="*"){
//cout<<"je passe laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<VecStr[i-1]<<"jjjjj"<<VecStr[i+1]<<endl;

if(i==1){
int t= std::stoi(VecStr[0]);
//cout<<"deparrrrrt"<<t<<endl;
case_depart=&cases[t/taille][t%taille];
}
Pion pion_adverse;

if(tour==1){

if(j.rafle(VecStr[i-1],VecStr[i+1],cases,*joueur2,pion_adverse,true)){

pion_a_detruire.push_back(pion_adverse);
}else{return false;}
}else{

if(j.rafle(VecStr[i-1],VecStr[i+1],cases,*joueur1,pion_adverse,true)){
pion_a_detruire.push_back(pion_adverse);
}else{return false;}
}

//cout <<"liste des pion a detruire"<<pion_a_detruire.size()<<endl;
if(pion_a_detruire.size()==0){
p=j.verif_pion(VecStr[i-1]);

p->mise_jour_rafle_plateau(*case_depart,j.getId(),cases.size());


return false;}
//JeuDameFrancais::affichePlateau();

	}//fin du ******************* rafle

else if(VecStr[i]=="+"){

int n_pion_rafle = std::stoi(VecStr[i+1]);

if(pion_a_detruire.size()==n_pion_rafle){

for(int i=0;i<pion_a_detruire.size();i++){
//cout<<"jeai detruis"<<pion_a_detruire[i].getCasePion()->getPositionX()<<"yyyyy"<<
//pion_a_detruire[i].getCasePion()->getPositionY()<<endl;

if(tour==1){
//cout<< "je detrui le joueur 2222222"<<n_pion_rafle<<endl;
joueur2->destruction_pion(pion_a_detruire);

joueur1->setScore(pion_a_detruire.size());
nb_tour=0;
cout<<"------------------- Bien JOUER "<<"JOUEUR "<<tour<<" -------------------"<<" SCORE :"<<joueur1->getScore()<<endl;
return true;
}else{
joueur1->destruction_pion(pion_a_detruire);
joueur2->setScore(pion_a_detruire.size());
cout<<"------------------- Bien JOUER "<<"JOUEUR "<<tour<<" -------------------"<<" SCORE :"<<joueur2->getScore()<<endl;
nb_tour=0;
return true;
}



}

}else{

//cout<< "mise a jour apres +++++++++"<<case_depart->getPositionX()<<"yy"<<case_depart->getPositionY()<<endl;

cout <<"le nombre de pion à rafler est invalide"<<endl;

p=j.verif_pion(VecStr[i-1]);

p->mise_jour_rafle_plateau(*case_depart,j.getId(),cases.size());
//JeuDameFrancais::affichePlateau();
return false;

// retouur a la case de depard

}


}else if(VecStr[0]=="n"||VecStr[0]=="N"){

nb_tour++;
return true;
}else if(VecStr[0]=="A"|| VecStr[0]=="a"){
abondon=true;
return true;
}else if(VecStr[0]=="H"|| VecStr[0]=="h"){
if(tour==1){
bool t=j.liste_coup_valide(cases,*joueur2,true);


}
else if(tour==2){
j.liste_coup_valide(cases,*joueur1,true);
}
return false;
}

	}

//----------------------------------traitement du coup dans le jeu------------------------


	}


//µ************************************************************************************************************************************


//**********************************************************************************************************************

// testéééééééééééééééééééééééééééééééééééééé
bool JeuDameFrancais::verif_coup(string coup){



regex pattern_rafle { "[0-9]{2}(\\s[\\*]\\s[0-9]{2})+(\\s[\\+]\\s[0-9])" }; // on recherche le motif "abc"

regex pattern_dep { "[0-9]{2}(\\s[\\-]\\s[0-9]{2})" };
regex pattern_not_coup { "[a-z]" };
    //std::string target { "13 - 12 - 45+1"};

    if(regex_match(coup, pattern_dep)){
    return true;
    }else if(regex_match(coup, pattern_rafle)){
    return true;
    }else if(regex_match(coup,pattern_not_coup)){
      return true;
    }else{
    return false;}

//    std::cout << std::boolalpha << result << std::endl;

};

//*********************************************************************************************************************

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




bool JeuDameFrancais::fin_jeu(){

if(nb_tour>25){
cout<<"---------------------------FIN DE PARTIE-----------------EGALITE : 25 coup sans prise ni deplacement-----------"<<endl;
return true;
}else if(joueur1->getPions().size()==0){
cout<<"---------------------FIN DE PARTIE-------------LE JOUEUR :"<<joueur2->getId()<<" GAGNE!!!!!!!!!!! ---------"<<endl;
return true;
}else if(joueur2->getPions().size()==0){
cout<<"---------------------FIN DE PARTIE-------------LE JOUEUR :"<<joueur1->getId()<<" GAGNE!!!!!!!!!!! ---------"<<endl;
return true;
}else if(abondon){
if(tour==2){

cout<<"---------------------FIN DE PARTIE-------------LE JOUEUR :"<<joueur2->getId()<<" GAGNE!!!!!!!!!!! ---------"<<endl;
return true;
}else if(tour==1){
cout<<"---------------------FIN DE PARTIE-------------LE JOUEUR :"<<joueur1->getId()<<" GAGNE!!!!!!!!!!! ---------"<<endl;
return true;
}

}else if(!joueur1->liste_coup_valide(cases,*joueur2,false) && !joueur2->liste_coup_valide(cases,*joueur1,false) ){
cout<<"---------------------------FIN DE PARTIE-----------------EGALITE------ AUCUN COUP A JOUER------"<<endl;
return true;}
/*else if(!joueur1->liste_coup_valide(cases,*joueur2,false)){
cout<<"---------------------FIN DE PARTIE-------------LE JOUEUR :"<<joueur2->getId()<<" GAGNE!!!!!!!!!!! ---------"<<endl;
}
else if(!joueur2->liste_coup_valide(cases,*joueur1,false)){
cout<<"---------------------FIN DE PARTIE-------------LE JOUEUR :"<<joueur1->getId()<<" GAGNE!!!!!!!!!!! ---------"<<endl;
}*/else{return false;}


}


