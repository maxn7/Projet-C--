
#ifndef DEF_objets
#define DEF_objets
#include "source.h"
/* Classe "euler" resolution de au'+bu=f. */
class euler{
	protected:
		double a,b,ci,pas,duree,u,up,t ; 
		source *generateur;
	public:
		euler();
		void diffSolve();
		virtual void circuitSolve() =0;
};
/* Classe ex1 resolution qui sert a rien */
class exemple1 : public euler{
	public:
		exemple1();
};
/* Classe circuit (choix de la source) */
class circuit : public euler{
	public:
		circuit();
};
/* Classe circuitA  */
class circuitA : public circuit{
	protected:
		double R,C;
	public:
		circuitA();
		void circuitSolve();
};

/* Classe circuitA  */
class circuitB : public circuit{
	protected:
		double Rd,C,R;
	public:
		circuitB();
		void circuitSolve();
};

#endif
