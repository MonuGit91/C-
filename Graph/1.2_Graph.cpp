#include <iostream>
#include "1.1BFS.cpp"
#include "1.0DFS.cpp"
using namespace std;

int main() {
    int V, E; // V = vertices, E = Edges

    cin >> V >> E;

//  Making Adjacency matrix with value false
    bool** graph = new bool*[V];

    for(int i = 0; i < V; i++) {
        graph[i] = new bool[V];

        for(int j = 0; j < V; j++) graph[i][j] = false;
    }

//  Taking edges in Adjacency matrix make sure it is bydirectional edge
    for(int i = 0; i < E; i++) {
        int st, ed;

        cin >> st >> ed;
        graph[st][ed] = true;
        graph[ed][st] = true;
    }

//  calling breadth first search
   cout << "BFS: ";
   BFS(graph, V);

//  calling depth first search
    cout << "\nDFS: ";
    DFS(graph, V);

//  deleting graph
    for(int i = 0; i < V; i++) delete [] graph[i];
    delete [] graph;
}

/*
9 10
0 8
1 6
1 7
1 8
5 8
6 0
7 3
7 4
8 7
2 5
BFS: 0 6 8 1 5 7 2 3 4
DFS: 0 6 1 7 3 4 8 5 2 %
*///
