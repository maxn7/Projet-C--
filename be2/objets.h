/*BE2 : d�claration des classes */

/* Classe "euler". */
class euler{

	protected:
		double a,b,ci,pas,duree;
	public:
		euler();
		virtual double f(double t) = 0; //Second membre
		void solve();
};

/* Classe "exemple" qui h�rite de "euler". */
class exemple1 : public euler{

	public:
		exemple1();
		double f(double t);
};

/* Classe "circuita" qui h�rite de "euler". */
class circuita : public euler{

	protected:
		int source;
	public:
		circuita(double C, double R, int tsource);
		double f(double t);
};