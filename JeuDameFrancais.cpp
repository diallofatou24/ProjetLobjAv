#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "JeuDameFrancais.hpp"

using namespace std;

//JeuDameNationnale::colChoisi{Couleur::null}
JeuDameFrancais::JeuDameFrancais(){}
JeuDameFrancais::JeuDameFrancais(Couleur c1, Couleur c2):joueur1{createJoueur(1,20, c1)}, joueur2{createJoueur(2,20, c2)}{}
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

	}while(couleur !=1 && couleur !=2);
		if(couleur ==1){
				c=Couleur::blanc;

		}else {
			c= Couleur::noir;

		}
		return c;
	}

	void JeuDameFrancais::affichePlateau(){}

	void JeuDameFrancais::placePion(Joueur *jj, int nbligne,int position){
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
	void JeuDameFrancais::createCases(int hauteur, int largeur){}
