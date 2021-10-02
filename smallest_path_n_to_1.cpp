#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int smallestPathBruteForce(int n)
{
	if(n == 1) return 0;
	
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;

	a = smallestPathBruteForce(n-1);
	if(n % 2 == 0) b = smallestPathBruteForce(n / 2);
	if(n % 3 == 0) c = smallestPathBruteForce(n / 3);

	int ans = min(a, min(b, c)) + 1;
	return ans;
}

int helpSmallestPathMemoization(int n, vector<int>* arr)
{
	if(n == 1) return 0;
	if(arr->at(n) != -1) return arr->at(n);
	
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;

	if(n % 1 == 0)
	{
		if(arr->at(n-1) != -1)	a = arr->at(n-1);
		else	a = helpSmallestPathMemoization(n-1, arr);
	}
        if(n % 2 == 0)
	{
		if(arr->at(n/2) != -1) b = arr->at(n/2);
		else	b = helpSmallestPathMemoization(n / 2, arr);
	}
        if(n % 3 == 0)
	{
		if(arr->at(n/3) != -1) c = arr->at(n / 3);
 		else	c = helpSmallestPathMemoization(n / 3, arr);
	}

	int ans = min(a, min(b, c)) + 1;
	arr->at(n) = ans;

	return ans;
}

int smallestPathMemoization(int n)
{
	vector<int>* arr = new vector<int>(n+1);
	
	for(int i = 0; i < n+1; i++) arr->at(i) = -1;
	int ans = helpSmallestPathMemoization(n, arr);
	return ans;
}

int smallestPatDynamiclly(int n)
{
	vector<int> arr(n+1);
	arr.at(1) = 0;
	for(int i = 2; i <= n; i++)
	{
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;

		if(i % 1 == 0) a = arr[i-1];
		if(i % 2 == 0) b = arr[i/2];
		if(i % 3 == 0) c = arr[i/3];
		
		arr[i] = (min(a, min(b, c)) + 1);
	}	
	return arr[n];
}
int main()
{
	int n, t;

	cout << "enter no of test cases: ";
	cin >> t;
	while(t--)
	{
		cout << "Enter number: ";
		cin >> n;
	
		cout << "smallest path is(brute_force): " << smallestPathBruteForce(n) <<  endl;
		cout << "smallest path is(memoization): " << smallestPathMemoization(n) << endl;
		cout << "smallest path is(dynamiclly):  " << smallestPatDynamiclly(n) << endl << endl;
	}
	return 0;
}
