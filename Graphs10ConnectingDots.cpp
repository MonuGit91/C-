#include <iostream>
#include <vector>
using namespace std;

bool validity(int sides[], int n) {
	return (sides[0] >= 0 && sides[0] < n && sides[1] >= 0 && sides[1] < n);
}

int dfs(vector<vector<int> > &cake, int n, int r1, int c1, int sr1, int sc1,  int** visited, int count) {
	visited[r1][c1] = true;
	int sides[4][2] = {{r1, c1+1},{r1+1, c1},{r1, c1-1},{r1-1, c1}};

	for(int i = 0; i < 4; i++) {
		int a = sides[i][0];
		int b = sides[i][1];
		
		if(validity(sides[i], n) && cake[a][b] == cake[r1][c1]) {
			if(a == sr1 && b == sc1 && count >= 4) return count;	
			if(!visited[a][b]) count = max(count, dfs(cake, n, a, b, sr1, sc1, visited, count+1));
		}
	}
	return count;
}

int getBiggestPieceSize(vector<vector<int> > &cake, int n) {
    // Write your code here.
    int** visited = new int*[n];
    for(int i = 0; i < n; i++) {
        visited[i] = new int[n];
        for(int j = 0; j < n; j++) visited[i][j] = false;
    }
    
	int maximum = 0;
		//finding index of specific intector
		for(int r1 = 0; r1 < n; r1++) {
			for(int c1 = 0; c1 < n; c1++) {
				if(cake[r1][c1] == 1 && !visited[r1][c1]) 
					maximum = max(maximum, dfs(cake, n, r1, c1, r1, c1, visited, 1));
			}
		}
	return maximum;
}

int main() {
	while(true) {
    int n;
    cin >> n;

    vector<vector<int> > cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n) << endl;
}}
