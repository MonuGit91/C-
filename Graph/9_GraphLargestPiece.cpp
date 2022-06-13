#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int direction[4][2] = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};

bool valid(int &n, int &r, int &c) {
    return (r >= 0 && c >= 0 && r < n && c < n);
}

int dfs(vector<vector<int> > &cake, int &n, int r, int c, int** visited, int count) {
    visited[r][c] = true;
    
    for(int i = 0; i < 4; i++) {
        int x = r + direction[i][0];
        int y = c + direction[i][1];
        
        if(valid(n, x, y) && cake[x][y] == 1 && !visited[x][y]) {
            count += dfs(cake, n, x, y, visited, 0); //**for each direction initialy "count" will be "0"
        }
    }

    return count+1;
    
}
int getBiggestPieceSize(vector<vector<int> > &cake, int n) {
    // Write your code here
    int** visited = new int*[n];
    
    for(int i = 0; i < n; i++) {
        visited[i] = new int[n];
        
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && cake[i][j] == 1) {
                maximum = max(maximum, dfs(cake, n, i, j, visited, 0));
            }
        }
    }
    return maximum;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int> > cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
//https://classroom.codingninjas.com/app/classroom/me/3039/content/53316/offering/604921/problem/556
/*
Largest Piece
==============
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/