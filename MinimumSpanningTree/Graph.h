#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Graph{
private:
    int V_count;
    int E_count;
    vector<pair<int, int>>* adj; // Adjacency list as array of vectors
public:
    Graph(int v);
    ~Graph();
    int V() const;
    int E() const;
    void add_edge(int x, int y, int weight);
    void remove_edge(int x, int y);
    bool adjacent(int x, int y) const;
    vector<pair<int, int>> neighbors(int x) const;
    int degree(int v) const;
    string toString() const;
    void printGraph() const;

    void prims();
};