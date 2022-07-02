#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
/*
//-----------------------------------------Using Adjacency matrix----------------------------------
int findMinWeightVertex(int* distance, bool* visited, int &v) {
	int minWeightVertex = -1;
	for(int i = 0; i < v; i++) {
		if(!visited[i] && (minWeightVertex == -1 || distance[i] < distance[minWeightVertex])) {
			minWeightVertex = i;
		}
	}

	return minWeightVertex;
}

void dijkstra(int** graph, int &v, int &e) {
	bool* visited = new bool[v];
	int* distance = new int[v];
	
	for(int i = 0; i < v; i++) {
		visited[i] = false;
		distance[i] = INT_MAX;
	}
	distance[0] = 0;

	for(int i = 0; i < v-1; i++) {
		int from = findMinWeightVertex(distance, visited, v);
		visited[from] = true;

		for(int j = 0; j < v; j++) {
			if(!visited[j] && graph[from][j] != -1) {
				int dist = graph[from][j] + distance[from];
				if(dist < distance[j]) {
					distance[j] = dist;
				}
			}
		}
	}

	for(int i = 0; i < v; i++) {
		cout << i << " " << distance[i] << endl;
	}


}

int main() {
    int v, e;//v: no of vertices, e: no of edges
    cin >> v >> e;

    //"Making adjacency matrix for graph\n";
    int** graph = new int*[v];
    for(int i = 0; i < v; i++) {
        graph[i] = new int[v];
        
        for(int j = 0; j < v; j++) {
            graph[i][j] = -1;
        }
    }

    //"Taking Edges of graph\n";
    for(int i = 0; i < e; i++) {
		int src, dst, wt; //src: source, dst: distance, wt: weight
            
      	cin >> src >> dst >> wt;
        graph[src][dst] = wt;
        graph[dst][src] = wt;
    }

    dijkstra(graph, v, e);

	for(int i = 0; i < v; i++) {
		delete graph[i];
	}
	delete [] graph;

    return 0;
}
// */

//----------------------------------------------Using Adjacency Matrix(vector)---------------------
/*
int findMinWeightedVertex(vector<int> &distance, vector<bool> &visited, int &v) {
	int minWeightVertex = -1;
	for(int i = 0; i < v; i++) {
		if(!visited[i] && (minWeightVertex == -1 || distance[i] < distance[minWeightVertex])) {
			minWeightVertex = i;
		}
	}
	return minWeightVertex;
}

void dijkstra(vector<vector<int> > &graph, int &v) {
	vector<bool> visited(v, false);
	vector<int> distance(v, INT_MAX);

	distance[0] = 0;
	for(int i = 0; i < v-1; i++) {
		int from = findMinWeightedVertex(distance, visited, v);
		visited[from] = true;

		for(int j = 0; j < v; j++) {
			if(!visited[j] && graph[from][j] != 0) {
				int temp = graph[from][j] + distance[from];
				if(temp < distance[j]) {
					distance[j] = temp;
				}
			}
		}
	}

	for(int i = 0; i < v; i++) {
		cout << i << " " << distance[i] << endl;
	}
}

int main() {
	int v, e; cin >> v >> e;
	vector<vector<int> > edges(v, vector<int> (v, 0));
	
	for(int i = 0; i < e; i++) {
		int src, dst, weight;
		cin >> src >> dst >> weight;

		edges[src][dst] = weight;
		edges[dst][src] = weight;
	}

	dijkstra(edges, v);
	return 0;
}
*/
//--------------------------------------------Using edgelist and priority queue----------------------

using MinQ =  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >;// *

void dijkstra(vector<vector<pair<int, int> > > &graph, int &v) {
	vector<bool> visited(v, false);
	vector<int> distance(v, INT_MAX);
	
	distance[0] = 0;
	MinQ minQ;
	minQ.push(make_pair(0, 0)); // push({0, 0})

	for(int i = 0; i < v-1; i++) {
		int from = minQ.top().second;	
		minQ.pop();
		visited[from] = true;

		for(int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j].first;
			int wt = graph[from][j].second;
			
			if(!visited[to]){
				int dist = distance[from] + wt;
				
				if(distance[to] > dist){
					distance[to] = dist;
					minQ.push(make_pair(dist, to));//push({dist, to});
				}
			}
		}
	}

	for(int i = 0; i < v; i++) {
		cout << i <<  " " << distance[i] << endl;
	}
}

void printGraph(vector<vector<pair<int, int> > > &graph) {
	for(int i = 0; i < graph.size(); i++) {
		for(int j = 0; j < graph[i].size(); j++) {
			cout << i << "->" << graph[i][j].first << ": " << graph[i][j].second << endl;
		}
	}
}

int main() {
	int v, e;
	cin >> v >> e;

	vector<vector<pair<int, int> > > graph(v);
	for(int i = 0; i < e; i++){
		int src, dst, wt;
		cin >> src >> dst >> wt;

		graph[src].push_back(make_pair(dst, wt)); // *
		graph[dst].push_back(make_pair(src, wt)); // * push_back({src, wt});
	}
//	printGraph(graph);

	dijkstra(graph, v);
	return 0;
}
// */
/*
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/
