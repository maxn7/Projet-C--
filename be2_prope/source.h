#ifndef DEF_source
#define DEF_source
//Classe Mère Source 
class source{ 

	protected:
		double T,phi,offset,ampli,alpha,sauvAmpli;
	public:
		source();
		virtual double E(double t)=0; //fct virtuelle de la source 
		
		void reglageOffset(double offsetN);
		void on(); //permet de modifier les param du gene
		void off();
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
