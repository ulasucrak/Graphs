/*
QUESTION 
20.1-1 
Given an adjacency-list representation of a directed graph, how long does it take 
to compute the out-degree of every vertex? How long does it take to compute the 
in-degrees?
*/


#include <iostream>
#include <vector>

using namespace std;

class Graph{
private:
    vector<vector<int>> adjList;
    bool isDirected;
public:
    Graph(int vertices, bool directed = false){
        adjList.resize(vertices);
        isDirected = directed;
    }

    void addEdge(int src, int dest) {
    // Ensure 'adjList' has enough buckets
        if (src >= adjList.size()) {
            adjList.resize(src + 1);
        }
        if (dest >= adjList.size()) {
            adjList.resize(dest + 1);
        }

        // Add forward edge
        adjList[src].push_back(dest);

        if(!isDirected){
            adjList[dest].push_back(src);
        }
    }

    void printGraph(){
        for(int i = 0 ; i<adjList.size() ; ++i){
            cout << i << ": ";
            for(int j=0; j<adjList[i].size(); ++j){
                cout << adjList[i][j] << " -> ";
            }
            cout << "Null" << endl;
        }
    }

    //this process takes time of O(V)
    int outDegree(int i){
        return adjList[i].size(); 
    }

    void printOutDegree(){
        for(int i=0 ; i < adjList.size() ; i++){
            cout << "Outdegree of " << i << ": " << outDegree(i) << endl;
        }
    }

    // void inDegree(){
    //     for(int i = 0 ; i<adjList.size() ; ++i){
    //         int count = 0;
    //         cout << "Indegree of " << i << ": ";
    //         for(int j = 0 ; j<adjList.size() ; ++j){
    //             for(int k=0; k<adjList[j].size(); ++k){
    //                 if(i == adjList[j][k]){
    //                     count++;
    //                 }
    //             }
    //         }
    //         cout << count << endl;
    //     }
    // }

    //this procces takes time OF o(v+e)
    vector<int> inDegree() {
        vector<int> inDeg(adjList.size(), 0);

        // For each vertex j
        for (int j = 0; j < (int)adjList.size(); ++j) {
            // For each neighbor of j
            for (int neighbor : adjList[j]) {
                inDeg[neighbor]++;
            }
        }
    
        return inDeg;
    }

    void printInDegree(){
        vector<int> inDeg = inDegree();
        for(int i=0 ; i < inDeg.size() ; i++){
            cout << "Indegree of " << i << ": " << inDeg[i] << endl;
        }
    }


};

int main(){
    int vertices = 3; // Number of vertices in the graph

    Graph undirectedGraph(vertices,true);

    undirectedGraph.addEdge(0,1);
    undirectedGraph.addEdge(0,2);
    undirectedGraph.addEdge(1,2);
    undirectedGraph.addEdge(10,9);

    cout << "Undirected Graph Adjacency List:" << endl;
    undirectedGraph.printGraph();

    undirectedGraph.printOutDegree();
    undirectedGraph.printInDegree();
    

    return 0;
}
