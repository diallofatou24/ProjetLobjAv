#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"

using namespace std;

class JeuDameNationnale{
	private :

	std::vector<std::vector<Case> > cases;
	//int choixPion=0;
	  //static Couleur colChoisi;


	public :
	Joueur* joueur1;
	Joueur* joueur2;

	JeuDameNationnale();
	JeuDameNationnale(Couleur, Couleur);

	//fonction qui instanci un joueur
Joueur * createJoueur(int id, int nbp,Couleur colChoisi);
	//fonction de creation des cases
	void createCases(int hauteur, int largeur);

	//placement des pions au debut
	void placePion(Joueur *j, int nbligne,int position);

	void affichePlateau();



};


//JeuDameNationnale::colChoisi{Couleur::null}
JeuDameNationnale::JeuDameNationnale(){}
JeuDameNationnale::JeuDameNationnale(Couleur c1, Couleur c2):joueur1{createJoueur(1,20, c1)}, joueur2{createJoueur(2,20, c2)}{}
Joueur* JeuDameNationnale::createJoueur(int id, int nbPions, Couleur colChoisi){
	string n;
	cout << "creation du joueur: " << to_string(id) << endl;
	cout << "Votre nom: " ;
	cin >> n;
	Joueur *j = new Joueur(id, n, nbPions);

		j->addPions(colChoisi,TypePion::pion);
		return j;
	}



	Couleur lectureCouleur(){
		int couleur;
		Couleur c;
		cout <<"choix de la couleur de pion pour joueur1:" << endl;
		do{
		cout << "Tapez 1 pour le blanc et 2 pour le noir: ";
		cin >> couleur;

	}while(couleur !=1 && couleur !=2);
		if(couleur ==1){
				c=Couleur::blanc;

		}else {
			c= Couleur::noir;

		}
		return c;
	}

	void JeuDameNationnale::affichePlateau(){}

	void JeuDameNationnale::placePion(Joueur *jj, int nbligne,int position){
		int k(0);
		if(position==0){
			for(int i(0);i< (int)cases.size();i++){
				for(int j(0); j<(int)cases[i].size();j++){
					if(cases[i][j].getCouleur()==Couleur::noir){
						jj->setCasePions(k,cases[i][j]);
						k++;
					}
				}

			}
		}else{
			for(int i(position);i>position-4;i--){
				for(int j(0); j<(int)cases[i].size();j++){
					if(cases[i][j].getCouleur()==Couleur::noir){
						jj->setCasePions(k,cases[i][j]);
						k++;
					}
				}

			}

		}
	}
	void JeuDameNationnale::createCases(int hauteur, int largeur){}

	int main(int argc, char const *argv[])

	{ //int *colChoisi=0;
		Couleur c=lectureCouleur();
		Couleur c2= (c==Couleur::noir)?Couleur::blanc:Couleur::noir;

		JeuDameNationnale jdn(c,c2);
		/*Joueur * j2=jdn.createJoueur(2,20,1, Couleur::blanc);

	 j2->affichePions();

		Couleur c(Couleur::noir);
		 Joueur *j =jdn.createJoueur(1,20,0, c);
		 //string s =(c==Couleur::=noir)?"noir":"autre";
		 //cout << " ddd " << s << endl;
		j->affichePions();

		*/
		jdn.joueur2->affichePions();
		jdn.joueur1->affichePions();

		return 0;
	}







