/* Programmation ortientée objet : BE2 */
/* Jeremie Fourmann et Maxime Morin    */
/* sources.h                           */
/* Declaration des classes sources     */

#ifndef DEF_sources
#define DEF_sources

/* Classe mère : source. */ 
class source{ 

	protected:
		double T,phi,offset,ampli,alpha,sauvAmpli;
		double A,B;
	public:
		source();
		virtual double E(double t)=0;//fct virtuelle de la source 
		double Esm(double t); // Transformation affine de E pour changer amplitude
							  // ou ajouter un offset dans le second membre
		void setAB(double Ai, double Bi); //accesseur pour les valeurs A et B
};

/* Classe fille permettant de traîter l'exemple 1. */
class fctExo1 : public source{
	public:
		 double E(double t);
};

/* Classes filles pour les differnets signaux d'entree. */
class echelon : public source{
	public:
		 double E(double t);	 
};

class porte : public source{
	public:
		 double E(double t);
};

class triangle : public source{
	public:
		 double E(double t);
};
class carre : public source{
	public:
		 double E(double t);
};

#endif
