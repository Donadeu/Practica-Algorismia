#include <cstdlib>
#include <random>
#include <iostream>
#include <vector>
#include "quickUnion.h"

using namespace std;

int main(int argc, char *argv[]){

	cout << "Introdueix la mida del QuickUnion" << endl;
	int n;
	cin >> n;
	Matrix2D gridaux(n, vector<Site>(n));
	int size1 = gridaux.size();
	int size2 = gridaux[0].size();
	cout << "Mida de la matrix que es generarà: " << size1 << " files " << size2 << " columnes" <<endl;
	QuickUnion qu = QuickUnion(n);
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << qu.getSite(i, j).id << " ";
			if (j == n-1) cout << endl;
		}
	}
	
	cout << "Arrel: " << qu.root(7) << endl;
	qu.Union(7, 2);
	cout << "Despres de Union 7, 2: " << endl;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << qu.getSite(i, j).id << " ";
			if (j == n-1) cout << endl;
		}
	}
	cout << "Arrel del 7: "  << qu.root(7) << endl;
	cout << "Arrel del 2: "  << qu.root(2) << endl;
	cout << "Arrel del 5: "  << qu.root(5) << endl;
	cout << "Estan connectats 7 i 2? " << qu.isConnected(7, 2) << endl;
	cout << "Estan connectats 7 i 5? " << qu.isConnected(7, 5) << endl;
	return 0;
} 
