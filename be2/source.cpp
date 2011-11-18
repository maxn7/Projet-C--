#include <iostream>
#include "source.h"
#include <math.h>

using namespace std;

//Méthode de la classe Source

source::source(){
	T=2;
	phi=1;
	offset=0;
	ampli=5;
	alpha=.6;
	A=1, B=0;
}

double source::Esm(double t)
{
	return A*E(t)+B ;
} 

void source::setAB(double Ai, double Bi)
{
	A = Ai;
	B = Bi;
}

double echelon::E(double t){
	double fx;
	if(phi <=t ) fx= offset+ampli;
	else fx= offset;
	return fx;
}

double porte::E(double t){
	double fx;
	if(phi < t && t <phi+T) fx=offset+ampli;
			else fx=offset;
	return fx;
}

double carre::E(double t){
	double fx;
	if((t-phi)-floor((t-phi)/T)*T<T*alpha) fx=offset+ampli;
			else fx=offset;
	return fx;
}

double triangle::E(double t){
	double fx;
	if((t-phi)-floor((t-phi)/T)*T<=T/2) fx=((t-phi)-floor((t-phi)/T)*T-.5)*ampli+offset;
			else fx=(-((t-phi)-floor((t-phi)/T)*T)+2-.5)*ampli+offset;
	return fx;
}

double fctExo1::E(double t){
	
	return -3*t;
}
