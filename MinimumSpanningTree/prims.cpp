#include "Graph.h"

int main(){
    Graph g(5); // Create a graph with 5 vertices

    g.add_edge(0, 1, 9);
    g.add_edge(0, 2, 5);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 4 ,5);
    g.add_edge(2, 3, 4);
    g.add_edge(2, 4, 5);
    g.add_edge(3, 4, 4);


    cout << "adjacent 3-4:" + to_string(g.adjacent(3,5));
    cout << "Graph representation:\n";
    cout << g.toString();

    cout << "\nRunning Prim's algorithm...\n";
    g.prims();
}
