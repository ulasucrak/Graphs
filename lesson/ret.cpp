#include "graph.h"
#include <queue>
// Test the Graph class

void printNeighbors(const vector<int> &neighbors,int s) {
    cout << "Neighbors of " << s << endl;
    for (size_t i = 0; i < neighbors.size(); ++i) {
        cout << neighbors[i] << " ";
    }
}

void BFS(Graph& g, int s);
void DFS(Graph& g);
void DFS_visit(int u, Graph& g);
void printDFSResults(const Graph& g);

int main() {
    Graph g(9); // Create a graph with 5 vertices

    g.add_edge(0, 5);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(2, 5);

    g.add_edge(4, 3);
    g.add_edge(4, 5);
    g.add_edge(6, 7);
    g.add_edge(7, 8);

    cout << "Graph representation:\n";
    cout << g.toString();

    cout << "\nNumber of vertices: " << g.V();
    cout << "\nNumber of edges: " << g.E();

    cout << "\nNeighbors of vertex 2: ";
    vector<int> neighbors = g.neighbors(2);
    printNeighbors(neighbors, 2);

    cout << "\nIs there an edge from 0 to 1? " << (g.adjacent(0, 1) ? "Yes" : "No") << "\n";
    cout << "\nIs there an edge from 1 to 0? " << (g.adjacent(1, 0) ? "Yes" : "No") << "\n";
    cout << "\nDegree of vertex 0:" << g.degree(0) << endl;
    BFS(g, 2);
    //int numberOfComponents(Graph & g, int s);
    //cout << "Number of components:"<<numberOfComponents(g, 2) << endl;
    cout << "DFS:" << endl << endl;
    DFS(g);
    printDFSResults(g);
    return 0;
}

enum Color{WHITE, BLACK,GREY};

void printDistance(const vector<int>& d){
    cout << "\nDistance vector of " << endl;
    for(int i=0 ; i<d.size() ; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0 ; i<d.size() ; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}

void printPredecessor(const vector<int>& p) {
    cout << "\nPredecessor Vector of " << endl;
    for (size_t i = 0; i < p.size(); ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (size_t i = 0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    cout  << endl;
}

void BFS(Graph& g, int s){
    vector<enum Color> color(g.V());
    vector<int> d(g.V());
    vector<int> predecessor(g.V());
    queue<int> q;
    for(int u=0 ; u<g.V() ; u++){
        color[u] = WHITE;
        d[u] = INT_MAX;
        predecessor[u] = -1;//Nan
    }
    color[s] = GREY;
    d[s] = 0;
    predecessor[s] = -1;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g.neighbors(u)){
            if(color[v] == WHITE){
                color[v] = GREY;
                d[v] = d[u] + 1;
                predecessor[v] = u;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
    printDistance(d);
    printPredecessor(predecessor);
    cout << endl;
} 

vector<enum Color> dfs_color;
vector<int> dfs_p;
vector<int> dfs_d;
vector<int> dfs_f;
int dfs_time=0;


void DFS_visit(int u, Graph& g){
    dfs_color[u]=GREY;
    dfs_time++;
    dfs_d[u]=dfs_time;
    for(int v : g.neighbors(u)){
        if(dfs_color[v]==WHITE){
            dfs_p[v]=u;
            DFS_visit(v, g);
        }
    }
    dfs_color[u]=BLACK;
    dfs_time++;
    dfs_f[u]=dfs_time;
}

void DFS(Graph& g){
    int V = g.V();
    dfs_color.assign(V, WHITE);
    dfs_d.assign(V, 0);
    dfs_f.assign(V, 0);
    dfs_p.assign(V, -1);
    dfs_time = 0;

    for(int u=0 ; u<g.V() ; u++){
        if(dfs_color[u]==WHITE){
            DFS_visit(u, g);
        }
    }
}

void printDFSResults(const Graph& g){
    cout << "\nVertex:\tDiscovery:\tFinish:\t\tPredecessor:\n";
    for(int i=0 ; i<g.V() ; i++){
        cout << i << "\t" << dfs_d[i] << "\t\t" << dfs_f[i] << "\t\t" << dfs_p[i] << endl; 
    }
}

