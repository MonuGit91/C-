#include <iostream>
#include <queue>
using namespace std;

void BFS(bool**, int);
void helpBFS(bool**, int, int, bool*);
void DFS(bool**, int);
void helpDFS(bool**, int);

/*--------------------------------------------------------BFS-------------------------------------------------------->*/
/*
->OBJECTIVE
--------------

--->For "BFS" a loop will run untill the Q is not empty
----->inside 1st loop one more loop is there which push the children of the start
    	ie, if(graph[start][i] == true) push(i);
	
->NOTE:
-------

--->Keep a visited array and make sure all the "Component" of graph are visited. (there is "component" not "vertex")
*/


void helpBFS(bool** graph, int V, int start, bool* visited) {
    queue<int> pending;

//->push "start" inside "queue"	
    pending.push(start);

//->mark "start" as visited ie "true"
    visited[start] = true;

//->start a loop until q is not empty------->**
    while(pending.empty() == false)
    {
        int st = pending.front();
        cout << st << " ";
        pending.pop();

//-->pushing "adjacent vertices" of "start" in q------>** 
        for(int ed = 0; ed < V; ed++) {
            if(graph[st][ed] == true && visited[ed] == false) {
                pending.push(ed);
                visited[ed] = true;
            }
        }
    }
}

void BFS(bool** graph, int V) {
    bool* visited = new bool[V];

//->"mark" all vertices as not visited ie, "false"
    for(int i = 0; i < V; i++) visited[i] = false;

//  make sure that all the vertices are visited--------**
    for(int st = 0; st < V; st++) {
        if(visited[st] == false)    helpBFS(graph, V, st, visited);
    }
}


/*---------------------------------------------------------------DFS----------------------------------------------------------->*/
void helpDFS(bool** graph, int n, int start, bool* visited) {
    cout << start << " ";

 //->mark "start" as visited ie "true"
    visited[start] = true;

//->calling helpDFS in each adjacency vartices of start------** 
    for(int i = 0; i < n; i++) {
        if(graph[start][i] && !visited[i]) {
            helpDFS(graph, n, i, visited);
        }
    }
}

void DFS(bool** graph, int n) {
    bool* visited = new bool[n];

//->"mark" all vertices as not visited ie, "false"
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }

//  make sure that all the vertices are visited--------**
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            helpDFS(graph, n, i, visited);
        }
    }
}

//--------------------------------------------------------main function------------------------------------------------------------
int main() {
    int V, E; // V = vertices, E = Edges

    cin >> V >> E;

//  Making Adjacency matrix with value false
    bool** graph = new bool*[V];

    for(int i = 0; i < V; i++) {
        graph[i] = new bool[V];

        for(int j = 0; j < V; j++) graph[i][j] = false;
    }

//  Taking edges in Adjacency matrix make sure it is bydirectional edge
    for(int i = 0; i < E; i++) {
        int st, ed;

        cin >> st >> ed;
        graph[st][ed] = true;
        graph[ed][st] = true;
    }

//  calling breadth first search
   cout << "BFS: ";
   BFS(graph, V);
	
//  calling depth first search
	cout << "\nDFS: ";
	DFS(graph, V);

//  deleting graph
    for(int i = 0; i < V; i++) delete [] graph[i];
    delete [] graph;
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
BFS: 0 6 8 1 5 7 2 3 4
DFS: 0 6 1 7 3 4 8 5 2 %
*/
