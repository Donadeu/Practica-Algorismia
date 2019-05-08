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
	
	cout << "Intentem obrir (1, 4): " << endl;
	p.obrir(1, 4);
	cout << "Matriu resultant:" << endl;
	qu_aux = p.getQu();
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << qu_aux.getSite(i, j).id << " ";
			if (j == n-1) cout << endl;
		}
	}
	return 0;
} 
