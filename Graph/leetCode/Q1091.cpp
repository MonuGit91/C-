/*
//1091. Shortest Path in Binary matrixi
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> using matrix = vector<vector<T> >;

template<typename T > 
class Q1091 {
private:
	template<typename T> using matrix = vector<vector<T> >;
    int m;
    int n;

    bool valid(int i, int j, matrix<T> &grid) {
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        if(grid[i][j] == 1) return false;
        else return true;
    }   

    int bfs(matrix<T> &grid, int& direction[8][2]) {
        queue<pair<int, int> > q;
        int count = 0;
        bool flag = false;
        q.push({0, 0});

        while(!q.empty() && !flag) {
            int size = q.size();
            count++;

            while(size-- && !flag) {
                pair<int, int> index = q.front();
                q.pop();

                for(int i = 0; i < 8; i++) {
                    int r = index.first + direction[i][0];
                    int c = index.second + direction[i][1];

                    if(valid(r, c, grid)) {
                        if(r == m-1 && c == n-1) flag = true;
                        q.push({r, c});
                        grid[r][c] = 1;
                    }   
                }   
            }   
                    
        }   
        if(flag) return count;
        else return -1; 
    }   
public:
    int shortestPathBinarymatrix(matrix<T>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(n == 1 && m == 1) return 1;
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1; 
        int direction[8][2] = { 
                                {+0, +1},//E
                                {+0, -1},//W
                                {-1, +0},//N
                                {+1, +0},//S
                                {-1, +1},//NE
                                {-1, -1},//NW
                                {+1, +1},//SE
                                {+1, -1},//SW

                            };  
        return bfs(grid, direction); 
    }   
            
};

template<typename T>
class Matrix {
public:
//  template<typename T> using matrix = vector<vector<T> >;
//	matrix<int> grid;
    matrix<T> grid;
    int m, n;

    void setter() {
        cin >> m >> n;
        for(int i = 0; i < m; i++) {
            grid.push_back(vector<int>(n));
            for(int j = 0; j < n; j++) cin >> grid[i][j];
        }
    }
matrix<bool> a;
    void getter() {
        for(auto x : grid) {
            for(auto y : x) cout << y << " ";
        }
        cout << endl;
    }
};

int main() {
    Matrix<int> obj;

    obj.setter();
//  obj.getter();

    Q1091<int> objQ1019;

    cout << objQ1019.shortestPathBinarymatrix(obj.grid);

    return 0;
}
