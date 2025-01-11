#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

// Graph class definition
class Graph {
public:
    // Constructors
    Graph(int vertices); // Create a graph with a given number of vertices
    Graph(std::istream &in); // Read graph from an input stream

    // Graph methods
    bool adjacent(int x, int y) const; // Check if there is an edge from x to y
    std::vector<int> neighbours(int x) const; // Get all neighbors of vertex x

    void add_vertex(int x); // Add a vertex to the graph
    void remove_vertex(int x); // Remove a vertex from the graph

    void add_edge(int x, int y); // Add an edge between vertices x and y
    void set_edge_value(int x, int y, int value); // Set the value of an edge
    int get_edge_value(int x, int y) const; // Get the value of an edge

    std::string get_vertex_value(int x) const; // Get the value of a vertex
    void set_vertex_value(int x, const std::string &value); // Set the value of a vertex

    int num_vertices() const; // Get the number of vertices
    int num_edges() const; // Get the number of edges

    std::string to_string() const; // String representation of the graph

private:
    // Graph properties
    int v; // Number of vertices
    int e; // Number of edges
    std::vector<std::unordered_set<int>> adj; // Adjacency list
    std::vector<std::string> labels; // Vertex labels

    // Helper methods
    void remove_edge(int x, int y); // Remove an edge between vertices x and y
};
