#ifndef COULEUR_HPP
#define COULEUR_HPP
#include <iostream>
enum class Couleur
{
	blanc, noir, null, rouge, bleu
	
};

inline std::ostream& operator<<(std::ostream& out,Couleur couleur){
	switch(couleur){
		case Couleur::blanc: out <<"blanc" ;
		break;
		case Couleur::noir: out <<"noir";
		break;
		case Couleur::null: out << "null";
		break;
		case Couleur::rouge: out << "rouge";
		break;
		case Couleur::bleu: out << "bleu";
		break;

	}
	return out;
}
#endif