/* Programmation ortientee objet : BE2 */
/* Jeremie Fourmann et Maxime Morin    */
/* circuits.cpp                        */
/* Definition des classes circuits     */

#include <iostream>
#include <math.h>
#include "circuits.h"

using namespace std;

euler::euler(){
	pas=0.01;
	duree=10;
	t=0.0;
}

/* Choix de la source lors de la creation d'un circuit. */
circuit::circuit(){
	int choix=0;
	a=0.0;
	b=0.0;
	ci=0.0;
	u=0.0;
	up=0.0;
	
		cout << "#Choisir la source ?" << endl;
		cout << "#1 - Echelon" << endl;
		cout << "#2 - Porte" << endl;
		cout << "#3 - Carre" << endl;
		cout << "#4 - Triangle" << endl;
		cout << "#5 - Rampe f(t)=-3*t (Exemple1)" << endl;
		cout << "#6 - Nulle (Exemple 2)" << endl;
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
		case 5:
			generateur=new fctExo1;
		    break;	
		case 6:
			generateur=new echelon; /* Generateur quelconque. */
			generateur->setAB(0,0); /* Coupe le generateur. */
		    break;	
		default:
			break;	
		}
		
}

void circuit1::diffSolve(){
		up=u;
		u=(pas/a)*(generateur->Esm(t)+up*(-b+a/pas));
		t=t+pas;
}

exemple1::exemple1(){   //Cas "mathematique" de l'exercice 1
	a=1;
	b=3;
	ci = 0;	
}

void exemple1::circuitSolve(){
		cout << "#Temps" << "   " << "SolEuler" <<"   " << "SolExacte" << "   " << endl;
	while(t<=	duree){
		diffSolve();
		cout << t << "   " << u <<"   " << -(1/3)*exp(-3*t) -t + (1/3) << endl;
	}	
}


/* Circuit A avec comme parametres R et C */
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

/*Ciruit 2 ordre*/

circuit2::circuit2(){
	u2=0.0;
	u2p=0.0;
	ci2=0;
	
}

void circuit2::circuitSolve(){
		cout << "#Temps" << "   " << "ESM" <<"   " << "Vs" << "   " << endl;
		u=ci;
		u2=ci2;
		while(t<=duree){
			diffSolve();
			cout << t << "   " << generateur->Esm(t) <<"   " << u << endl;
		}	
}

/*Resolution de l'exemple numero 2 */
exemple2::exemple2(){   //Cas mathematique de l'exercice 2
	a=0.0;
	b=-1.0;
	ci2=1;
}

void exemple2::diffSolve(){
		up=u;
		u2p=u2;
		u=up+pas*u2p;
		u2=u2p+pas*(b*up+a*u2p+generateur->Esm(t));
		t=t+pas;
}

void exemple2::circuitSolve(){
		cout << "#Temps" << "   " << "Entree" <<"   " << "Sortie-Solution" <<"   " << "Sinus(sol exact)" << "   " << endl;
		u=ci;
		u2=ci2;
		while(t<=duree){
			diffSolve();
			cout << t << "   " << generateur->Esm(t) <<"   " << u << "   " <<  sin(t) << endl;
		}	
}

/*Constructeur du circuitC*/
circuitC::circuitC(){   //Cas special de l'exercice 2
	cout << "#Valeur de R (Ohm) : " << endl;
	cin >> R ;
	cout << "#Valeur de L (Henry) : " << endl;
	cin >> L ;
	cout << "#Valeur de C (Farad) : " << endl ;
	cin >> C ;		
	
	a=-R/L;
	b=-1/(L*C);
	ci=0.0;
	ci2=0.0;
	
	generateur->setAB(1,0); 
}

circuitD::circuitD(){  
	cout << "#Valeur de R (Ohm) : " << endl;
	cin >> R ;
	cout << "#Valeur de L (Henry) : " << endl;
	cin >> L ;
	cout << "#Valeur de C (Farad) : " << endl ;
	cin >> C ;		
	
	a=-1/(R*C);
	b=-1/(L*C);
	ci=0.0;
	ci2=0.0;
	
	generateur->setAB(-a,0); 
}

void circuitD::diffSolve(){
		up=u;
		u2p=u2;
		u=up+pas*u2p;
		u2=u2p+pas*(b*up+a*u2p)+(generateur->Esm(t)-generateur->Esm(t-pas)); //on code la derivé de la fct second membre
		t=t+pas;
}
