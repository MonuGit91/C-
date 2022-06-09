#include <iostream>
#include <queue>
using namespace std;

//declearing functions
void hasPathBFS(bool**, int&, int&, int&);
bool helpHasPathDFS(bool**, int&, int&, int&, bool*);
void hasPathDFS(bool**, int&, int&, int&);

/*-----------------------------------------------using BFS--------------------------------------------------*/

//defining helpHasPathDFS function
bool helpHasPathDFS(bool** graph, int &V, int &v1, int &v2, bool* visited) {
	if(graph[v1][v2]) return true;

	for(int i = 0; i < V; i++) {
		if(graph[v1][i] && visited[i] == false) {
			visited[i] = true;
			bool flag = helpHasPathDFS(graph, V, i, v2, visited);
			if(flag == true) {
				 return true;
			}
		}
	}
	return false;
}

//defining fhasPathDF Sunction
void hasPathDFS(bool** graph, int &V, int &v1, int &v2) {
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++) visited[i] = false;

	bool flag = helpHasPathDFS(graph, V, v1, v2, visited);
	cout << (flag ? "true" : "false");

	delete [] visited;
}

/*-----------------------------------------------using BFS--------------------------------------------------*/

//defining hasPathBFS function
void hasPathBFS(bool** graph, int &V, int &v1, int &v2) {
	bool* visited = new bool[V];

	for(int i = 0; i < V; i++) visited[i] = false;

	queue<int> pending;
	pending.push(v1);
	visited[v1] = true;
	bool flag = false;

	while(pending.size() > 0) {
		int start = pending.front();
		pending.pop();

		for(int end = 0; end < V; end++) {
			if(graph[start][end] && !visited[end]) {
				pending.push(end);	
				visited[end] = true;
				
				if(end == v2) {
					flag = true;
					break;
				}
			}
		}
		if(flag) break;
	}

	cout << (flag == true ? "true" : "false");
}

/*-----------------------------------------------using BFS--------------------------------------------------*/

//this is main function
int main() {
	int V, E; 
	cin >> V >> E;

	//makint adjacency matrix with value false
	bool** graph = new bool*[V];
	for(int i = 0; i < V; i++) {
		graph[i] = new bool[V];

		for(int j = 0; j < V; j++) {
			graph[i][j] = false;
		}
	}

	//taking edges 
	for(int i = 0; i < E; i++) {
		int v1, v2; 
		cin >> v1 >> v2;

		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}

	//taking starting and ending vertex to find the path
	int stVertex, edVertex;
	cin >> stVertex >> edVertex;

	//calling hasPath function
	hasPathBFS(graph, V, stVertex, edVertex);
	hasPathDFS(graph, V, stVertex, edVertex);

	//delting graph ie, adjacency Matrix
	for(int i = 0; i < V; i++) delete [] graph[i];
	delete [] graph;

	return 0;
}
