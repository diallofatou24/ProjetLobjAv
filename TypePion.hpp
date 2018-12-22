#ifndef TYPEPION_HPP
#define TYPEPION_HPP
#include <iostream>
enum class TypePion
{
  dame, pion, Marechal, General, Colonel,Commandant,Capitaine ,Lieutenant,
	Sergent, Demineur,Eclaireur,Espion,Drapeau, mine, null

};

inline std::ostream& operator<<(std::ostream& out,TypePion pion){
	switch(pion){
		case TypePion::dame: out <<"dame" ;
		break;
		case TypePion::pion: out <<"pion";
		break;
		case TypePion::Marechal: out << "Marechal";
		break;
		case TypePion::General: out << "General";
		break;
		case TypePion::Colonel: out << "Colonel";
		break;
		case TypePion::Commandant: out << "Commandant";
		break;
		case TypePion::Capitaine: out << "Capitaine";
		break;
		case TypePion::Lieutenant: out << "Lieutenant";
		break;
		case TypePion::Sergent: out << "Sergent";
		break;
		case TypePion::Demineur: out << "Demineur";
		break;
		case TypePion::Eclaireur: out << "Eclaireur";
		break;
		case TypePion::Espion: out << "Espion";
		break;
		case TypePion::Drapeau: out << "Drapeau";
		break;
		case TypePion::mine: out << "mine";
		break;
		case TypePion::null: out << "null";
		break;

	}
	return out;
}

#endif // TYPEPION_HPP
