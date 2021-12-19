#include <iostream>
using namespace std;

int* arrInput(int n)
{
	int *arr = new int[n];
	
	for(int i = 0; i < n; i++) cin >> arr[i];

	return arr;
}

int knapsack1(int *wt, int *val, int n, int w)
{
	if(n == 0 || w == 0) return 0;

	if(wt[n-1] > w) return knapsack1(wt, val, n-1, w);

	int max_val1 = val[n-1] + knapsack1(wt, val, n-1, w - wt[n-1]);
	int max_val2 = knapsack1(wt, val, n-1, w);

	return max(max_val1, max_val2);
}



int helpKnapsack2(int* wt, int* val, int n, int w, int** A)
{
	if(n == 0 || w == 0)
	{
		A[n][w] = 0;
		return A[n][w];
	}

	if(A[n][w] != -1) return A[n][w];

	if(wt[n-1] > w)
	{
		A[n][w] = helpKnapsack2(wt, val, n-1, w, A);
		return A[n][w];
	}

	int max_val1 = val[n-1] + helpKnapsack2(wt, val, n-1, w - wt[n-1], A);
	int max_val2 = helpKnapsack2(wt, val, n-1, w, A);

	A[n][w] = max(max_val1, max_val2);
	return A[n][w];
	
}

int kanpsack2(int *wt, int *val, int n, int w)
{
	int **A = new int*[n+1];
	
	for(int i = 0; i <= n; i++)
	{
		A[i] = new int[w+1];
		for(int j = 0; j <= w; j++) A[i][j] = -1;
	}

	return helpKnapsack2(wt, val, n, w, A);
}


int knapsack3(int* wt, int* val, int n, int w)
{
	int **A = new int*[n+1];

    for(int i = 0; i <= n; i++)
    {
        A[i] = new int[w+1];
        for(int j = 0; j <= w; j++)
		{
			if(i == 0 || j == 0) A[i][j] = 0;
			else A[i][j] = -1;
		}
    }


	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= w; j++)
		{
		    if(wt[i-1] > j)
		    {
		        A[i][j] = A[i-1][j];
		        continue;
		    }
		
		    int max_val1 = val[i-1] + A[i-1][j - wt[i-1]];
		    int max_val2 = A[i-1][j];
		
		    A[i][j] = max(max_val1, max_val2);
		    continue;
		}

		return A[n][w];
}

int main()
{
	int n; cin >> n;

	int *wt = arrInput(n);
	int *val = arrInput(n);

	int w; cin >> w;

	cout << "Knapsack Maximum value(brute Force): " << knapsack1(wt, val, n, w) << "\n";
	cout << "Knapsack Maximum value(memoization): " << kanpsack2(wt, val, n, w) << "\n";
	cout << "Knapsack Maximum value(Dynamically): " << knapsack3(wt, val, n, w) << "\n";

	return 0;
}
