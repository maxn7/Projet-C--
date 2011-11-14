/*BE2 : déclaration des classes */

/* Classe "euler". */
class euler{

	protected:
		double a,b,ci,pas,duree;
	public:
		euler();
		virtual double f(double t) = 0; //Second membre
		void solve();
};

/* Classe "exemple" qui hérite de "euler". */
class exemple1 : public euler{

	public:
		exemple1();
		double f(double t);
};

/* Classe "circuita" qui hérite de "euler". */
class circuita : public euler{

	protected:
		int source;
	public:
		circuita(double C, double R, int tsource);
		double f(double t);
};