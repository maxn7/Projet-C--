/*BE2 : d�claration des classes */
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


/* Classe "exemple" qui h�rite de "euler". */
class exemple1 : public euler{

	public:
		exemple1();
		double f(double t);
};

/* Classe "circuit" qui h�rite de "euler". */
class circuit : public euler{
	public:
		circuit(source*);
};


/* Classe "circuita" qui h�rite de "circuit". */
class circuita : public circuit{
	protected:

	public:
		circuita(double C, double R);
};

