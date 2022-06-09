#include <iostream> 
#include <vector>
#include <string>
using namespace std;

//DECLARATION OF FUNCTIONS:
bool hasPath(vector< vector<char> > &, int, int); 
bool dfs(vector< vector<char> > &, int, int, int, int, bool** , int);
bool validity(int , int, int, int);

//GLOBLE VARIABLE:
const string str = "CODINGNINJA";

//DEFINING FUNCTIONS:
bool validity(int a, int b, int R, int C) {
	if(a < R && a >= 0 && b < C && b >= 0) return true;
	else return false;
}

bool dfs(vector< vector<char> > &matrix, int R, int C, int r, int c, bool** visited, int ind) {
	if(ind == 11) return true;
	visited[r][c] = true;

	int sideIndex[8][2] = {{r+1,c-1}, {r,c-1}, {r-1, c-1}, {r-1, c}, {r-1, c+1}, {r, c+1}, {r+1, c+1}, {r+1, c}};
	
	for(int i = 0; i < 8; i++) {
		int a = sideIndex[i][0];
        int b = sideIndex[i][1];
		if((validity(a, b, R, C))  
			&& (matrix[a][b] == str[ind]) 
			&& (!visited[a][b])) {
				if(dfs(matrix, R, C, a, b, visited, ind+1)) return true;
		}
	}
	visited[r][c] = false;
	return false;
}

bool hasPath(vector< vector<char> > &matrix, int R, int C) {
    bool** visited = new bool*[R];
	for(int i = 0; i < R; i++) {
        visited[i] = new bool[C];
        for(int j = 0; j < C; j++) {
             visited[i][j] = false;
        }
    }

	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			if(matrix[r][c] == 'C') {
				bool ans = dfs(matrix, R, C, r, c, visited, 1);
				if(ans) return ans;

			}
		}
	}

	return false;
}

//MAIN FUNCTION:
int main() {
//for Input:
	int R, C;
	cin >> R >> C;

	vector< vector<char> > matrix(R, vector<char>(C));
	
	for(int r = 0; r < R; r++)
		for(int c = 0; c < C; c++) 
			cin >> matrix[r][c];

//for Output:
hasPath(matrix, R, C);		
	cout << (hasPath(matrix, R, C) ? "1\n" : "0\n");
	
	return 0;	
}

