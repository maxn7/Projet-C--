#ifndef DEF_source
#define DEF_source
//Classe Mère Source 
class source{ 

	protected:
		double T,phi,offset,ampli,alpha,sauvAmpli;
		double A,B;
	public:
		source();
		virtual double E(double t)=0; //fct virtuelle de la source 
		double Esm(double t); // Transformation affine de E pour changer amplitude
							  // ou ajouter un offset dans le second membre
		void setAB(double Ai, double Bi); //accesseur pour les valeurs A et B
};
//classe fille pour les 4 différents signaux d'entrés
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

//Classe fille pour permetant de traiter l'exo1
class fctExo1 : public source{
	public:
		 double E(double t);
};
#endif
