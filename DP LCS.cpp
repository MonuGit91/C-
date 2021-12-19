#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS_1(string s1, string s2, int m, int n)
{
	if(m == 0 || n == 0) return 0;

	if(s1[0] == s2[0])
	{
		int ans = 1 + LCS_1(s1.substr(1), s2.substr(1), m-1, n-1);
		return ans;
	}

	int ans1 = LCS_1(s1.substr(1), s2, m-1, n);
	int ans2 = LCS_1(s1, s2.substr(1), m, n-1);
	int ans = max(ans1, ans2);
	return ans;
}

int helpLCS_2(string s1, string s2, int m, int n, vector<vector<int>*>* A)
{
    if(m == 0 || n == 0) return 0;

	if(A->at(m)->at(n) != -1) return A->at(m)->at(n);

    if(s1[0] == s2[0])
    {   
        int ans = 1 + helpLCS_2(s1.substr(1), s2.substr(1), m-1, n-1, A);
		A->at(m)->at(n) = ans;
        return ans;
    }   

    int ans1 = helpLCS_2(s1.substr(1), s2, m-1, n, A); 
    int ans2 = helpLCS_2(s1, s2.substr(1), m, n-1, A);
    int ans = max(ans1, ans2);
	A->at(m)->at(n) = ans;
    return ans;
}

int LCS_2(string s1, string s2, int m, int n)
{
	vector<vector<int>*>* A = new vector<vector<int>*>(m+1);
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n+1; j++) A->at(i) = new vector<int>(n+1, -1);
	}

	return helpLCS_2(s1, s2, m, n, A);
}

int LCS_3(string s1, string s2, int m, int n)
{
	int row = m+1;
	int column = n+1;
	vector<vector<int>> A(row, vector<int>(column, 0));

	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < column; j++)
		{
			if(s1[row-i] == s2[column-j]) A[i][j] = 1 + A[i-1][j-1];
			else
			{
				A[i][j] = max(A[i-1][j], A[i][j-1]);
			}
		}
	}
	return A[m][n];
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	cout << "LCS(Brute force): " << LCS_1(s1, s2, s1.size(), s2.size()) << endl;
	cout << "LCS(Memoization): " << LCS_2(s1, s2, s1.size(), s2.size()) << endl;
 	cout << "LCS(Dynamically): " << LCS_3(s1, s2, s1.size(), s2.size()) << endl;
	
}
