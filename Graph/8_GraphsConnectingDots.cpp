#include <iostream>
#include <vector>
using namespace std;

bool validity(int sides[], int r, int c) {
    return (sides[0] >= 0 && sides[0] < r && sides[1] >= 0 && sides[1] < c);
}

bool dfs(vector<vector<char> > &board, int r, int c, int r1, int c1, int sr1, int sc1,  bool** visited, int count) {
    visited[r1][c1] = true;
    
    int sides[4][2] = {{r1, c1+1},{r1+1, c1},{r1, c1-1},{r1-1, c1}};

    for(int i = 0; i < 4; i++) {
        int a = sides[i][0];
        int b = sides[i][1];
        
        if(validity(sides[i], r, c) && board[a][b] == board[r1][c1]) {
            if(a == sr1 && b == sc1 && count >= 4) return true;//** teaches 
    
            if(!visited[a][b] && dfs(board, r, c, a, b, sr1, sc1, visited, count+1)) return true;
        }   
    }   
//    visited[r1][c1] = false;
    return false;
}


bool hasCycle(vector<vector<char> > &board, int r, int c) {
    // Write your code here.
    bool** visited = new bool*[r];
    for(int i = 0; i < r; i++) {
        visited[i] = new bool[c];
        for(int j = 0; j < c; j++) visited[i][j] = false;
    }   
    
    for(int i = 0; i < 26; i++) {
        char find = ('A'+i);
    
        //finding index of specific charector
        for(int r1 = 0; r1 < r; r1++) {
            for(int c1 = 0; c1 < c; c1++) {
                if(board[r1][c1] == find) {
                    if(dfs(board, r, c, r1, c1, r1, c1, visited, 1)) return true;
                }   
            }   
        }   
    }   
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char> > board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}

//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604921/problem/529
/*
Connecting Dots
================
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following 

condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.

Output Format :
Print true if there is a cycle in the board, else print false.

Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
3 4
AAAA
ABCA
AAAA

Sample Output 1:
true
*/