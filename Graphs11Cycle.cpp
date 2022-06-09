#include <iostream>
using namespace std;

int cycle(bool** graph, int v) {
	int count = 0;
	for(int i = 0; i < v-2; i++) {
		for(int j = i+1; j < v-1; j++) {
			if(!graph[i][j]) continue;
			for(int k = j+1; k < v; k++) {
				if(!graph[j][k]) continue;
				if(graph[k][i]) count++;
			}
		}
	}
	return count;
}	

int main()
{
	while(true) {
	int v, e;
	cin >> v >> e;

	bool** graph = new bool*[v];
	for(int i = 0; i < v; i++) {
		graph[i] = new bool[v];
		for(int j = 0; j < v; j++) graph[i][j] = false;
	}

	for(int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		 graph[b][a] = true;
	}

	cout << (cycle(graph, v)) << endl;
}    return 0;
}
