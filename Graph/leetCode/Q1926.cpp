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

int nearestExit(matrix<char> &grid, int i, int j, matrix<bool> visited) {
	int level = 0;
	q.push({i, j});

	while(q.size()) {
		level++;
		int size = q.size();
		while(size--) {
			pair<int, int> temp = q.front();
			q.pop();

			for(int k = 0; k < 4; k++) {
				int r = temp.first + dis[k][0];
				int c = temp.second + dis[k][1];

				if(r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || grid[r][c] == '+' || (r == i && c == j)) continue;
				
				visited[r][c] = true;
				q.push({r, c});
				
				if((r == 0 || r == m-1) || (c == 0 || c == n-1)) 
				{
					cout << r << " " << c << endl;
					return  level;
				}
			}
		}
	}
	return -1;
}

int main()
{
	//declearin variables and taking values
	cin >> m >> n;
	matrix<char> grid(m, vector<char>(n));
	matrix<bool> visited(m, vector<bool>(n, false));

	//filling grid
	for(int i = 0; i < m; i++) 
		for(int j = 0; j < n; j++) cin >> grid[i][j];

	//display grid
//	disp(grid);
	
	//solution
	int i, j; cin >> i >> j;
	cout << nearestExit(grid, i, j, visited);

    return 0;
}

/*
1926. Nearest Exit from Entrance in Maze

3 4
+ + . +
. . . +
+ + + .
1 2
-->yes

3 3
+ + +
. . .
+ + +
1 0
-->yes

1 2
. +
0 0

5 7
+ . + + + + +
+ . + . . . +
+ . + . + . +
+ . . . + . +
+ + + + + . +
0 1
-->12
*/
