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
		double pas,duree,t ; 
		source *generateur;
	public:
		euler();
		virtual void diffSolve()=0;
		virtual void circuitSolve()=0;
};


/* Classe "circuit" (permet le choix de la source) */
class circuit : public euler{
	protected:
		double a,b,ci,u,up;
	public:
		circuit();
		virtual void diffSolve()=0;
		virtual void circuitSolve()=0;
};

/* Classe "circuit1" (1er ordre) */
class circuit1 : public circuit{		
	public:
		void diffSolve();
		virtual void circuitSolve() =0; //defini en fct du circuit 
};

/* Classe "exemple1". */
class exemple1 : public circuit1{
	public:
		exemple1();
		void circuitSolve();
};


/* Classe "circuitA". */
class circuitA : public circuit1{
	protected:
		double R,C;
	public:
		circuitA();
		void circuitSolve();
};

/* Classe "circuitB". */
class circuitB : public circuit1{
	protected:
		double Rd,C,R;
	public:
		circuitB();
		void circuitSolve();
};

/* Classe "circuit2" (2eme Ordre)*/ 
class circuit2 : public circuit{
	protected:
		double ci2,u2,u2p;
	public:
		circuit2();
		 virtual void diffSolve()=0;
		 virtual void circuitSolve();
};
/* Classe "exemple2" (2eme Ordre)*/ 
class exemple2 : public circuit2{
	public:
		exemple2();	
		void diffSolve();
		void circuitSolve(); //Redefinition pour les besoins de l'exemple	
};

/* Classe "circuitC". */
class circuitC : public exemple2{
	protected:
		double R,C,L;
	public:
		circuitC();
};

/* Classe "circuitD". */
class circuitD : public circuit2{
	protected:
		double R,C,L;
	public:
		circuitD();
		void diffSolve();
};

#endif
