//including header files(pre defined libraries) recognised by pre-processor
#include <iostream>
using namespace std;

//declearing DFS function
void DFS(bool**, int, int, bool*);

//this Main Function
int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	//Creating Adjacency matrices
	bool** graph = new bool*[vertices];
	for(int i = 0; i < vertices; i++) {
		graph[i] = new bool[vertices];

		for(int j = 0; j < vertices; j++) graph[i][j] = false;
	}

	//taking Adges
	for(int i = 0; i < edges; i++) {
		int st, end;
		cin >> st >> end;

		graph[st][end] = true;
		graph[st][st] = true;//****
	}
	
	//creating array list for tracking visited vertices
	bool* visited = new bool[vertices];

	//Initialising visited array as flase 
	for(int i = 0; i < vertices; i++)  visited[i] = false;
	
	
	//calling DFS for traversor 
	DFS(graph, vertices, 0, visited);

	//deleting dynamically created memories
	for(int i = 0; i < vertices; i++) delete [] graph[i];
	delete [] graph;
	delete [] visited;
	return 0;
}

//defining DFS function 
void DFS(bool** graph, int vertices, int st, bool* visited) {
    cout << st;
    visited[st] = true;

    for(int end = 0; end < vertices; end++) {
        if(st == end) continue;
        if(visited[end] == true) continue;
        if(graph[st][end] == true) DFS(graph, vertices, end, visited);
    }
    cout << endl;
}

/*
input:
8 9
0 1
1 2
2 3
3 4
4 5
4 6
5 6
6 7
7 0

output:
01234567
*/






