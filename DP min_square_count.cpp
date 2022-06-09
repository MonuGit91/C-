#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;


int minSquareCount1(int n)
{
//	if(n == 0) return 0;
	
	int min_count = INT_MAX;
	for(int i = 1; i <= sqrt(n); i++)
	{
		int count = minSquareCount1(n - (i*i));
		min_count = min(min_count, count);
	}
	
	return (min_count + 1);
}

int helpMinSquareCount2(int n, vector<int> *arr)
{
	if(n == 0) return 0;

	if(arr->at(n) != -1) return arr->at(n);

	int min_count = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++)
        {       
		int count = helpMinSquareCount2(n - (i*i), arr);
                min_count = min(min_count, count);
        }
	
	arr->at(n) = min_count + 1;
        return arr->at(n);
}

int minSquareCount2(int n)
{
	vector<int> *arr = new vector<int>(n+1);

	arr->at(0) = 0;
	for(int i = 1; i <= n; i++) arr->at(i) = -1;
	 
	return helpMinSquareCount2(n, arr); 
}


int minSquareCount3(int n)
{
	vector<int> A(n+1);
	
	A[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int small = INT_MAX;
		for(int j = 1; j <= sqrt(i); j++)
		{
			small = min(small, A[i - (j*j)]);
		}
		
		A[i] = small + 1;
	} 
	
	return A[n];
}

int main()
{
	int n;
	
	cout << "Enter number: ";
	cin >> n;

//Brute Force:
	cout << "Brute Force: " << minSquareCount1(n) << endl;

//Memoization: 
	cout << "Memoization: " << minSquareCount2(n) << endl;

//Dynamically:
	cout << "Dynamically: " << minSquareCount3(n) << endl;
}
