#include <iostream>
#include <queue>
using namespace std;

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
//
