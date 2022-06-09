#include <iostream>
using namespace std;
int groupOfIceland(bool**, int &);
void DFS(bool**, int&, int, bool[]);

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
			DFS(graph, V, start, visited);
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
