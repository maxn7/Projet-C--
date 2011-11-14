/* Classe mere Source  */
class source{ 

	protected:
		double 	T,phi,offset,ampli;
	public:
		source(double ,double , double,double);
		virtual double E(double t)=0;
};

/*
class smex1 : public source{
	protected:
		
	public:
		 double f(double t);
};
*/
class echelon : public source{
	protected:
		
	public:
		 double E(double t);
};

/*
class porte : public source{
	protected:
		
	public:
		 double f(double t);
};

class triangle : public source{
	protected:
		double alpha;
	public:
		triangle(double);
		 double f(double t);
};

class carre : public source{
	protected:
		double alpha;
	public:
		carre(double);
		 double f(double t);
};
*/