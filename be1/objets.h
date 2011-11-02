/*BE1 : déclaration des classes */

/* Classe "mobile". */
class mobile{
	private :
		int immatriculation;
	protected:
		double vitesse , position;
	public:
		mobile();
		mobile(int x,double y);
		void calculPosition(double);
		double getVitesse();
		void putVitesse();

};

/* Classe "voiture" qui hérite de "mobile". */
class voiture : public mobile{
	protected:
		double masse, consommation;
	public:
		voiture();
};

/* Classe "deuxRoues" qui hérite de "mobile". */
class deuxRoues : public mobile{
	protected:
		double prix;
		int type;
	public:
		deuxRoues();
};