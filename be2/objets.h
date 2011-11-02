/*BE2 : déclaration des classes */

/* Classe "eq1". */
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
		double f(double t);
};
