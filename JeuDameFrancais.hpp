#ifndef JEUDAMEFRANCAIS_HPP_INCLUDED
#define JEUDAMEFRANCAIS_HPP_INCLUDED

#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
class JeuDameFrancais{
	private :
static int tour;
static int nb_tour;
	std::vector<std::vector<Case> > cases;

	Joueur* joueur1;
	Joueur* joueur2;
	//int choixPion=0;
	  //static Couleur colChoisi;


	public :


	JeuDameFrancais();
	JeuDameFrancais(Couleur, Couleur);
    JeuDameFrancais(Joueur* j1, Joueur*j2, std::vector<std::vector < Case > > v);

    Joueur* getjoueur1();
    Joueur* getjoueur2();
    std::vector<std::vector<Case> > getCases();

    static int gettour();
    static void setnbtour(int i);
      static int getnbtour();
       static void settour(int i);

	static Couleur lectureCouleur();

	//fonction qui instanci un joueur
Joueur * createJoueur(int id, int nbp,Couleur colChoisi);
	//fonction de creation des cases
	void createCases(int hauteur, int largeur);

	//placement des pions au debut
	void placePion(Joueur *j, int nbligne,int position);

	void affichePlateau();

	void debut_jeu();


Pion* verif_pion_rafle(Joueur* j,std::vector<Case>& v);
void mise_jour_rafle_plateau(Pion* p,Case& c);

bool lecture_de_coup(Joueur* j,std::string t);



bool verif_coup(std::string coup);

int Split(std::vector<std::string>& vecteur, std::string chaine, char separateur);



};

#endif // JEUDAMEFRANCAIS_HPP_INCLUDED
