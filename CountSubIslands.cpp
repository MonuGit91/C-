#include <iostream>
#include <vector>
using namespace std;

class Solution {
	private:
	//DFS traversal
	void dfs(vector<vector<int> > &grid1, vector<vector<int> > &grid2, int &m, int &n, int i, int j, bool &flag) {
		if(i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0) return;

		grid2[i][j] = 0;
		if(grid1[i][j] == 0) flag = false;
		
		dfs(grid1, grid2, m, n, i, j+1, flag);//Right
		dfs(grid1, grid2, m, n, i, j-1, flag);//Left
		dfs(grid1, grid2, m, n, i-1, j, flag);//Up
		dfs(grid1, grid2, m, n, i+1, j, flag);//Down

		return;
	}

	public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  		int m = grid1.size();
		int n = grid1[0].size();

		int count = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid1[i][j] == 1 && grid2[i][j] == 1){
					bool flag = true;
		  			dfs(grid1, grid2, m, n, i, j, flag);
				 	if(flag) count++;
				}
		  	}
		}
		return count;
    }
};

class Input {
	public:
	int m, n;
	vector<vector<int> > grid1, grid2;
	
	//parameterized constructor
	Input(int m1, int n1): grid1(m1, vector<int>(n1)), grid2(m1, vector<int>(n1)) {
		this->m = m1;
		this->n = n1;
	}

	// function for filling grids
	void fillGrid() {
		//for grid1
		for(int i = 0; i < m; i++) { 
			for(int j = 0; j < n; j++) {
				cin >> grid1[i][j];
			}
		}

		//for grid2
		for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >>  grid2[i][j];
            }
        }
	}
	//function for printing Grids
	void printGrids() {
		cout << "grid1:\n";
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cout << grid1[i][j] << " ";
			}
			cout << endl;
		}

		cout << "grid2:\n";
		for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << grid2[i][j] << " ";
            }
            cout << endl;
        }
	}
};

int main() {
	int m, n; 
	cin >> m >> n;
	
	Input obj1(m, n);
	
	obj1.fillGrid();
	obj1.printGrids();

	Solution obj2;
	cout << (obj2.countSubIslands(obj1.grid1, obj1.grid2));
	return 0;
}

/*
5 5

1 0 1 0 1
1 1 1 1 1
0 0 0 0 0
1 1 1 1 1
1 0 1 0 1

0 0 0 0 0
1 1 1 1 1
0 1 0 1 0
0 1 0 1 0
1 0 0 0 1

*/
