#include <iostream>
#include <queue>
using namespace std;

int helpBFS(int** graph, int V, int start, int life, bool* visited) {
    int count = 0;
    queue<int> pending;

    pending.push(start);
    
    count++;
    visited[start] = true;

    bool flag = true;
    if(life <= 0) {
        return count;
    }

    while(pending.empty() == false && life > 0)
    {
        int st = pending.front();
        pending.pop();
        while(life--) {
            for(int ed = 0; ed < V; ed++) {
                if(graph[st][ed] == true && visited[ed] == false) {
                    pending.push(ed);
                    count++;
                    visited[ed] = true;
                }
            }
        }
        
    }

    return count;
}

int BFS(int** graph, int V, int start, int life) {
    bool* visited = new bool[V];

    for(int i = 0; i < V; i++) visited[i] = false;

    return helpBFS(graph, V, start, life, visited);
}

int limeCloud(int input1, int input2, int input3, int **input4, int input5) {
    return  BFS(input4, input2, input5, input1);
}




int main() {
    int life; cin >> life;
    int V, E; 

    cin >> V >> E;
    V++;
    int** graph = new int*[V];

    for(int i = 0; i < V; i++) {
        graph[i] = new int[V];

        for(int j = 0; j < V; j++) graph[i][j] = 0;
    }

    for(int i = 0; i < E; i++) {
        int st, ed;

        cin >> st >> ed;
        graph[st][ed] = 1;
        graph[ed][st] = 1;
    }

    int start; cin >> start;
    cout << limeCloud(life, V, E, graph, start);

}