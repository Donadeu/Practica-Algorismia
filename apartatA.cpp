#include <cstdlib>
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void read_graph(vector<pair<int,int>> &adj){
	int a, b;
	while(cin >> a >> b){
		adj.push_back(make_pair(a,b));
	}
}

void print_graph(vector<pair<int,int>> adj){
	for(int i = 0; i < adj.size(); i++){
		cout << "(" << adj[i].first <<"," << adj[i].second << ")" << endl;
	}
}

void percolation_sites(vector<pair<int,int>> &adj, list<int> &nodes){
	default_random_engine generator;
	bernoulli_distribution distribution(q);
	
	list<int>::iterator it;
	for(it = nodes.begin(); it != nodes.end(); it++){
		// probabilitat que el node falli
		bool falla = distribution(generator);
		if(falla){
			if(site_per) nodes.remove(*it); // s'elimina el node
			// s'eliminen les seves adjacències
			vector<pair<int,int>>::iterator it = find_if(adj.begin(), adj.end(), Cond);
			if(it != adj.end()) adj.erase(it);
			// o bé:
			vector<pair<int,int>>::iterator it = find_if(adj.begin(), adj.end(), [&int x] (const pair<int,int> &p) {return x == p.first or x == p.second;});
	}
}

bool Cond(pair<int,int> p, int x){
	return (x == p.first or x == p.second);
}

void percolation_bonds(vector<pair<int,int>> &adj){
	default_random_engine generator;
	bernoulli_distribution distribution(q);
	
	for(int i = 0; i < adj.size(); i++){
		// probabilitat que aresta falli
		bool falla = distribution(generator);
		if(falla) adj.erase(i);
	}
}

int main(){

	string tipus;
	cin >> tipus >> endl;
	
	int n; // num de nodes
	cin >> n >> endl;
	
	int q; // probabilitat que node o aresta falli
	cin >> q >> endl;
	
	list<int> nodes = nodes(n); // llista de nodes

	vector<pair<int,int>> adj;
	read_graph(adj); // adjacències del graf
	
	if(tipus == "sites") percolation_sites(adj,nodes);
	else if(tipus == "bonds") percolation_bonds(adj);
		
	print_graph(adj);
}