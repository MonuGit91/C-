#include <iostream>
#include <climits>
using namespace std;
//function for finding minimum weighted vertex
int findMinWeightVertex(int* weight, bool* visited, int v) {
	int minVertex = -1;
	for(int i = 0; i < v; i++) {
		if(!visited[i] && (minVertex == -1 || (weight[i] < weight[minVertex]))) {
			minVertex = i;
		}
	}

	return minVertex;
}

void prims(int** graph, int v, int e) {
	bool visited[v];
	int parent[v];
	int weight[v];

	//initializing witght with infinity
	for(int i = 0; i < v; i++) {
		visited[i] = false;
		weight[i] = INT_MAX;	
	}

	//taking 0 as root
	parent[0] = -1;
	weight[0] = 0;

	//pick a vertex with minimum weighted vertex and compair with it's edge weight and update
	for(int i = 0; i < v; i++) {
		int minVertex = findMinWeightVertex(weight, visited, v);
		visited[minVertex] = true;

		//exploring neighbours of min weighted vertex
		for(int j = 0; j < v; j++) {
			if(graph[minVertex][j] != 0 && !visited[j] && graph[minVertex][j] < weight[j]) {
				weight[j] = graph[minVertex][j];
				parent[j] = minVertex;
			}
		}
	}

	//pring prims 
	for(int i = 0; i < v; i++) {
		if(parent[i] == -1) continue;

		if(parent[i] < i) {
			cout << parent[i] << " " << i << " " << weight[i] << endl;
		}
		else {
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}
}

int main() {
	int v, e;
	cin >> v >> e;

	//making adgacency matrix
	int** graph = new int*[v];
	for(int i = 0; i < v; i++) {
		graph[i] = new int[v];

		for(int j = 0; j < v; j++) {
			graph[i][j] = 0;
		}
	}
	
	//taking adges
	for(int i = 0; i < e; i++) {
		int source, destination, weight;
		cin >> source >> destination >> weight;
		graph[source][destination] = weight;
		graph[destination][source] = weight;
	}
	
	//call prims function
	prims(graph, v, e);

	//free space
	for(int i = 0; i < v; i++) {
		delete [] graph[i];
	}
	delete [] graph;

	return 0;
}
