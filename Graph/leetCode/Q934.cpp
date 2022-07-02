#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T> using matrix = vector<vector<T> >;
int dis[4][2] = {{0, 1},{0, -1},{-1, 0},{1, 0}};
queue<pair<int, int> > q;
int m, n;


template<typename T>
void disp(matrix<T> &grid) {
	for(auto x : grid) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
}



void DFS(matrix<int> &grid, int i, int j, matrix<bool> &visited, queue<pair<int, int> > &q) {
	if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) return;

	visited[i][j] = true;
	q.push({i, j});
	
	for(int k = 0; k < 4; k++) {
		int r = dis[k][0] + i;
		int c = dis[k][1] + j;
		
		DFS(grid, r, c, visited, q);
	}
	return;
}

int BFS(matrix<int> &grid, matrix<bool> &visited) {
	int level = -1;
	bool flag = false;
	while(q.size()) {
		level++;
		int size = q.size();
		
		while(size--) {
			pair<int, int> temp = q.front();
			q.pop();

			for(int i = 0; i < 4; i++) {
				int row = temp.first + dis[i][0];
				int col = temp.second + dis[i][1];

				if(row < 0 || col < 0 || row >= m || col >= n || visited[row][col]) continue;
				
				visited[row][col] = true;
				if(grid[row][col] == 1) {
					flag = true;
					break;
				}
				q.push({row, col});
			}
			if(flag) break;
		}
		if(flag) break;
	}
	return level;	
}
int main()
{
	//declearin variables and taking values
	cin >> m >> n;
	matrix<int> grid(m, vector<int>(n));
	matrix<bool> visited(m, vector<bool>(n, false));

	//filling grid
	for(int i = 0; i < m; i++) 
		for(int j = 0; j < n; j++) cin >> grid[i][j];

	//display grid
//	disp(grid);
	
	//finding 1 in grid
	bool flag = false;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 1) {
				//calling DFS
				DFS(grid, i, j, visited, q); 
				flag = true;
				cout << BFS(grid, visited);
				break;
			}
		}
		if(flag) break;
	}
    return 0;
}
/*
2 2
1 0 
0 1

3 3
0 1 0
0 0 0
0 0 1

5 5 
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1

*/
