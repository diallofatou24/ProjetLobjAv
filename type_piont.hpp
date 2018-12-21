#ifndef TYPE_PIONT_H_INCLUDED
#define TYPE_PIONT_H_INCLUDED
#include <iostream>
enum class type_piont
{
  dame, pion, Marechal, General, Colonel,Commandant,Capitaine ,Lieutenant,
	Sergent, Demineur,Eclaireur,Espion,Drapeau, mine, null

};

inline std::ostream& operator<<(std::ostream& out,type_piont pion){
	switch(pion){
		case type_piont::dame: out <<"dame" ;
		break;
		case type_piont::pion: out <<"pion";
		break;
		case type_piont::Marechal: out << "Marechal";
		break;
		case type_piont::General: out << "General";
		break;
		case type_piont::Colonel: out << "Colonel";
		break;
		case type_piont::Commandant: out << "Commandant";
		break;
		case type_piont::Capitaine: out << "Capitaine";
		break;
		case type_piont::Lieutenant: out << "Lieutenant";
		break;
		case type_piont::Sergent: out << "Sergent";
		break;
		case type_piont::Demineur: out << "Demineur";
		break;
		case type_piont::Eclaireur: out << "Eclaireur";
		break;
		case type_piont::Espion: out << "Espion";
		break;
		case type_piont::Drapeau: out << "Drapeau";
		break;
		case type_piont::mine: out << "mine";
		break;
		case type_piont::null: out << "null";
		break;

	}
	return out;
}

#endif // TYPE_PIONT_H_INCLUDED
