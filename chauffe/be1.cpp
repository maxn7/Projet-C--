/*BE1 : fichier principal */

#include <iostream>
#include "objets.h"
using namespace std;


int main()
{
	mobile* p = NULL;

	noeud* curseur =new noeud(p);
	noeud* ptemp;
	int choix = 0;


	while(choix != 4){
		cout << "Que voulez-vous creer ?" << endl;
		cout << "1 - Une voiture" << endl;
		cout << "2 - Un deux roues" << endl;
		cout << "3 - Recapituler" << endl;
		cout << "4 - Quitter" << endl;
		cin >> choix;

		switch(choix){
		case 1:
			p=new(voiture);
			p->getVitesse();
			
			ptemp=curseur;
			curseur->setSuivant(new noeud(p));
			curseur=curseur->getSuivant();
			curseur->setPrecedent(ptemp);
			

			break;
		case 2:
			p=new(deuxRoues);
			p->getVitesse();
			break;
		case 3:
			curseur->enumerer(curseur);
			break;		
		default:
			break;
		}
	}
	
	return 0;

}

