#include "Joueur.hpp"
#include <iostream>

Joueur::Joueur():id{0},nom{"Joueur1"},score{0}{}
	Joueur::Joueur(int i, std::string ns, int size):id{i}, nom{ns}, score{0}{
		pions.resize(size);
	}
	int Joueur::getId(){
		return id;
	}
	std::string Joueur::getNom(){
		return nom;
	}
	std::vector<Pion> Joueur::getPions(){
		return pions;
	}
	int Joueur::getScore(){
		return score;
	}
	void Joueur::setCasePions(int idx, Case *c){
		pions.at(idx).setCasePion(c);
	}
	void Joueur::setTypePions(int idx, TypePion tp){
		pions.at(idx).setType(tp);

	}
	void Joueur::setScore(int c){
		score = score + c;
	}
	void Joueur::affichePions()const{
		for(Pion p: pions){
			std::cout << "J" << id << " " ;
		}
		std::cout << std::endl;
	}
	void Joueur::addPions(Pion *p){
		pions.push_back(*(p));
	}

    Joueur::~Joueur(){
		pions.clear();
	}