#include <iostream>
#include "source.h"
#include <math.h>

using namespace std;

//Méthode de la classe Source

source::source(){
	T=2;
	phi=0;
	offset=0;
	ampli=5;
	alpha=.5;
}

void source::reglage(double TN, double phiN, double offsetN, double ampliN){
	T=TN;
	phi=phiN;
	offset=offsetN;
	ampli=ampliN;
}

double echelon::E(double t){
	double fx;
	if(phi <t ) fx= offset+ampli;
	else fx= offset;
	return fx;
}

double porte::E(double t){
	double fx;
	if(phi < t && t <phi+T) fx=offset+ampli;
			else fx=offset;
	return fx;
}

double triangle::E(double t){
	double fx;
	if(t-floor((t-phi)/T)*T<=T/2) fx=(t-floor((t-phi)/T)*T-.5)*ampli+offset;
			else fx=(-(t-floor((t-phi)/T)*T)+2-.5)*ampli+offset;
	return fx;
}

double carre::E(double t){
	double fx;
	if(t-floor((t-phi)/T)*T<T*alpha) fx=offset+ampli;
			else fx=offset;
	return fx;
}


double fctExo1::E(double t){
	
	return -3*t;
}
