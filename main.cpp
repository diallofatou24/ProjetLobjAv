#include <iostream>
#include <vector>
#include "Case.hpp"
#include "piont.hpp"

using namespace std;

int main()

{
Case c;

vector< vector<Case> > plateau(10,vector<Case>(10));
//plateau[0][0]=c(0,0,Couleur::blanc);

for(int i(0);i< 10;i++){

for(int j(0);j< 10;j++){

if((i+j)%2==0){
Case c(i,j,Couleur::blanc);
plateau[i][j]=c;


}else{
Case c(i,j,Couleur::noir);


plateau[i][j]=c;



}


}
}

for(int i(0);i<10;i++){

if(i+1==10){cout<<i+1 <<" ";}else{
cout<<i+1 <<"  ";}


for(int j(0);j<10;j++){

plateau[i][j].affiche();

}
cout<<endl;
}
cout<<"   A B C D E F G H I J";


vector<piont> liste_pion(20);

for(int i(0);i< 20;i++){
piont()
liste_pion[i]=
}

    /*cout << "Hello world!" << endl;
    vector<vector<int>> plateau;
    tab.resize(10);*/
    return 0;
}
