//      
//      
//     TD1-Programation C++
//
//      
//      


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
	
		cout << "#Quel montage ?" << endl;
		cout << "#1 - Circuit A" << endl;
		cout << "#2 - Circuit B" << endl;
		cin >> choix;

		switch(choix){
		case 1:
			montage = new circuitA; 
			break;
		case 2:
			montage = new circuitB;
			break;	
		default:
			cout << "#Mauvaix choix" << endl;
			return 0;
		}
			
			
	montage->circuitSolve();
	
	return 0;
}

