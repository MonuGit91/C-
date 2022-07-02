#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int> > &graph, int start, int parent, vector<bool> &visited) {
    visited[start] = true;

    for(int i = 0; i < graph[start].size(); i++) {
        int to = graph[start][i];
        
        if(!visited[to]) {
            if(dfs(graph, to, start, visited)) return true;;
        }
        else {
            if(to != parent) return true;
        }
    }
    return false;
}

bool detectCycle(vector<vector<int> > &graph, int &v) {
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(dfs(graph, i, i, visited)) return true;
        }
    }
    return false;
}

int main() {

    int v, e;
    cin >> v >> e;

    vector<vector<int> > graph(v);
    for(int i = 0; i < e; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    cout << (detectCycle(graph, v));
    return 0;
}

/*
3 2
1 2
1 3
2 3
*/