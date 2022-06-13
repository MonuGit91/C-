#include <iostream>
#include <queue>
using namespace std;

//declearing functions
bool helpBFS(bool**, int&, int&, int&, bool*);
void hasPathBFS(bool**, int&, int&, int&);
bool helpDFS(bool**, int&, int&, int&, bool*);
void hasPathDFS(bool**, int&, int&, int&);

/*-----------------------------------------------using DFS--------------------------------------------------*/

bool helpDFS(bool** graph, int &n, int &start, int &end, bool* visited) {
	if(start == end) return true;
//    if(graph[start][end]) return true;

 //->mark "start" as visited ie "true"
    visited[start] = true;

//->calling helpDFS in each adjacency vartices of start------** 
    for(int i = 0; i < n; i++) {
        if(graph[start][i] && !visited[i]) {
            if(helpDFS(graph, n, i, end, visited)) {
                return true;
            }
        }
    }
    return false;
}

//defining fhasPathDF Sunction
void hasPathDFS(bool** graph, int &V, int &v1, int &v2) {
    bool* visited = new bool[V];

//->"mark" all vertices as not visited ie, "false"
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

//  calling helpDFS
    bool flag = helpDFS(graph, V, v1, v2, visited);
    cout << (flag ? "true" : "false");
    
    delete [] visited;
}


/*-----------------------------------------------using BFS--------------------------------------------------*/

bool helpBFS(bool** graph, int &V, int &start, int &end, bool* visited) {
    queue<int> pending;

//->push "start" inside "queue" 
    pending.push(start);

//->mark "start" as visited ie "true"
    visited[start] = true;

//->start a loop until q is not empty------->**
    while(pending.empty() == false)
    {   
        int st = pending.front();
        if(graph[st][end]) return true;
        pending.pop();

//-->pushing "adjacent vertices" of "start" in q------>** 
        for(int ed = 0; ed < V; ed++) {
            if(graph[st][ed] == true && visited[ed] == false) {
                pending.push(ed);
                visited[ed] = true;
            }   
        }   
    }   
    
    return false;
}

void hasPathBFS(bool** graph, int &V, int &v1, int &v2) {
    bool* visited = new bool[V];

//->"mark" all vertices as not visited ie, "false"
    for(int i = 0; i < V; i++) visited[i] = false;

//  calling helpBFS
    bool flag = helpBFS(graph, V, v1, v2, visited);
    cout << (flag ? "true" : "false");
    
    delete [] visited;
}


//this is main function
int main() {
	int V, E; 
	cin >> V >> E;

	//makint adjacency matrix with value false
	bool** graph = new bool*[V];
	for(int i = 0; i < V; i++) {
		graph[i] = new bool[V];

		for(int j = 0; j < V; j++) {
			graph[i][j] = false;
		}
	}

	//taking edges 
	for(int i = 0; i < E; i++) {
		int v1, v2; 
		cin >> v1 >> v2;

		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}

	//taking starting and ending vertex to find the path
	int stVertex, edVertex;
	cin >> stVertex >> edVertex;

	//calling hasPath function
	hasPathBFS(graph, V, stVertex, edVertex);
	cout << endl;
	hasPathDFS(graph, V, stVertex, edVertex);

	//delting graph ie, adjacency Matrix
	for(int i = 0; i < V; i++) delete [] graph[i];
	delete [] graph;

	return 0;
}
/*
input:
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

output:
true
true  
*/

//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604911/problem/1693
/*
Has Path
=========
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.

Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false
*/