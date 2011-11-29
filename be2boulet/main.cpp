/* Programmation ortientee objet : BE2 */
/* Jeremie Fourmann et Maxime Morin    */
/* main.cpp                            */
/* Programme principal                 */


#include <iostream>
#include "circuits.h"
#include "sources.h"

using namespace std;

int main(int argc, char **argv)
{	
	
	cout.width(6);
	cout.precision(4);

	circuit * montage;
	int choix=0;
		
		cout << "#Premier Ordre :" << endl;
		cout << "#1 - Exemple 1" << endl;
		cout << "#2 - Circuit A" << endl;
		cout << "#3 - Circuit B" << endl;
		cout << "#Deuxième Ordre :" << endl;
		cout << "#4 - Exemple 2" << endl;
		cout << "#5 - Circuit C" << endl;
		cout << "#6 - Circuit D" << endl;
		cin >> choix;

		switch(choix){
		case 1:
			montage = new exemple1; 
			break;
		case 2:
			montage = new circuitA;
			break;	
		case 3:
			montage = new circuitB;
			break;	
		case 4:
			montage = new exemple2;
			break;	
		case 5:
			montage = new circuitC;
			break;	
		case 6:
			montage = new circuitD;
			break;	
		default:
			cout << "#Mauvaix choix" << endl;
			return 0;
		}
			
			
	montage->circuitSolve();

	return 0;
}

