#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include "apartatB.h"
using namespace std;

inline getRandom(int n){
	return (rand() % n);
}


/* el quickUnion crea graella NxN amb caselles tancades*/
Percolacio::Percolacio(int n){
	qu = new QuickUnion(n);
}
 /* eliminar graella */
Percolacio::~Percolacio() {
	delete qu;
}

/* obrir una casella (i unir-la amb les obertes del seu
 entorn immediat */
bool Percolacio::obrir(int row, int col) {
	bool obre = false;
    // row-> j & col->i
    if (isOpen(row, col))
    return obre;

    qu->grid[row][col].open = true;
	obre = true;
    auto current_site_id = qu->grid[row][col].id; // casella just oberta

    // connectar la casella recentment oberta a les seves veïnes obertes

	// veí de baix
	if(row != 0 && qu->grid.[row-1][col].open){
		qu->Union(qu->grid.[row-1][col].id, current_site_id);
	}
	// veí de dalt
	if(row != size-1 && qu->grid[row+1][col].open){
		qu->Union(qu->grid[row+1][col].id, current_site_id);
	}
	// veí de l'esquerra
	if (col != 0 && qu->grid[row][col-1].open) {
        qu->Union(qu->grid[row][col-1].id, current_site_id);
    } 
	// veí de la dreta
	if (col != size-1 && qu->grid[row][col+1].open) {
        qu->Union(qu->grid[row][col+1].id, current_site_id);
    } 
	return obre;
}

/* la casella està oberta? */
bool Percolacio::isOpen(int f, int c) {
	return qu->grid[f][c].open;
}

/* casella oberta està plena si pot ser connectada a una altra
 d'oberta de la fila de dalt de tot
*/
bool Percolacio::isFull(int f, int c){
	return qu->isConnected(qu->grid[f][c].id, 0);
}

/* hi ha alguna casella de la fila de baix de tot connectada a la 
 primera fila? (afirmatiu-> sistema percola) */
bool Percolacio::percolates(){
	for(int i = 0; i < qu->count; i++){
		if(qu->isConnected(qu->grid[qu->count - 1][i].id,0)) return true;
	}
	return false;
}


int main(int argc, char *argv[]){

	if (argc < 2) {
		cout << "Massa pocs arguments " << endl;
		return -1;
	}
	/*
	REPETIR EL SEGÜENT PROCEDIMENT (per obtenir un valor mitjà del llindar):
	1. inicialment, totes les caselles tancades
	2. escollir casella random (parametres i,j)
	3. obrir-la
	4. sistema percola? (negatiu: tornem a punt 2)
	5. la fracció de caselles obertes (respecte les totals) estima el llindar 
	*/
	int size = atoi(argv[1]);

	p = Percolacio(size);
	int obertes = 0;
	int i, j;

	bool obre;
	while(!p.percolates()) {
		i = getRandom(size);
		j = getRandom(size);
		obre = p.obrir(i,j);
		if(obre) obertes++;
	}
	cout << "El sistema percola amb el llindar " << float(obertes)/float(size*size) << endl;

}
