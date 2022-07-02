#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T> using matrix = vector<vector<T> >;

class solutionBruteForce {
private:
	int m, n;
	int direction[4][2] = {
							{+0, +1},//E
							{+0, -1},//W
							{-1, +0},//N
							{+1, +0} //S
						  };

	void BFS(int i, int j, matrix<int> &grid) {
		matrix<bool> visited(m, vector<bool>(n, false));
		queue<pair<int, int> > q;

		q.push({i, j});
		int level = 0;
		bool flag = false;

		//for traveling matrix
		while(q.size() && !flag) {
			level++;
			int size = q.size();

			//for level wise traversal
			while(size-- && !flag){
				pair<int, int> temp = q.front();
				q.pop();

				//for traversing 4 directions of matrix
				for(int i = 0; i < 4; i++) {
					int r = temp.first + direction[i][0];
					int c = temp.second + direction[i][1];

					if(r < 0 || c < 0 || r >= m || c >= n || visited[r][c]) continue; // if current position is out of bond or visited then continue

					if(grid[r][c] == 0) flag = true;
					q.push({r, c});
					visited[r][c] = true; 
				}
			}
		}
		grid[i][j] = level;
		return;
	}

public:
	
	matrix<int> updateMatrix(matrix<int> grid) {
		m = grid.size();
		n = grid[0].size();

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == 1) BFS(i, j, grid);
			}
		}
		return grid;
	}
	
	
};

class SolutionBetter {
	int m, n;
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
    	m = mat.size();
		n = mat[0].size();
		queue<pair<int, int> > q;
		matrix<int> ans(m, vector<int>(n));

		int direction[4][2] = {
							{+0, +1},//E
							{+0, -1},//W
							{-1, +0},//N
							{+1, +0} //S
						};

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(mat[i][j] == 0) {
					q.push({i, j});
				}
			}
		}

		int level = -1;
		while(!q.empty()) {
			int size = q.size();
			level++;

			while(size--) {
				pair<int, int> temp = q.front();
				ans[temp.first][temp.second] = level;

				q.pop();
				for(int i = 0; i < 4; i++) {
					int r = temp.first + direction[i][0];
					int c = temp.second + direction[i][1];

					if(r < 0 || c < 0 || r >= m || c >= n || mat[r][c] == 0) continue;
					else {
						q.push({r, c});
						mat[r][c] = 0;
					}
				}
			}
		}
		return ans;
	}
};

//Best solution
class SolutionBest {
private:
    int m, n, maximum;

    int value(int i, int j, vector<vector<int> > &mat) {
        if(i < 0 || j < 0 || i >= m || j >= n) return 100000;
        else return mat[i][j];
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        maximum = 100000;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) continue;
                else {
                    mat[i][j] = min(value(i, j-1, mat), value(i-1, j, mat))+1;//minimum of west(<-) and north() + 1
                }
            }
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(mat[i][j] == 0) continue;
                else {
                    mat[i][j] = min(min(value(i, j+1, mat), value(i+1, j, mat))+1, mat[i][j]);
                }
            }
        }
        return mat;
    }
};

int main() {
    matrix<int> mat;
    int m; cin >> m;
    int n; cin >> n;

    for(int i = 0; i < m; i++) {
        mat.push_back(vector<int>(n));
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    solutionBruteForce obj;
    mat = obj.updateMatrix(mat);

    for(auto x : mat) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

