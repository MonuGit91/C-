#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void  findConnections(vector< vector<bool> > &graph, int &V, vector< vector<int> > &connections) {
	vector<bool> visited(V, false);
	queue<int> pending;
	int next = -1;

	for(int st = 0; st < V; st++) {
		if(!visited[st]) {
			next++;
			pending.push(st);
    		visited[st] = true;
			vector<int> sub(1, st);

    		while(pending.size() > 0) {
                 	int start = pending.front();
                    pending.pop();

                    for(int end = 0; end < V; end++) {
					if(graph[start][end] && !visited[end] && start != end) {
						sub.push_back(end);
						visited[end] = true;
						pending.push(end);
					}
				}
    		}
			connections.push_back(sub);
		}
	}
}

int main() {
	int V, E;
	cin >> V >> E;

	vector< vector<bool> > graph(V, vector<bool>(V, false));
	for(int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	vector< vector<int> > connections;
	findConnections(graph, V, connections);
	for(int i = 0; i < connections.size(); i++) {
		sort(connections[i].begin(), connections[i].end());
		for(int j : connections[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
