#include <cstdlib>
#include <random>
#include <iostream>
#include <vector>
#include "quickUnion.h"

using namespace std;

QuickUnion::QuickUnion( int N){
	Matrix2D gridaux(N, vector<Site>(N));
	// crear graella NxN: totes caselles tancades, ids corresponents
	// afegir Sites als vector2D
	// Cada Site està tancada, si pertany a la primera fila: id = 0
	Site aux;
	int iter = 0;
	aux.open = false;
	this->mida = N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == 0) aux.id = 0;
			else aux.id = iter;
			gridaux[i][j] = aux;
			iter++;
		}
	}
	this->grid = gridaux;
}

bool QuickUnion::isConnected(int id1, int id2){
	return (root(id1) == root(id2));
}

Site QuickUnion::getSite(int x, int y){
	return this->grid[x][y];
}

int QuickUnion::root(int p){
	int x = (int)p / mida;
	int y = p % mida;
	while(p != this->grid[x][y].id) p = this->grid[x][y].id;
	return p;
}

void QuickUnion::Union(int p, int q){
	int i = root(p);
	int j = root(q);
	int x1 = (int)p / mida;
	int y1 = p % mida;
	int x2 = (int)q / mida;
	int y2 = q % mida;
	if(j == 0) this->grid[x1][y1].id = j; // connectada a casella de la fila superior? 
	else this->grid[x2][y2].id = i; // altrament
}
