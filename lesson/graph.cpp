#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//undirected graph
Graph::Graph(int V) : V_count(V), E_count(0){
    adj = new vector<int>[V];
}

Graph::Graph(const string& filename){
    std::ifstream infile(filename); // Open the file
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }
    
    infile >> V_count; // Read number of vertices
    infile >> E_count; // Read number of edges

    adj = new vector<int>[V_count]; // Allocate adjacency list

    int x, y;
    for (int i = 0; i < E_count; ++i) {
        infile >> x >> y; // Read edge (x, y)
        add_edge(x, y);
    }
    infile.close();
}

Graph::~Graph(){
    delete[] adj;
}

int Graph::V() const{
    return V_count;
}

int Graph::E() const{
    return E_count;
}

void Graph::add_edge(int x, int y){
    if(x<V_count && y<V_count){
        adj[x].push_back(y);
        adj[y].push_back(x);
        E_count++;
    }
}

void Graph::remove_edge(int x, int y){
    
}

bool Graph::adjacent(int x, int y) const{
    if(x < V_count && x < E_count){
        for(int i=0 ; i < adj[x].size() ; i++){
            if(adj[x][i] == y) return true;
        }
    }
    return false;
}

vector<int> Graph::neighbors(int x) const{
    if(x < V_count){return adj[x];}
    return vector<int>();
} 

int Graph::degree(int v) const{
    return  adj[v].size();
}

string Graph::toString() const{
    string s="";
    for(int i=0 ; i<V_count ; i++ ){
        s = s + to_string(i) + " :";
        for(int j=0; j<adj[i].size() ; j++ ){
            s = s + to_string(adj[i][j]) + "->";
        }
        s = s + "Null\n";
    }
    return s;
}



