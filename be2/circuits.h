/* Programmation ortientee objet : BE2 */
/* Jeremie Fourmann et Maxime Morin    */
/* circuits.h                          */
/* Declaration des classes circuits    */

#ifndef DEF_circuits
#define DEF_circuits
#include "sources.h"

/* Classe "euler"*/
class euler{
	protected:
		double pas,duree,t,a,b,ci,ci2,u,up,u2,u2p ; 
		source *generateur;
	public:
		euler();
		virtual void diffSolve()=0;
		virtual void circuitSolve() =0;
};

/* Classe "euler1" pour la resolution de au'+bu=f. */
class euler1 : public euler{
	protected:
		
	public:
		euler1();
		void diffSolve();
		virtual void circuitSolve() =0;
};

/* Classe "Euler 2 pour la resolution de u''=au'+bu+f */

class euler2 :public euler{
	protected:
		
	public:
		euler2();
		void diffSolve();
		void circuitSolve();
};



/* Classe "exemple1". */
class exemple1 : public euler1{
	public:
		exemple1();
};

/* Classe "exemple2". */
class exemple2 : public euler2{
	public:
		exemple2();
};

/* Classe "circuit" (permet le choix de la source) */
class circuit : public euler1{
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
