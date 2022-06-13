#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void DFS(vector<vector<bool> > &graph, int &n, int start, int next, vector<vector<int> > &connections, vector<bool> &visited) {
    for(int i = 0; i < n; i++) {
        if(graph[start][i] && !visited[i] && start != i) {
            visited[i] = true;
            connections[next].push_back(i);
            DFS(graph, n, i, next, connections, visited);
        }   
    }   
}

void BFS(vector<vector<bool> > &graph, int &n, int start, int &next, vector<vector<int> > &connections, vector<bool> &visited) {
    queue<int> pending;
    
    pending.push(start);
    visited[start] = true;
    
    while(!pending.empty()) {
        int st = pending.front();
        pending.pop();
        connections[next].push_back(st);
        
        for(int i = 0; i < n; i++) {
            if(graph[st][i] && !visited[i]) {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}
void  findConnections(vector< vector<bool> > &graph, int &V, vector< vector<int> > &connections) {
    vector<bool> visited(V, false);
    int next = -1; 

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
//            connections.push_back(vector<int>());
//             BFS(graph, V, i, ++next, connections, visited);

            connections.push_back(vector<int>(1, i));
            visited[i] = true;
            DFS(graph, V, i, ++next, connections, visited);
        }
    }   
}

int main() {
    int V, E;
    cin >> V >> E;

    vector< vector<bool> > graph(V, vector<bool>(V, false));
    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }   

    vector< vector<int> > connections;
    findConnections(graph, V, connections);
    for(int i = 0; i < connections.size(); i++) {
        sort(connections[i].begin(), connections[i].end());
        for(int j : connections[i]) {
            cout << j << " ";
        }   
        cout << endl;
    }   
    return 0;
}
//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604919/problem/1698
/*
All connected components
=========================
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Sample Input 1:
4 2
0 1
2 3

Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
0 1 3 
2
*/