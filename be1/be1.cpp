/*BE1 : fichier principal */

#include <iostream>
#include "objets.h"
using namespace std;


int main()
{
	mobile* p;
	int choix = 0;

	while(choix != 3){
		cout << "Que voulez-vous creer ?" << endl;
		cout << "1 - Une voiture" << endl;
		cout << "2 - Un deux roues" << endl;
		cout << "3 - Quitter" << endl;
		cin >> choix;

		switch(choix){
		case 1:
			p=new(voiture);
			p->getVitesse();
			break;
		case 2:
			p=new(deuxRoues);
			p->getVitesse();
			break;
		default:
			break;
		}
	}
	
	return 0;

}

