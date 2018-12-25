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
						
						jj->setCasePions(k,cases.at(i).at(j));
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
