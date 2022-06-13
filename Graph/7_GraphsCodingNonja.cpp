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

bool dfs(vector< vector<char> >  &matrix, int R, int C, int r, int c, bool** visited, int ind) {
	if(ind == 11) return true;
	
	visited[r][c] = true;
    
	bool ans = false;

	int sideIndex[8][2] = {{+1,-1}, {0,-1}, {-1, -1}, {-1, 0}, {-1, +1}, {0, +1}, {+1, +1}, {+1, 0}};
	
	for(int i = 0; i < 8; i++) {
		int a = r+sideIndex[i][0];
        int b = c+sideIndex[i][1];
		if((validity(a, b, R, C))  
			&& (matrix[a][b] == str[ind]) 
			&& (!visited[a][b])) {
				ans = ans | dfs(matrix, R, C, a, b, visited, ind+1);
				if(ans) return true;
		}
	}
   visited[r][c] = false;//**
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

//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604921/problem/528
/*
Coding Ninjas
==============
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output 1:
1
*/