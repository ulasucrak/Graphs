#include "Graph.h"

Graph::Graph(int v) : V_count(v), E_count(0){
    adj = new vector<pair<int,int>>[v];
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

void Graph::add_edge(int x, int y, int weight){
    if(x<V_count && y<V_count){
        adj[x].push_back({y, weight});
        adj[y].push_back({x, weight}); //if undirected
        E_count++;
    }
}

void Graph::remove_edge(int x, int y){
    if(x<V_count && y<V_count){
        adj[x].erase(remove_if(adj[x].begin(), adj[x].end(), [y](const pair<int, int>& p) {return p.first == y;}), adj[x].end());
        adj[y].erase(remove_if(adj[y].begin(), adj[y].end(),
                               [x](const pair<int, int>& p) { return p.first == x; }),
                     adj[y].end());
    }
}

bool Graph::adjacent(int x, int y) const{
    if(x<V_count && y<V_count){
        for(int i=0 ; i<adj[x].size() ; i++){
            if(adj[x][i].first == y){
                return 1;
            }
        }
    }
    return 0;
}

vector<pair<int, int>> Graph::neighbors(int x) const{
    if(x<V_count){
        return adj[x];
    }
    return vector<pair<int, int>>();
}

int Graph::degree(int v) const{
   return adj[v].size();
}

string Graph::toString() const{
    string s;
    for(int i=0 ; i<V_count ; i++){
        s = s + to_string(i) + ": ";
        for(const auto& p : adj[i]){
            s += "(" + to_string(p.first) + ", " + to_string(p.second) + ") -> ";
        }
        s+= "NULL\n";
    }
    return s;
}

void Graph::printGraph() const{
    for(int i=0 ; i<V_count ; i++){
        cout << i << ": ";
        for (const auto& p : adj[i]){
            cout << "(" << p.first << ", " << p.second << ") -> ";
        }
        cout << "NULL" << endl;
    }
}

void Graph::prims(){
    // Step 1: Initialization
    vector<int> d(V_count, INT_MAX); // Distances to tree
    vector<int> parent(V_count, -1); // Parent array
    vector<bool> inMST(V_count, false); // MST inclusion flag
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap
    
    int r = 0; // Choose the root vertex
    d[r] = 0;
    pq.push({0, r}); // Insert root with distance 0

    // Step 2: Main loop
    while (!pq.empty()) {
        int u = pq.top().second; // Get vertex with minimum distance
        pq.pop();

        // If already in MST, skip
        if (inMST[u]) continue;

        inMST[u] = true; // Include vertex in MST

        // Step 3: Update distances for neighbors
        for (auto &edge : adj[u]) {
            int v = edge.first;  // Neighbor vertex
            int weight = edge.second; // Edge weight

            if (!inMST[v] && weight < d[v]) {
                d[v] = weight; // Update distance
                parent[v] = u; // Update parent
                pq.push({d[v], v}); // Push updated distance
            }
        }
    }

    // Step 4: Output MST
    cout << "Minimum Spanning Tree (MST):" << endl;
    for (int i = 1; i < V_count; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " : " << d[i] << endl;
        }
    }
}