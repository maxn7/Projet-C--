/*BE2 : définition des méthodes des classes */

#include <iostream>
#include "objets.h"
#include <math.h>
using namespace std;

/* Méthodes de la classe "euler". */
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


/* Méthodes de la classe "circuit". */
circuit::circuit(source * gene){
	generateur=gene;	//generateur = gene;
}

/* Méthodes de la classe "circuita". */
 circuita::circuita(double C, double R){
	a=R*C;
	b=1;
}

/* Méthodes de la classe "source". */
source::source(double Tn ,double phin , double offsetn,double amplin){
	
	T=Tn;
	phi=phin;
	offset=offsetn;
	ampli=amplin;

}

double echelon::E(double t){
	double fx;
	if(phi <t ) fx= offset+ampli;
	else fx= offset;
	return fx;
	
}
	/*
	double fx;
	double T=2.0,phi=0,offset=0.0,ampli=5.0,alpha=.5;
		switch(source){
		case 1: //Fonction porte
			if(phi < t && t <phi+T) fx=offset+ampli;
			else fx=offset;
			break;

		case 2: //Fonction echelon
				if(phi <t ) fx=offset+ampli;
				else fx=offset;
				break;

        case 3: //Fonction carre
			if(t-floor((t-phi)/T)*T<T*alpha) fx=offset+ampli;
			else fx=offset;
			break;

		case 4: //Fonction triangle
			if(t-floor((t-phi)/T)*T<=T/2) fx=(t-floor((t-phi)/T)*T-.5)*ampli+offset;
			else fx=(-(t-floor((t-phi)/T)*T)+2-.5)*ampli+offset;
			break;			
	
		default:
			cout << "Source inconnue" << endl;
			fx=0;
			break;
		}
	return fx;
	*/