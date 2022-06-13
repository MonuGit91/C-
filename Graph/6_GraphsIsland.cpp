#include <iostream>
#include <queue>
using namespace std;
int groupOfIceland(bool**, int &);
void DFS(bool**, int&, int, bool[]);

void BFS(bool** graph, int &n, int &start, bool visited[]) {
	queue<int> pending;

	pending.push(start);
	visited[start] = true;

	while(!pending.empty()) {
		int st = pending.front();
		pending.pop();

		for(int i = 0; i < n; i++) {
			if(graph[st][i] && !visited[i] && i != st) {
				visited[i] = true;
				pending.push(i);
			}
		}
	}
}

void DFS(bool** graph, int &V, int start, bool visited[]) {
	visited[start] = true;

	for(int end = 0; end < V; end++) {
		if(graph[start][end] && !visited[end] && start != end) {
			DFS(graph, V, end, visited);
		}
	}
}

int groupOfIceland(bool** graph, int &V) {
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++) visited[i] = false;

	int count = 0;
	for(int start = 0; start < V; start++) {
		if(!visited[start]) {
//			DFS(graph, V, start, visited);
			BFS(graph, V, start, visited);
			count++;
		}
	}
	delete [] visited;
	return count;
}

int main()
{
	int V, E;
	cin >> V >> E;

	bool** graph = new bool*[V];
	for(int i = 0; i < V; i++) {
		graph[i] = new bool[V]();
			for(int j = 0; j < V; j++) 
	    	graph[i][j] = false;
	}


	for(int i = 0; i < E; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	cout << groupOfIceland(graph, V) << endl;
	
	for(int i = 0; i < V; i++) delete [] graph[i];
	delete [] graph;
    return 0;
}
//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604921/problem/555
/*
Islands
=========
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 

Output Format :
Print the count the number of connected groups of islands

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3

Sample Output 1:
1 
*/