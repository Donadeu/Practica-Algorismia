#include <iostream>
#include <random>
#include <vector>
#include <time.h>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "apartatB.h"
#include "quickUnion.h"

using namespace std;

int mida;

int getRandom(int n){
	return (rand() % n);
}


/* el quickUnion crea graella NxN amb caselles tancades*/
Percolacio::Percolacio(int n){
	QuickUnion aux = QuickUnion(n);
	mida = n;
	this->qu = aux;
}
 /* eliminar graella */
/*void Percolacio::dPercolacio() {
	delete *qu;
}*/

QuickUnion Percolacio::getQu(){
	return this->qu;
}


/* obrir una casella (i unir-la amb les obertes del seu
 entorn immediat */
bool Percolacio::obrir(int row, int col) {
	bool obre = false;
    // row-> j & col->i
    if (isOpen(row, col)) return obre;
	qu.setOpen(row, col, true);
	obre = true;
    auto current_site_id = qu.getSite(row, col).id; // casella just oberta

    // connectar la casella recentment oberta a les seves veïnes obertes

	// veí de baix
	if(row != 0 && qu.getSite(row-1, col).open){
		qu.Union(qu.getSite(row-1, col).id, current_site_id);
	}
	// veí de dalt
	if(row != mida-1 && qu.getSite(row+1, col).open){
		qu.Union(qu.getSite(row+1, col).id, current_site_id);
	}
	// veí de l'esquerra
	if (col != 0 && qu.getSite(row, col-1).open) {
        qu.Union(qu.getSite(row, col-1).id, current_site_id);
    } 
	// veí de la dreta
	if (col != mida-1 && qu.getSite(row, col+1).open) {
        qu.Union(qu.getSite(row, col+1).id, current_site_id);
    } 
	return obre;
}

/* la casella està oberta? */
bool Percolacio::isOpen(int f, int c) {
	return qu.getSite(f, c).open;
}

/* casella oberta està plena si pot ser connectada a una altra
 d'oberta de la fila de dalt de tot
*/
bool Percolacio::isFull(int f, int c){
	return qu.isConnected(qu.getSite(f, c).id, 0);
}

/* hi ha alguna casella de la fila de baix de tot connectada a la 
 primera fila? (afirmatiu-> sistema percola) */
bool Percolacio::percolates(){
	for(int i = 0; i < mida; i++){
		if(qu.isConnected(qu.getSite(mida-1, i).id, 0)) return true;
	}
	return false;
}


int main(int argc, char *argv[]){

	if (argc < 3) {
		cout << "Massa pocs arguments " << endl;
		return -1;
	}
	/*
	REPETIR EL SEGÜENT PROCEDIMENT (per obtenir un valor mitjà del llindar):
	1. inicialment, totes les caselles tancades
	2. escollir casella random (parametres i,j)
	3. obrir-la
	4. sistema percola? (negatiu: tornem a punt 2)
	5. la fracció de caselles obertes (respecte les totals) estima el llindar */
	
	auto start = std::chrono::system_clock::now();
	
	int size = atoi(argv[1]);
	int repeticions = atoi(argv[2]);
	Percolacio p = Percolacio(size);
	int obertes = 0;
	int i, j;
	int iteracions = 0;
	float iteracions_avg = 0;
	srand(time(0));
	float llindar = 0;
	float llindar_avg = 0; 
	bool obre;
	for (int i = 0; i < repeticions; ++i){
		iteracions = 0;
		obertes = 0;
		p = Percolacio(size);
		while(!p.percolates()) {
			iteracions++;
			i = getRandom(size);
			j = getRandom(size);
			obre = p.obrir(i,j);
			if(obre) obertes++;
		}
		llindar = float(obertes)/float(size*size);
		llindar_avg += llindar;
		iteracions_avg += iteracions;
	}
	
	auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    
	llindar_avg = llindar_avg / float(repeticions);
	iteracions_avg = iteracions_avg / float(repeticions);
	cout << "Després de " << repeticions << " execucions, el sistema percola de mitjana amb el llindar " << llindar_avg << " el bucle ha realitzat de mitjana " << iteracions_avg << " iteracions" << endl;
	cout << "Temps d'execució: " << time.count() * (10*10*10*10*10*10) << " microsegons " << endl;

}
