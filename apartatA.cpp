#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <list>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iomanip>
#include <chrono>
using namespace std;

class Graph{
    int n;
    set<int> *adj;
    
public:
    Graph(int n);
    void addEdge(int v, int w);
    void deleteEdge(int v, int w);
    bool edgeExists(int v, int w);
    void printGraph();
    void percolation_sites(float q);
    void percolation_bonds(float q);
};
///////////////

Graph::Graph(int v){
    this->n = v;
    adj = new set<int>[n];
}

void Graph::addEdge(int v, int w){
    adj[v].insert(w);
    adj[w].insert(v);
}

void Graph::deleteEdge(int v, int w){
    adj[v].erase(w);
    adj[w].erase(v);
}

bool Graph::edgeExists(int v, int w){
    set<int>::iterator it;
    it = adj[v].find(w);
    if(it == adj[v].end()) return false;
    else return true;
}

///////////////

void read_graph(Graph g){
	int v, w;
	while(cin >> v >> w){
		g.addEdge(v,w);
	}
}

void Graph::printGraph(){
    set<int>::iterator it;
	for(int i = 0; i < n; i++){
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            cout << *it << " ";
        }
        cout << endl;
	}
}

void Graph::percolation_sites(float q){
    cout << "percolacio sites" << endl;
    srand(time(0));
	default_random_engine generator;
    int rand_seed = rand();
    generator.seed(rand_seed);
	std::bernoulli_distribution distribution(q);
	
	set<int>::iterator it;
	for(int i = 0; i < n; i++){
		// probabilitat que el node falli
		bool falla = distribution(generator);
		if(falla){
            cout << "falla node " << i << endl;
			adj[i].clear(); // s'elimina el node i les seves adjacencies
            this->printGraph();
			for(int j = 0; j < n; j++){
                it = adj[j].find(i);
                if(it != adj[j].end()) {
                    adj[j].erase(it);
                }
            }
		}
	}
}

bool Cond(pair<int,int> p, int x){
	return (x == p.first or x == p.second);
}

void Graph::percolation_bonds(float q){
    cout << "percolacio bonds" << endl;
    srand(time(0));
	default_random_engine generator;
    int rand_seed = rand();
    generator.seed(rand_seed);
	std::bernoulli_distribution distribution(q);
	
    bool falla;
    int v, w;
    
    set<int>::iterator it;
    
	for(int i = 0; i < n; i++){ // per cada node
        for(it = adj[i].begin(); it!= adj[i].end(); it++){
            // probabilitat que aresta falli
            falla = distribution(generator);
            if(falla) {
                this->printGraph();
                v = i;
                w = *it;
                cout << "falla aresta " << v << " " << w << endl;
                // comprovar que aresta existeix
                if(v != w and this->edgeExists(v,w)) this->deleteEdge(v,w);
            }
        }
    }
}


int main(){

	
	
	int n; // num de nodes
	cin >> n;
	
	float q; // probabilitat que node o aresta falli
	cin >> q;
	
	Graph g(n);

	read_graph(g); 
    
    string tipus;
    cin >> tipus;
    
    string sites = "sites";
    string bonds = "bonds";
    
    cout << tipus << endl;
    
	if(tipus == sites) g.percolation_sites(q);
	else if(tipus == bonds) g.percolation_bonds(q);
		
	g.printGraph();
}
