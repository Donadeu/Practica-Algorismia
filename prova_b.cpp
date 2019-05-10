#include <cstdlib>
#include <random>
#include <iostream>
#include <vector>
#include "apartatB.h"

using namespace std;

int main(int argc, char *argv[]){

	cout << "Introdueix la mida de la Percolacio" << endl;
	int n;
	cin >> n;
	Percolacio p = Percolacio(n);
	QuickUnion qu_aux = p.getQu();
	
	cout << "Matriu resultant:" << endl;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << qu_aux.getSite(i, j).id << " ";
			if (j == n-1) cout << endl;
		}
	}
	
	cout << "Intentem obrir (0, 3): " << endl;
	p.obrir(0, 3);
	cout << "Intentem obrir (1, 3): " << endl;
	p.obrir(1, 3);
	cout << "Intentem obrir (2, 3): " << endl;
	p.obrir(2, 3);
	cout << "Intentem obrir (3, 3): " << endl;
	p.obrir(3, 3);
	
	cout << "Matriu resultant:" << endl;
	qu_aux = p.getQu();
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << qu_aux.getSite(i, j).id << " ";
			if (j == n-1) cout << endl;
		}
	}
	cout << "Matriu resultant mostrant el valor de open en lloc de id:" << endl;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << qu_aux.getSite(i, j).open << " ";
			if (j == n-1) cout << endl;
		}
	}
	
	cout << "Percola la matriu? " << p.percolates() << endl;
	
	return 0;
} 
