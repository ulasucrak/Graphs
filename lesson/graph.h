#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {
private:
    int V_count;         // Number of vertices
    int E_count;         // Number of edges
    vector<int>* adj;    // Adjacency list as array of vectors

public:
    // Constructs a V-vertex graph with no edges
    Graph(int V);

    // Constructs a graph by reading from a file
    Graph(const string& filename);

    // Destructor: clean up dynamic memory
    ~Graph();

    // Returns the number of vertices
    int V() const;

    // Returns the number of edges
    int E() const;

    // Adds an edge between vertices x and y
    void add_edge(int x, int y);

    // Removes the edge between vertices x and y
    void remove_edge(int x, int y);

    // Checks if there is an edge from x to y
    bool adjacent(int x, int y) const;

    // Returns a list of neighbors (adjacent vertices) of x
    vector<int> neighbors(int x) const;

    // Returns the degree of vertex v
    int degree(int v) const;

    // Returns a string representation of the graph
    string toString() const;
};
