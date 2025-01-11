#include "graph.h"
// Test the Graph class

void printNeighbors(const vector<int> &neighbors,int s) {
    cout << "Neighbors of " << s << endl;
    for (size_t i = 0; i < neighbors.size(); ++i) {
        cout << neighbors[i] << " ";
    }
}

void BFS(Graph& g, int s);

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
    cout << "\n Degree of vertex 0:" << g.degree(0) << endl;
    BFS(g, 2);
    int numberOfComponents(Graph & g, int s);
    cout << "Number of components:"<<numberOfComponents(g, 2) << endl;
    return 0;
}

enum Color{WHITE, BLACK,GREY};

/*
WHITE if u has not been discovered
BLACK if u and all its adjacent vertices have been discovered
GRAY if u has been discovered, but has some adjacent white vertices

*/
#include <queue>

void printDistance(const vector<int>& d) {
    cout << "\nDistance Vector of " <<endl;
    for (size_t i = 0; i < d.size(); ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (size_t i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout  << endl;
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
void BFS(Graph& g, int s) {
    queue<int> q;
    vector<enum Color> color(g.V());
    vector<int> d(g.V());
    vector<int> p(g.V()); //predecessor
    for (int i = 0; i < color.size(); i++) {
        color[i] = WHITE;
        d[i] = INT_MAX;
        p[i] = -1;

    }
    color[s] = GREY;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << "-" ;
        vector<int> adj=g.neighbors(u);
        //printNeighbors(adj, u);
        for (int i = 0; i < adj.size(); i++) {
            int v = adj[i];
            if (color[v] == WHITE) {
                color[v] = GREY;
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
        color[u] = BLACK;
    }
    printDistance(d);
    printPredecessor(p);
    cout << endl;
}

int idxOfNotVisited(const vector<enum Color> &c) {
    for (int i = 0;i < c.size();i++) {
        if (c[i] == WHITE)
            return i;
    }
    return -1;
}
int numberOfComponents(Graph& g, int s) {
    queue<int> q;
    vector<enum Color> color(g.V());
    vector<int> d(g.V());
    vector<int> p(g.V()); //predecessor
    for (int i = 0; i < color.size(); i++) {
        color[i] = WHITE;
        d[i] = INT_MAX;
        p[i] = -1;

    }
    
    int idxWhite=s;
    int numberofComp = 0;
   do {
       color[idxWhite] = GREY;
       d[idxWhite] = 0;
       q.push(idxWhite);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << "-";
            vector<int> adj = g.neighbors(u);
            //printNeighbors(adj, u);
            for (int i = 0; i < adj.size(); i++) {
                int v = adj[i];
                if (color[v] == WHITE) {
                    color[v] = GREY;
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }
            color[u] = BLACK;
        }
        printDistance(d);
        printPredecessor(p);
        cout << endl;
        numberofComp++;
        idxWhite = idxOfNotVisited(color);
   } while (idxWhite != -1);
   return numberofComp;
}