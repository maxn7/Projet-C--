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
	u=0.0;
	up=0.0;
	t=0.0;
}

void euler::solve(){
	//int N= ((double)duree/(double)pas),i=0;
		up=u;
		u=(pas/a)*(generateur->E(t)+up*(-b+a/pas));
		cout << t << "  " <<generateur->E(t) <<"  "<<up<< endl;
		t=t+pas;
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
		cout << "3 - Carré" << endl;
		cout << "4 - Triangle" << endl;
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
/* Circuit A avec comme param R et C */
circuitA::circuitA(){
	cout << "Choix des valeurs pour le circuit suivant :" << endl ;
	cout << "_____/\\/\\/\\____  " << endl ;
	cout << "|      R      _|_" << endl ;
	cout << "E           C ---" << endl ;
	cout << "|______________|" << endl ;
	
	cout << "Valeur de R (Ohm) : " << endl;
	cin >> R ;
	cout << "Valeur de C (Farad) : " << endl ;
	cin >> C ;
	
	a=R*C;
	b=1;
}
void circuitA::reglage(double cN,double rN){
	R=rN;
	C=cN;
	a=R*C;
	b=1;
}

circuitB::circuitB(){
	Rd=1.0;
	R=1.0;
	C=1.0;
	
}

void circuitB::solveB(){
	
	 ci=0;
	 int bloquee=1;
	double vd=.7;
	//vd=ve-vrd-vs avec vrd=rd*ic=rd*C*(u-up)/h+u/R
	while(t<duree){
		if(vd>=.6 && bloquee ){ //equa dif ve-.6=vs(R/R1+R1/R)+RCvs' et ci =0 que la 1er fois (charge)
			a=Rd*C;	//		
			b=1+Rd/R;
			generateur->on();
			generateur->reglageOffset(-0.6);
			ci=u;
			cout << "diode passante"<<endl;
			bloquee=0;
		}
		if(vd<.6 && !bloquee ) //equa du type R1Cvs'+vs=0 avec ci non null (decharge)
		{
			generateur->reglageOffset(0.6);
			a=R*C;
			b=1;
			generateur->off();
			ci=u;
			cout << "diode bloquee"<<endl;
			bloquee=1;
		}
		
		solve();
		//cout <<"iii"<< generateur->E(t) << "iiii"<< <<endl;
		vd=generateur->E(t)-u-Rd*C*(u-up)/pas+u/R;
		cout <<"vd"<< vd <<endl;
	}	
}
