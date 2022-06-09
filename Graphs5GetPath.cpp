#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

//declaration of function
void getPath(bool**, int&);
bool getPathDFS(bool** , int &, int , int , vector<bool>*);
void getPathBFS_matrix(bool** , int &, int , int , vector<bool>*);
void getPathBFS_map(bool** , int &, int , int , vector<bool>*);

void getPathBFS_map(bool** graph, int &V, int start, int end, vector<bool>* visited) {
    unordered_map<int, int> path;
    queue<int> pending;
    pending.push(start);
    visited->at(start) = true;
    bool flag = false;

    //vector<vector<bool> > path(V, (vector<bool>(V, false)));

    while(pending.size() > 0 && !flag) {
        int st = pending.front();
        pending.pop();

        for(int i = 0; i < V && !flag; i++) {
            if(graph[st][i] && visited->at(i) == false && st != i) {
                visited->at(i) = true;
                pending.push(i);

                path[i] = st;
                if(i == end) flag = true;
            }
        }
    }

    if(flag) {
        cout << end << " ";
        while(path[end] != start) {
            cout << path[end] << " ";
            end = path[end];
        }
        cout << start << " ";
    }
}

void getPathBFS_matrix(bool** graph, int &V, int start, int end, vector<bool>* visited) {
	queue<int> pending;
	pending.push(start);
	visited->at(start) = true;
	bool flag = false;

	vector<vector<bool> > path(V, (vector<bool>(V, false)));

	while(pending.size() > 0 && !flag) {
		int st = pending.front();
		pending.pop();

		for(int i = 0; i < V && !flag; i++) {
			if(graph[st][i] && visited->at(i) == false && st != i) {
				visited->at(i) = true;
				pending.push(i);

				path[st][i] = true;
				if(i == end) flag = true;
			}
		}
	}

	if(flag) {
		cout << end << " ";
		for(int i = 0; i < V; i++) {
			if(path[i][end]) {
				cout << i << " ";
				end = i;
				i = -1;
			}
		}
	}
}

bool getPathDFS(bool** graph, int &V, int start, int end, vector<bool>* visited) {
	if(graph[start][end]) {
		cout << end  << " ";
		 return true;
	}

	for(int i = 0; i < V; i++) {
		if(graph[start][i] && visited->at(i) == false) {
			visited->at(i) = true;
			bool flag = getPathDFS(graph, V, i, end, visited);
			if(flag) {
				cout << i << " ";
				return true;
			}
		}
	}
	return false;
 }

//defining function
void getPath(bool** graph, int &V) {
	int start, end;	
	cin >> start >> end;
	
	vector<bool>* visited = new vector<bool>(V, false);

cout << "get patth using DFS:\n";
	bool flag = getPathDFS(graph, V, start, end, visited);
	if(flag) cout << start;

cout << " \nget patth using BFS with matrix:\n";
	visited->assign(V, false); 
	getPathBFS_matrix(graph, V, start, end, visited);

cout << " \nget patth using BFS with map:\n";
	 visited->assign(V, false);
	 getPathBFS_map(graph, V, start, end, visited);
}

int main()
{
	int V, E; 
	cin >> V >> E;

	//making adjacency matrix with value false
	bool** graph = new bool*[V];
	for(int i = 0; i < V; i++) {
		graph[i] = new bool[V];

		for(int j = 0; j < V; j++) graph[i][j] = false;
	}

	//Taking Edges
	for(int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}

	//calling getPath function
	getPath(graph, V);
    return 0;
}
