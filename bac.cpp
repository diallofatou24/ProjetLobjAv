ifstream lire("text.txt",ios::in);
if(lire)

        {Joueur* j;

                int id, score, nombre,px,py ;

                string nom, chaine2, vcase, ccCase, ccPion ,ttPion, eeCase;
                Couleur cCase, cPion;
                TypePion typeP;
                bool etatCase;
                lire.clear();
                lire.ignore(numeric_limits<int>::max(), '9');
                lire >> nombre >> chaine2;
                cout << nombre << " " << chaine2 << endl;
                //if(chaine2=="joueur1"){
                	lire >> id >> nom >> score;
                	cout << id << nom << score << endl;
                	j= new Joueur(id,nom,20);
                	j->setScore(score);
//-------------------lecture des pions de J1---------------
                	lire >> nombre; // lecture de la valeur de pion
                	int taille = 0;
               do{
                	//lecture de positionx, positiony etat case, valeur de case, couleur de pion et type de pion
                	lire >> px >> py >> ccCase >> eeCase >> vcase >> ccPion >> ttPion;
                	cout << nombre << " " << px << "  " << py << " " << ccCase << " " << eeCase<< " "<< vcase << " " << ccPion <<" " << ttPion<< endl;;
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
                j->affichePions();

 //--------------lecture de J2-------
                cout << nombre;
                lire >> chaine2; //lecture joueur2


                lire >> id >> nom >> score;
                	cout << id << nom << score << endl;
                	Joueur *j2= new Joueur(id,nom,20);
                	j2->setScore(score);
//-------------------lecture des pions de J1---------------
                	lire >> nombre; // lecture de la valeur de pion
                     taille = 0;
               do{
                	//lecture de positionx, positiony etat case, valeur de case, couleur de pion et type de pion
                	lire >> px >> py >> ccCase >> eeCase >> vcase >> ccPion >> ttPion;
                	cout << nombre << " " << px << "  " << py << " " << ccCase << " " << eeCase<< " "<< vcase << " " << ccPion <<" " << ttPion<< endl;;
                	cCase =(ccCase =="blanc")?Couleur::blanc: Couleur::noir;
                	etatCase =(eeCase=="true")?true:false;
                	cPion =(ccPion =="blanc")?Couleur::blanc:Couleur::noir;
                	typeP =(ttPion =="dame")?TypePion::dame:TypePion::pion;

                	Case* cc = new Case(px,py,cCase,etatCase,vcase);
                    //cout << "type pion " << typeP ;
                	Pion p(nombre,cc,cPion,typeP);
                	cout << "type pion " << p.getType() ;
                	j2->addPion(p,taille);
                	//nombre = vpion;
                	lire >> nombre;
                	taille ++;

                }while(nombre!=9999);
                j2->resizePions(taille);
                j2->aff();
               //cout<< j2->getPions().at(0).getType();
//---------------------lecture du plateau ---------------
                cout << nombre << endl;;
                lire >> chaine2;
                std::vector<vector<Case > > v(10);
                for(int i(0);i<(int) v.size();i++){
                	v.at(i) = vector<Case>(10);
                }
               int i(0);
               int k(0);

                lire>>nombre; // nombre = px
                string pointVirgule;
                cout << "debut\n";
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
                	v.at(i).at(k).aff();
                	k++;
                	lire>>nombre;
                	//v.at(i).at(k).aff();
                	cout << "|";

                 
               if(k==10){
               	cout << endl;
               	  i++;
               	  k=0;
               	  
               }
               if(i==10)
               	break;
             	 

               }while(nombre!=9999);
                		//
                		

              

                lire.close();

                JeuDameFrancais jdn2(j,j2,v);
                jdn2.affichePlateau();
                

        }

        else

                cerr << "Impossible d'ouvrir le fichier !" << endl;

 



 	return 0;
 }


ofstream fichier("text.txt", ios::out | ios::trunc);

    if(fichier){
        fichier << "#format de l'ecriture du joueur:\n#Ligne1:id nom score \n#pour chaque pion: on a une ligne:\n#valeur de pion la case:positionX positionY couleur etat(qui est 1 ou 0) valeur couleurPion typePion9" << endl;
        fichier << 9999 <<" joueur1" << endl;
        fichier << j.getId() <<" " << j.getNom() << " " << j.getScore() << endl;
        vector<Pion> v = j.getPions();
        for(Pion p:v){
        fichier << p.getValeur() << " "  << p.getCasePion()->getPositionX() << " " << p.getCasePion()->getPositionY() << " " << p.getCasePion()->getCouleur() << " " <<boolalpha << p.getCasePion()->getEtat() << " " << p.getCasePion()->getValeur() << " " << p.getColor() << " " << p.getType() << endl;
        }
        fichier << 9999 <<" joueur2" << endl;
        j = *jdn.getjoueur2();
        fichier << j.getId() <<" " << j.getNom() << " " << j.getScore() << endl;
        v = j.getPions();
        for(Pion p:v){
        fichier << p.getValeur() << " "  << p.getCasePion()->getPositionX() << " " << p.getCasePion()->getPositionY() << " " << p.getCasePion()->getCouleur() << " " << p.getCasePion()->getEtat() << " " << p.getCasePion()->getValeur() << " " << p.getColor() << " " << p.getType() << endl;
        }
        fichier << 9999 <<" cases" << endl;
        string finligne ;
        vector<vector<Case> > cases = jdn.getCases();
        int t1((int)cases.size()), t2((int)cases.at(0).size());
        for(int i(0);i<t1;i++){
            for (int j(0);j<t2; j++)
            {finligne=(j==t2-1)?" ;":" ; ";
                fichier << cases.at(i).at(j).getPositionX() << " " << cases.at(i).at(j).getPositionY() << " " << cases.at(i).at(j).getCouleur() << " " << cases.at(i).at(j).getEtat() << " " << cases.at(i).at(j).getValeur() << finligne;
        }
        fichier << endl;
}
        fichier.close();

    }else{
        cerr << "ouverture de fichier impossible" << endl;
