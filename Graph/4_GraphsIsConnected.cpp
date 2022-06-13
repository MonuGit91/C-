#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void IsConnected(vector< vector<bool> >&, int&);
void DFS(vector< vector<bool> >&, int&,  vector<bool>&, int);
void BFS(vector<bool>&, int&, vector<bool>&);
void check(vector<bool>&);


void check(vector<bool> &visited) {
    bool flag = true;
    for(bool flag1 : visited) {
        if(flag1 == false) {
            flag = flag1;
            break;
        }
    }

    cout << (flag ? "true" : "false") << endl;
}

void DFS(vector< vector<bool> > &graph, int &V,  vector<bool> &visited, int start) {
	for(int end = 0; end < V; end++) {
		if(graph[start][end] && visited[end] == false && start != end) {
			visited[end] = true;
			 DFS(graph, V, visited, end);
		}
	}
}

void  BFS(vector< vector<bool> > &graph, int &V, vector<bool> &visited) {
	queue<int> pending;
	pending.push(0);
	visited[0] = true;

	while(pending.size() > 0) {
		int st = pending.front();
		pending.pop();

		for(int i = 0; i < V; i++) {
			if(graph[st][i] && visited[i] == false && st != i) {
				pending.push(i);
				visited[i] = true;
			}
		}
	}
}

void IsConnected(vector< vector<bool> > &graph, int &V) {
	vector<bool> visited(V, false);

//using DFS:
	visited[0] = true;
	DFS(graph, V, visited, 0);
	check(visited);
	
//using BFS:
	visited.assign(V, false);
	BFS(graph, V, visited);
	check(visited);

}

int main()
{
	int V, E;
	cin >> V >> E;

	vector< vector<bool> > graph(V, vector<bool> (V, false));
	for(int i = 0; i < E; i++) {
		int a, b; 
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	IsConnected(graph, V);
    return 0; 
}
//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604917/problem/1697
/*
Is Connected ?
===============
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 

Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/