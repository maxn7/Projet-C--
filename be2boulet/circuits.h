/* Programmation ortientee objet : BE2 */
/* Jeremie Fourmann et Maxime Morin    */
/* circuits.h                          */
/* Declaration des classes circuits    */

#ifndef DEF_circuits
#define DEF_circuits
#include "sources.h"

/* Classe "euler" pour la resolution de au'+bu=f. */
class euler{
	protected:
		double a,b,ci,pas,duree,u,up,t ; 
		source *generateur;
	public:
		euler();
		void diffSolve();
		virtual void circuitSolve() =0;
};

/* Classe "exemple1". */
class exemple1 : public euler{
	public:
		exemple1();
};

/* Classe "circuit" (permet le choix de la source) */
class circuit : public euler{
	public:
		circuit();
};

/* Classe "circuitA". */
class circuitA : public circuit{
	protected:
		double R,C;
	public:
		circuitA();
		void circuitSolve();
};

/* Classe "circuitB". */
class circuitB : public circuit{
	protected:
		double Rd,C,R;
	public:
		circuitB();
		void circuitSolve();
};

#endif
