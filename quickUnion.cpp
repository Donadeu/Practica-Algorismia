#include <cstdlib>
#include <random>
#include <iostream>
#include <vector>
#include "QuickUnion.h"

QuickUnion::QuickUnion(const int N){
	// crear graella NxN: totes caselles tancades, ids corresponents
	// afegir Sites als vector2D
	// Cada Site està tancada, si pertany a la primera fila: id = 0
	Site aux;
	aux.open = false;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i = 0) aux.id = 0;
			else aux.id = i+j;
			grid[i].push_back(aux);
		}
	}
}

bool QuickUnion::isConnected(int p, int q){
	return (root(p) == root(q));
}

int QuickUnion::root(int p){
	while(p != id[p]) p = id[p];
	return p;
}

void QuickUnion::Union(int p, int q){
	int i = root(p);
	int j = root(q);
	if(j == 0) p.id = j; // connectada a casella de la fila superior? 
	else q.id = i; // altrament
}