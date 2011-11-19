/* Programmation ortientee objet : BE2 */
/* Jeremie Fourmann et Maxime Morin    */
/* circuits.cpp                        */
/* Definition des classes circuits     */

#include <iostream>
#include <math.h>
#include "circuits.h"

using namespace std;

euler::euler(){
	a=0.0;
	b=0.0;
	ci=0.0;
	pas=0.1;
	duree=10.0;
	u=0.0;
	up=0.0;
	t=0.0;
}

void euler::diffSolve(){
		up=u;
		u=(pas/a)*(generateur->Esm(t)+up*(-b+a/pas));
		t=t+pas;
}

exemple1::exemple1(){   //Cas special de l'exercice 1
	a=1;
	b=3;
	generateur = new fctExo1;	
}

/* Choix de la source lors de la creation d'un circuit. */
circuit::circuit(){
	int choix=0;
	
		cout << "#Choisir la source ?" << endl;
		cout << "#1 - Echelon" << endl;
		cout << "#2 - Porte" << endl;
		cout << "#3 - Carre" << endl;
		cout << "#4 - Triangle" << endl;
		cin >> choix;

		switch(choix){
		case 1:
			generateur=new echelon; 
			break;
		case 2:
			generateur=new porte;
			break;
		case 3:
			generateur=new carre;
			break;	
		case 4:
			generateur=new triangle;
		    break;		
		default:
			break;	
		}
}

/* Circuit A avec comme paramètres R et C */
circuitA::circuitA(){
	cout << "#Choix des valeurs pour le circuit suivant :" << endl ;
	cout << "#_____/\\/\\/\\____  " << endl ;
	cout << "#|      R      _|_" << endl ;
	cout << "#E           C ---" << endl ;
	cout << "#|______________|" << endl ;
	
	cout << "#Valeur de R (Ohm) : " << endl;
	cin >> R ;
	cout << "#Valeur de C (Farad) : " << endl ;
	cin >> C ;
	
	a=R*C;
	b=1;
	generateur->setAB(1,0); // Esm(t) = E(t) 
}

/* Resolution de l'equation differentielle du circuitA pour la source choisie. */
void circuitA::circuitSolve(){

	cout << "#Temps" << "   " << "Ve" <<"   " << "Vs" << "   " << endl;
	while(t<=	duree){
		diffSolve();
		cout << t << "   " << generateur->E(t) <<"   " << u << endl;
	}	
}


/* Circuit B avec comme paramètres Rd, R et C. */
circuitB::circuitB(){
	cout << "#Choix des valeurs pour le circuit suivant :" << endl ;
	cout << "#_____/\\/\\/\\____|\\______________  " << endl ;
	cout << "#|      Rd      |/       |     |" << endl ;
	cout << "#|                 D     /    _|_" << endl ;
	cout << "#E                     R \\    --- C " << endl ;
	cout << "#|                       /     |" << endl ;
	cout << "#|_______________________|_____|" << endl ;
	
	cout << "#Valeur de Rd (Ohm) : " << endl;
	cin >> Rd ;
	cout << "#Valeur de R (Ohm) : " << endl;
	cin >> R ;
	cout << "#Valeur de C (Farad) : " << endl ;
	cin >> C ;		
}

/*Resolution des equations differentielles circuitB pour la source
choisie, pour les deux differents etats de la diode */
void circuitB::circuitSolve(){
	bool bloquee=1; //Flag d'etat de la diode
	double vd=.7;   // A t=0, C dechargee donc D passante (vd>0.6)	 
	ci=0;			// C dechargee
	
	cout << "#Temps" << "   " << "Ve" <<"   " << "Vs" << "   " << "Vd" << endl;
	while(t<=duree){
		if(vd>=.6 && bloquee ){ 
			a=Rd*C;		
			b=1+Rd/R;
			generateur->setAB(1,-0.6); // Offset pour le second membre
			ci=u;
			cout << "#Diode passante"<<endl;
			bloquee=0;
		}
		if(vd<.6 && !bloquee )
		{
			a=R*C;
			b=1;
			generateur->setAB(0,0); // Second membre nul, decharge de C dans R
			ci=u;
			cout << "#Diode bloquee"<<endl;
			bloquee=1;
		}
		diffSolve();
		vd=generateur->E(t)-u-Rd*C*(u-up)/pas+u/R;
		cout << t << "   " << generateur->E(t) <<"   " << u << "   " << vd << endl;
	}	
}
