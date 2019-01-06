#ifndef BACKUP_HPP
#define BACKUP_HPP
#include <iostream>
#include <fstream>
#include <string>
#include "Case.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "JeuDameFrancais.hpp"
#include "Backup.hpp"
#include <vector>
#include <limits>
 using namespace std;
class Backup{
	private:
	
	public :
	Backup();
	void sauvegarde(JeuDameFrancais *jdn,std::string  nomfichier);
	Joueur* lectureJoueur(ifstream& lire, int nbPion, int& nombre);
	std::vector<std::vector<Case > > lectureCase(ifstream& lire, int h, int l, int& nombre );
	JeuDameFrancais restaure(std::string nomfichier);
};
#endif