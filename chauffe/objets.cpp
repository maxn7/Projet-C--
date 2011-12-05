/*BE1 : définition des méthodes des classes */

#include <iostream>
#include "objets.h"
using namespace std;

/* Méthodes de la classe "mobile". */
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
void mobile::recapitulation()
{
	cout << "Immatriculation : " << immatriculation << endl;
	cout << "Vitesse : " << vitesse << endl;
}

/* Méthodes de la classe "voiture" qui hérite de "mobile". */
voiture::voiture(){
    cout<<"masse"<<endl;
	cin>> (double) masse;
	cout<<"consommation"<<endl;
	cin>> (double) consommation;
}
void voiture::recapitulation(){
	mobile::recapitulation();
	cout<<"Masse : "<< masse << endl;
	cout<<"Consommation : "<< consommation << endl;
}

/* Méthodes de la classe "deuxRoues" qui hérite de "mobile". */
deuxRoues::deuxRoues(){
    cout<<"prix"<<endl;
	cin>> (double) prix;
	cout<<"type (1-Essence 2-Electrique)"<<endl;
	cin>> type;
}
void deuxRoues::recapitulation(){
	mobile::recapitulation();
	cout<<"Prix : "<< prix << endl;
	cout<<"Type : "<< type << endl;

}

/* Méthodes de la classe "noeud". */
noeud::noeud(mobile * mob){
	element = mob;
	suivant = NULL;
	precedent =NULL;

}
noeud* noeud::getPrecedent(){
	return precedent ;
}
noeud* noeud::getSuivant(){
	return suivant ;
}
void noeud::setSuivant(noeud* suiv){
	suivant=suiv;
}
void noeud::setPrecedent(noeud* prec){
	precedent=prec;
}
void noeud::enumerer(noeud* dernierElement){
	
	noeud* curseur = dernierElement;

	while(curseur->getPrecedent() != NULL)
	{
		curseur->element->recapitulation();
		curseur = curseur->getPrecedent();
	}
}














