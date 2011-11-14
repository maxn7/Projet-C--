#include <iostream>
#include "objets.h"
#include <math.h>

using namespace std;

euler::euler(){
	a=0.0;
	b=0.0;
	ci=0.0;
	pas=0.1;
	duree=10.0;
}

void euler::solve(){
	//int N= ((double)duree/(double)pas),i=0;
	double u=ci, up=ci;
	double t=0;

	while(t<duree)
	{
		u=(pas/a)*(generateur->E(t)+up*(-b+a/pas));
		up=u;
		cout << t << "  " <<generateur->E(t) <<"  "<<up<< endl;
		t=t+pas;
	}
}

exemple1::exemple1(){   //c'est le cas ex1 special
	a=1;
	b=3;
	generateur=new fctExo1;	
}
/* Choix de la source lors de la creation d'un circuit*/
circuit::circuit(){
	int choix=0;
	
		cout << "Choisir la source ?" << endl;
		cout << "1 - Echelon" << endl;
		cout << "2 - Porte" << endl;
		cout << "3 - Triangle" << endl;
		cout << "4 - Carré" << endl;
		cin >> choix;

		switch(choix){
		case 1:
			generateur=new echelon;
			break;
		case 2:
			generateur=new porte;
			break;
		case 3:
			cout << "todo" << endl;
			break;	
		case 4:
			cout << "todo" << endl;
		    break;		
		default:
			break;
		
		}
}
/* Circuit A avec comme param R et C */
circuitA::circuitA(){
	R=1.0;
	C=1.0;
	a=R*C;
	b=1;
}
void circuitA::reglage(double cN,double rN){
	R=rN;
	C=cN;
	a=R*C;
	b=1;
}
