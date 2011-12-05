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
		virtual void recapitulation();
};

/* Classe "voiture" qui hérite de "mobile". */
class voiture : public mobile{
	protected:
		double masse, consommation;
	public:
		voiture();
		virtual void recapitulation();
};

/* Classe "deuxRoues" qui hérite de "mobile". */
class deuxRoues : public mobile{
	protected:
		double prix;
		int type;
	public:
		deuxRoues();
		virtual void recapitulation();
};

/* Classe "noeud". */
class noeud{
	public:
		noeud(mobile * mob);
		noeud* getPrecedent();
		noeud* getSuivant();
		void setSuivant(noeud* suiv);
		void setPrecedent(noeud* prec);
		void enumerer(noeud* dernierElement);
	private:
		noeud * precedent;
		noeud * suivant;
		mobile * element;
};