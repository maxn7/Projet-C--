/*BE2 : d�finition des m�thodes des classes */

#include <iostream>
#include "objets.h"
#include <math.h>
using namespace std;

/* M�thodes de la classe "euler". */
euler::euler(){
	a=0.0;
	b=0.0;
	ci=0.0;
	pas=0.01;
	duree=10.0;
}
void euler::solve(){
	//int N= ((double)duree/(double)pas),i=0;
	double u=ci, up=ci;
	double t=0;

	while(t<duree)
	{
		u=(pas/a)*(f(t)+up*(-b+a/pas));
		up=u;
		cout << t << "  " << f(t) <<"  "<<up<< endl;
		t=t+pas;
	}

}

/* M�thodes de la classe "exemple1". */
double exemple1:: f(double t){
	return -3*t;
}

exemple1::exemple1(){
	a=1;
	b=3;
	ci=0;
}

/* M�thodes de la classe "circuita". */

circuita::circuita(double C, double R, int tsource){
	a=R*C;
	b=1;
	source = tsource;
}
double circuita:: f(double t){
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
}