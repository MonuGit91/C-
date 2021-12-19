
#include <iostream>
#include <queue>
using namespace std;
void printBFS(bool** edges, int v, int st, bool* visited) { //st = start
	queue<int> q; //q = priority queue
	q.push(st);
	visited[st] = true;
	
	while(!q.empty()) {
		int temp = q.front();
        q.pop();
        cout << temp << " ";;

        for(int i = 0; i < v; i++) {
            if(i == temp || visited[i]) continue;
            if(edges[temp][i]) {
                q.push(i);
				visited[i] = true;
            }   
        }
	}
	cout << endl;
}

int main() {
	int v, e;//v = vertices, e = edges
	cin >> v >> e;

	//creating 2d matrix
	bool** edges = new bool*[v];
	for(int i = 0; i < v; i++) {
		edges[i] = new bool[v];
		for(int j = 0; j < v; j++) edges[i][j] = false;
	}
	
	//storing edges
	for(int i = 0; i < e; i++) {
		int e2, e1; // e1 = edge 1, e2 = edge 2
		cin >> e1 >> e2;
		edges[e1][e2] = true;
		edges[e2][e1] = true;
	}

	//for storing alrady visited vertices
	bool* visited = new bool[v];
	for(int i = 0; i < v; i++) visited[i] = false;

	//printing edges(BFS)	
	printBFS(edges, v, 0, visited);

	// delete the memory
	for (int i = 0; i < v; i++) delete [ ] edges[i]; 
	delete [] edges;
	return 0;	
}
