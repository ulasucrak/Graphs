#include "Graph.h"
#include <sstream>
#include <algorithm>

Graph::Graph(int vertices) : v(vertices), e(0), adj(vertices), labels(vertices, "") {}

Graph::Graph(std::istream &in) {
    int numVertices, numEdges;
    in >> numVertices >> numEdges;

    v = numVertices;
    e = 0; // Will update as edges are added
    adj.resize(v);
    labels.resize(v, "");

    for (int i = 0; i < numEdges; ++i) {
        int x, y;
        in >> x >> y;
        add_edge(x, y);
    }
}

bool Graph::adjacent(int x, int y) const {
    return adj[x].find(y) 
}
