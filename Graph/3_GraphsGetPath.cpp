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

        for(int i = 0; i < V; i++) {
            if(graph[st][i] && visited->at(i) == false && st != i) {
                visited->at(i) = true;
                pending.push(i);

                path[i] = st;
                if(i == end) {
					flag = true;
					break;
				}
            }
        }
    }

    if(flag) {
        cout << end << " ";
        while(end != start) {
            cout << path[end] << " ";
            end = path[end];
        }
    }
}

void getPathBFS_matrix(bool** graph, int &V, int start, int end, vector<bool>* visited) {
	queue<int> pending;
	pending.push(start);
	visited->at(start) = true;
	bool flag = false;

	vector<int> path(V, -1);

	while(pending.size() > 0 && !flag) {
		int st = pending.front();
		pending.pop();

		for(int i = 0; i < V; i++) {
			if(graph[st][i] && visited->at(i) == false && st != i) {
				visited->at(i) = true;
				pending.push(i);

				path[i] = st;
				if(i == end) {
					flag = true;
					break;
				}

			}
		}
	}

	if(flag) {
		cout << end << " ";
		while(start != end) {
			cout << path[end] << " ";
			end = path[end];
		}
	}
}

bool getPathDFS(bool** graph, int &V, int start, int end, vector<bool>* visited) {
/*	if(start == end) return true;// */	
	if(graph[start][end]) {
		cout << end  << " ";
		 return true;
	}//*/

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
/*
9 10
0 8
1 6
1 7
1 8
5 8
6 0
7 3
7 4
8 7
2 5
3 8
get patth using DFS:
8 7 3 
get patth using BFS with matrix:
8 7 3  
get patth using BFS with map:
8 7 3 % 
*/

//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604915/problem/1696
/*
Get Path - BFS
======================
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
Print the path from v1 to v2 in reverse order.

Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
*/