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
