#include <iostream>
using namespace std;

void helpDFS(bool** graph, int n, int start, bool* visited) {
    cout << start << " ";

 //->mark "start" as visited ie "true"
    visited[start] = true;

//->calling helpDFS in each adjacency vartices of start------** 
    for(int i = 0; i < n; i++) {
        if(graph[start][i] && !visited[i]) {
            helpDFS(graph, n, i, visited);
        }   
    }   
}

void DFS(bool** graph, int n) {
    bool* visited = new bool[n];

//->"mark" all vertices as not visited ie, "false"
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }   

//  make sure that all the vertices are visited--------**
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            helpDFS(graph, n, i, visited);
        }   
    }   
}

/*
input:-
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

output:
DFS: 0 6 1 7 3 4 8 5 2
*/
