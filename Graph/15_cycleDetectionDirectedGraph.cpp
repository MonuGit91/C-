#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int> > &graph, int start, vector<bool> &visited, vector<bool> &tempVisited) {
    visited[start] = true;
    tempVisited[start] = true;

    for(int to : graph[start]) {
        if(!visited[to]) {
            if(dfs(graph, to, visited, tempVisited)) {
                return true;
            }
        }
        else if(tempVisited[to]){
            return true;
        }
    }
    
    tempVisited[start] = false;
    return false;
}
bool hasCycle(vector<vector<int> > &graph) {
    int v = graph.size();
    vector<bool> visited(v, false);
    vector<bool> tempVisited(v, false);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            if(dfs(graph, i, visited, tempVisited)) {
                return true;
            }
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
    }

    cout << (hasCycle(graph) ? "true" : "false");
    return 0;
}