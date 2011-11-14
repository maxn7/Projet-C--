/*BE2 : déclaration des classes */
#include "source.h"

/* Classe "euler". */
class euler{

	protected:
		double a,b,ci,pas,duree ;
		source *generateur;

	public:
		euler();
		void solve();
};


/* Classe "exemple" qui hérite de "euler". */
class exemple1 : public euler{

	public:
		exemple1();
		double f(double t);
};

/* Classe "circuit" qui hérite de "euler". */
class circuit : public euler{
	public:
		circuit(source*);
};


/* Classe "circuita" qui hérite de "circuit". */
class circuita : public circuit{
	protected:

	public:
		circuita(double C, double R);
};

