/*BE2 : définition des méthodes des classes */

#include <iostream>
#include "objets.h"
#include <math.h>
using namespace std;

/* Méthodes de la classe "euler". */
euler::euler(){
	a=1.0;
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
		cout << t << "  " << up << endl;
		t=t+pas;
	}

}

/* Méthodes de la classe "exemple1". */
double exemple1:: f(double t){
	return t;
}