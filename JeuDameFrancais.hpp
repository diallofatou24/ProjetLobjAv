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

	std::vector<std::vector<Case> > cases;
	//int choixPion=0;
	  //static Couleur colChoisi;


	public :
	Joueur* joueur1;
	Joueur* joueur2;

	JeuDameFrancais();
	JeuDameFrancais(Couleur, Couleur);

	static Couleur lectureCouleur();

	//fonction qui instanci un joueur
Joueur * createJoueur(int id, int nbp,Couleur colChoisi);
	//fonction de creation des cases
	void createCases(int hauteur, int largeur);
	std::vector<std::vector<Case> > getCases();

	//placement des pions au debut
	void placePion(Joueur *j, int nbligne,int position);

	void affichePlateau();
	std::vector<Case> diagonale(Case c);
void aff();


};

#endif // JEUDAMEFRANCAIS_HPP_INCLUDED
