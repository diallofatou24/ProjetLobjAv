#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "JeuDameFrancais.hpp"
#include "Backup.hpp"

 using namespace std;
	int main(int argc, char const *argv[])

	{ 

		Couleur c=JeuDameFrancais::lectureCouleur();
		Couleur c2= (c==Couleur::noir)?Couleur::blanc:Couleur::noir;

		JeuDameFrancais jdn(c,c2,20);
		jdn.createCases(10,10);
			//jdn.affichePlateau();
		cout << "J1" << endl;

		jdn.placePion(jdn.getjoueur1(), 4,0);
		//jdn.affichePlateau();


			//cout << "J2" << endl;

		jdn.placePion(jdn.getjoueur2(), 4,9);
		jdn.affichePlateau();
		cout<< "tape 1 pour sauvegarde 2 pour restaure: " ;
		int test;
		cin >> test;
		Backup b;
		if(test ==1){
			Backup b;
			string nfichier;
			cout << "le nom du fichier de sauvegarde: ";
			cin >> nfichier;
			b.sauvegarde(&jdn,nfichier);
		}else{
			string nfichier;
			cout << "le nom du fichier de sauvegarde: ";
			cin >> nfichier;
		 JeuDameFrancais jd=	b.restaure(nfichier);

		}


		jdn.debut_jeu();


	
		return 0;
	}






