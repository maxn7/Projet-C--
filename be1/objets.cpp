/*BE1 : d�finition des m�thodes des classes */

#include <iostream>
#include "objets.h"
using namespace std;

/* M�thodes de la classe "mobile". */
mobile::mobile(){
	cout<<"entrez immatriculation"<<endl;
	cin>>immatriculation;
	cout<<"entrez vitesse initiale"<<endl;
	cin>> (double) vitesse;
}
mobile::mobile(int x,double y){
	immatriculation=x;
	vitesse=y;
}
void mobile::calculPosition(double temps){
	position = temps*vitesse ;
}
double mobile::getVitesse(){
	cout<<"vitesse :"<<vitesse<<endl;
	return vitesse;
}
void mobile::putVitesse(){
	cout<<"entrez nouvelle vitesse :"<<endl;
	cin	>>vitesse;
	
}

/* M�thodes de la classe "voiture" qui h�rite de "mobile". */
voiture::voiture(){
    cout<<"masse"<<endl;
	cin>> (double) masse;
	cout<<"consommation"<<endl;
	cin>> (double) consommation;
}

/* M�thodes de la classe "deuxRoues" qui h�rite de "mobile". */
deuxRoues::deuxRoues(){
    cout<<"prix"<<endl;
	cin>> (double) prix;
	cout<<"type (1-Essence 2-Electrique)"<<endl;
	cin>> type;
}


















