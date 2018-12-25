#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "JeuDameFrancais.hpp"

 using namespace std;


	int main(int argc, char const *argv[])

	{ //int *colChoisi=0;
		Couleur c=JeuDameFrancais::lectureCouleur();
		Couleur c2= (c==Couleur::noir)?Couleur::blanc:Couleur::noir;

		JeuDameFrancais jdn(c,c2);
		jdn.createCases(10,10);
			jdn.affichePlateau();
	cout << "tes" << endl << endl;;
			jdn.aff();
		cout << "J1" << endl;

		jdn.placePion(jdn.joueur1, 4,0);
		jdn.affichePlateau();


			cout << "J2" << endl;

		jdn.placePion(jdn.joueur2, 4,9);
		jdn.affichePlateau();
		std::vector<Case> v = jdn.diagonale(jdn.getCases().at(6).at(5));
		for(int i(0);i< (int)v.size();i++){
			cout << " cases " << to_string(i) << "X =" << to_string( v.at(i).getPositionX() )<< " Y=" << to_string(v.at(i).getPositionY())  << endl;
		}

		return 0;
	}







