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

int iteracions = 0;

class Graph{
    int n;
    set<int> *adj;
    
public:
    Graph(int n);
    void addEdge(int v, int w);
    void deleteEdge(int v, int w);
    bool edgeExists(int v, int w);
    bool BFS(int s);
    void printGraph();
};

Graph::Graph(int v){
    this->n = v;
    adj = new set<int>[n];
}

void Graph::addEdge(int v, int w){
    adj[v].insert(w);
}

void Graph::deleteEdge(int v, int w){
    adj[v].erase(w);
}

bool Graph::edgeExists(int v, int w){
    set<int>::iterator it;
    it = adj[v].find(w);
    if(it == adj[v].end()) return false;
    else return true;
}


bool Graph::BFS(int s){
    // cas base
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    
    visited[s] = true;
    
    list<int> queue;
    queue.push_back(s);
    
    set<int>::iterator i;
    
    while(!queue.empty()){
        s = queue.front();
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i){
			++iteracions;
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    for (int j = 0; j < n; j++) if (!visited[j]) return false;
    return true;
}


void Graph::printGraph(){
    set<int>::iterator it2;
    for(int i = 0; i < n; i++){
        for(it2 = adj[i].begin(); it2 != adj[i].end(); it2++){
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

        
// construeix graf complet de mida n
void complete_graph(Graph &g, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j) g.addEdge(i,j);
        }
    }
}
    
float percolation(Graph &g, int n){

    /*
     * 1. Trio aresta random
     * 2. L'elimino (incrementar comptador)
     * 3. Graf segueix sent connex? (mirem si les 2 arestes eliminades són reachable)
     * 4. Afirmatiu: anar al pas 1
     * 5. Negatiu: retornar nombre d'arestes eliminades
     * */

    float count = 0; // arestes eliminades
    int v, w;
    
    srand(time(0));
    bool connex = true;
    while(connex){		
		v = rand()%n;
		w = rand()%n;
    // comprovar que aresta existeix
		if(v != w and g.edgeExists(v,w)) {
			g.deleteEdge(v,w);
			++count;
			connex = g.BFS(v);
		}		
    }
    return count;
}
    

int main(int argc, char *argv[]){
    
    if (argc < 2) {
		cout << "Massa pocs arguments " << endl;
		return -1;
	}
    
    auto start = std::chrono::system_clock::now();

    int n = atoi(argv[1]);
    float a = n*(n-1); // arestes totals
    
    Graph g(n);
    complete_graph(g,n);
    
    /* cout << "Graf generat: " << endl;
    
    g.printGraph();*/
    
    float p = percolation(g,n); // p = num arestes random eliminades
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;
    
    cout << "arestes eliminades: " << p << endl;
    cout << "fraccio 1-p: " << setprecision(4) << p/a << endl;    
    cout << "temps d'execució: " << time.count()*(10*10*10*10*10*10) << " microsegons" << endl;
    //cout << "Número d'iteracions de la funció percolation: " << iteracions << endl;
    
}
