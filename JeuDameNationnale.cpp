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
	Joueur *joueur1;
	Joueur *joueur2;
	std::vector<std::vector<Case> > cases;
	int choixPion;


	public :
	JeuDameNationnale();
	//fonction qui instanci un joueur
	static Joueur * createJoueur(int id, int nbp);
	//fonction de creation des cases
	void createCases(int hauteur, int largeur);

	//placement des pions au debut
	void placePion(Joueur j);

	void affichePlateau();



};
JeuDameNationnale::JeuDameNationnale(){}
Joueur* JeuDameNationnale::createJoueur(int id, int nbPions){
	string n;
	cout << "Votre nom: " ;
	cin >> n;
	Couleur c;
	Joueur *j = new Joueur(id, n, nbPions);
	int couleur;
	

		cout <<"choix de la couleur de pion:" << endl;
		do{
		cout << "Tapez 1 pour le blanc et 2 pour le noir: ";
		cin >> couleur;

	}while(couleur !=1 && couleur !=2);
		if(couleur ==1){
			c= Couleur::blanc;
		}else if(couleur ==2){
			c= Couleur::noir;
			cout << "je suis nor " << endl;
		}
		j->addPions(c,TypePion::pion);
		return j;

	}
	void JeuDameNationnale::affichePlateau(){}
	void JeuDameNationnale::placePion(Joueur j){}
	void JeuDameNationnale::createCases(int hauteur, int largeur){}

	int main(int argc, char const *argv[])
	{
		
		Joueur * j = JeuDameNationnale::createJoueur(1,20);
		j->affichePions();
		return 0;
	}

	


 


