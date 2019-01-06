#include <iostream>
#include <fstream>
#include <string>
#include "Joueur.hpp"
#include "Couleur.hpp"
#include "TypePion.hpp"
#include "Backup.hpp"
 
 using namespace std;
  Backup::Backup(){}
void Backup::sauvegarde(JeuDameFrancais *jdn,string  nomfichier){
 ofstream fichier(nomfichier.c_str(), ios::out | ios::trunc);

  if(fichier){
   fichier << "#format de l'ecriture du joueur:\n#Ligne1:id nom score \n#pour chaque pion: on a une ligne:\n#valeur de pion la case:positionX positionY couleur etat(qui est 1 ou 0) valeur couleurPion typePion9" << endl;
   
   fichier << 9999 <<" joueur1" << endl;

      //ecrire le joueur1
   Joueur  j = *jdn->getjoueur1();
   fichier << j.getId() <<" " << j.getNom() << " " << j.getScore() << endl;
   vector<Pion> v = j.getPions();
   //pion du joueur1
   if(!v.empty()){
   for(Pion p:v){
   fichier << p.getValeur() << " "  << p.getCasePion()->getPositionX() << " " << p.getCasePion()->getPositionY() << " " << p.getCasePion()->getCouleur() << " " <<boolalpha << p.getCasePion()->getEtat() << " " << p.getCasePion()->getValeur() << " " << p.getColor() << " " << p.getType() << endl;
        }
      }else{
       fichier << 0000 << "videPJ1" << endl;
      }
      //debut joueur 2
        fichier << 9999 <<" joueur2" << endl;
        j = *jdn->getjoueur2();
        fichier << j.getId() <<" " << j.getNom() << " " << j.getScore() << endl;
   v = j.getPions();
   //pion du joueur2
   if(!v.empty()){
   for(Pion p:v){
   fichier << p.getValeur() << " "  << p.getCasePion()->getPositionX() << " " << p.getCasePion()->getPositionY() << " " << p.getCasePion()->getCouleur() << " " << p.getCasePion()->getEtat() << " " << p.getCasePion()->getValeur() << " " << p.getColor() << " " << p.getType() << endl;
        }
    }else{
     fichier << 0000 << "videPJ2" << endl;
    }
    //-----------le plateau--------------------
        fichier << 9999 <<" cases" << endl;
        string finligne ;
        vector<vector<Case> > cases = jdn->getCases();
        int t1((int)cases.size()), t2((int)cases.at(0).size());
        for(int i(0);i<t1;i++){
         for (int j(0);j<t2; j++)
         {finligne=(j==t2-1)?" ;":" ; ";
          fichier << cases.at(i).at(j).getPositionX() << " " << cases.at(i).at(j).getPositionY() << " " << cases.at(i).at(j).getCouleur() << " " << cases.at(i).at(j).getEtat() << " " << cases.at(i).at(j).getValeur() << finligne;
        }
        fichier << endl;

        }
        //------------------les tours-------------
        fichier << 9999 << "tourEtNBtour" << endl;
        fichier << jdn->gettour() << " " << jdn->getnbtour();
   fichier.close();

  }else{
   cerr << "ouverture de fichier impossible" << endl;
  }

}

 ///------------------------------------------lecture -----------------------------//




 Joueur * Backup::lectureJoueur(ifstream & lire, int nbPion, int & nombre){
   int id, score,px,py ;
   string nom, chaine2, vcase, ccCase, ccPion ,ttPion, eeCase;
  Couleur cCase, cPion; 
     TypePion typeP;
       bool etatCase;
      lire >> id >> nom >> score;
                  //cout << id << nom << score << endl;
                  Joueur *j= new Joueur(id,nom,nbPion);
                  j->setScore(score);
 //-------------------lecture des pions de J1---------------
                  lire >> nombre; // lecture de la valeur de pion
                  if(nombre ==0000){
                   //lire >> chaine2;
                   return j;
                  }
                  int taille = 0;
                     do{
                  //lecture de positionx, positiony etat case, valeur de case, couleur de pion et type de pion
                  lire >> px >> py >> ccCase >> eeCase >> vcase >> ccPion >> ttPion;
                  //cout << nombre << " " << px << "  " << py << " " << ccCase << " " << eeCase<< " "<< vcase << " " << ccPion <<" " << ttPion<< endl;;
                  cCase =(ccCase =="blanc")?Couleur::blanc: Couleur::noir;
                  etatCase =(eeCase=="true")?true:false;
                  cPion =(ccPion =="blanc")?Couleur::blanc:Couleur::noir;
                  typeP =(ttPion =="dame")?TypePion::dame:TypePion::pion;

                  Case* cc = new Case(px,py,cCase,etatCase,vcase);
                 
                  Pion p(nombre,cc,cPion,typeP);
                  j->addPion(p,taille);
                  //nombre = vpion;
                  lire >> nombre;
                  taille ++;

                 }while(nombre!=9999);
            // }
                 j->resizePions(taille);

                return j;


 }

std::vector<std::vector<Case > > Backup::lectureCase(ifstream& lire, int h, int l, int& nombre ){
  int py ;
  string  vcase, ccCase, eeCase,pointVirgule;
  Couleur cCase;
  bool etatCase;
  std::vector<vector<Case > > v(h);
                     for(int i(0);i<h;i++){
                      v.at(i) = vector<Case>(l);
                     }
                    int i(0);
                    int k(0);

                     lire>>nombre; // nombre = px
                     //cout << "debut\n";
                    do{
                      lire >>  py >> ccCase >> eeCase >> vcase >> pointVirgule;
                      //cout <<"debut " << nombre << " " << py << " " << ccCase << " " << eeCase<< " "<< vcase << pointVirgule<<endl ;
                      //lire >> nombre >> py >> ccCase >> eeCase >> vcase >> pointVirgule;
                      //cout <<"debut " << nombre << " " << py << " " << ccCase << " " << eeCase<< " "<< vcase << pointVirgule<< endl;
                        cCase =(ccCase =="blanc")?Couleur::blanc: Couleur::noir;
                      etatCase =(eeCase=="true")?true:false;
                      Case cs (nombre,py,cCase,etatCase,vcase);
                      //cs.aff();
                      v.at(i).at(k)=cs;
                      //v.at(i).at(k).aff();
                      k++;
                      lire>>nombre;
                      //v.at(i).at(k).aff();
                      //cout << "|";

                      
                    if(k==l){
                     //cout << endl;
                       i++;
                       k=0;
                       
                    }
                    if(i==h)
                     break;
                    

                    }while(nombre!=9999);
                       //
 return v;

}


 JeuDameFrancais Backup::restaure(std::string nomfichier){
  ifstream lire(nomfichier.c_str(),ios::in);
  if(lire){
   int nombre;
   string chaine2;
   lire.clear();
   lire.ignore(numeric_limits<int>::max(), '9');
   lire >> nombre >> chaine2;
   //cout << nombre << " " << chaine2 << endl;
   Joueur * j1 = lectureJoueur(lire,20,nombre);
   //j1->aff();
   if(nombre ==0000){
    lire >> chaine2;
    lire >> nombre >> chaine2;

   }else{
    lire >> chaine2;
   }
   Joueur *j2 = lectureJoueur(lire,20,nombre);
   //j2->aff();
   if(nombre ==0000){
    lire >> chaine2;
    lire >> nombre >> chaine2;

   }else{
    lire >> chaine2;
   }
   std::vector<vector<Case > > v= lectureCase(lire,10,10, nombre);
   lire >> chaine2;
  int tour , nbTour;
   lire >> tour >> nbTour ;
  lire.close();

 JeuDameFrancais jd(j1,j2,v);
 jd.settour(tour);
 jd.setnbtour(nbTour);

  jd.affichePlateau();

   return jd;

 }

  else{cerr << "Impossible d'ouvrir le fichier !" << endl;
  JeuDameFrancais jdn;

  return jdn;
 }

    

  }

