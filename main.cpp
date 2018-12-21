#include "Couleur.hpp"
#include "Case.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	Case  c(0,1,Couleur::noir);
	c.affiche();
	return 0;
}