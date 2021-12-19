#include <iostream>
#include <queue>
using namespace std;

void printDFS(bool** edgesMatrix, int vertices, int start, bool* visited) {
	cout << start << endl;
	visited[start] = true;

	for(int i = 0; i < vertices; i++) {
		if(i == start || visited[i]) continue;
		if(edgesMatrix[start][i]) printDFS(edgesMatrix, vertices, i, visited);
	}
}

void DFS(bool** edgesMatrix, int vertices) {
	bool* visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) visited[i] = false;
	
	for(int i = 0; i < vertices; i++) {
		if(!visited[i]) printDFS(edgesMatrix, vertices, i, visited);
	}
	delete [] visited;
}

void printBFS(bool** edgesMatrix, int vertices, int start, bool* visited) {
	queue<int> pendingQueue;
	pendingQueue.push(start);
	visited[start] = true;

	while(!pendingQueue.empty()) {
		start = pendingQueue.front();
		pendingQueue.pop();

		cout << start << endl;

		for(int i = 0; i < vertices; i++) {

			if(edgesMatrix[start][i] && !visited[i]) {
				pendingQueue.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS(bool** edgesMatrix, int vertices) {
	bool* visited = new bool[vertices];
    for(int i = 0; i < vertices; i++) visited[i] = false;

	for(int i = 0; i < vertices; i++) {
        if(!visited[i]) printBFS(edgesMatrix, vertices, i, visited);
    }
	delete [] visited;
}
//main Method
int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	//creating 2D arr to store edges
	bool** edgesMatrix = new bool*[vertices];
	for(int i = 0; i < vertices; i++) {
		edgesMatrix[i] = new bool[vertices];
		for(int j = 0; j < vertices; j++) edgesMatrix[i][j] = false;
	}

	//storing edges
	for(int i = 0; i < edges; i++) {
		int edgeStart, edgeEnd;
		cin >> edgeStart >> edgeEnd;
		edgesMatrix[edgeStart][edgeEnd] = true;
		edgesMatrix[edgeEnd][edgeStart] = true;
	}

	//BFS
	DFS(edgesMatrix, vertices);
	cout << endl;
	BFS(edgesMatrix, vertices);
	for(int i = 0; i < vertices; i++) delete [] edgesMatrix[i];
	delete [] edgesMatrix;
	return 0;
}
