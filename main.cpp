#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "JeuDameFrancais.hpp"


	int main(int argc, char const *argv[])

	{ //int *colChoisi=0;
		Couleur c=JeuDameFrancais::lectureCouleur();
		Couleur c2= (c==Couleur::noir)?Couleur::blanc:Couleur::noir;

		JeuDameFrancais jdn(c,c2);
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







