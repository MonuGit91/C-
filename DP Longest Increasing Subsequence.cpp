#include <iostream>
using namespace std;

//int LIS1(int A[], int 
int main()
{
	int n;
	cin >> n;

	int A = new int[n];
	for(int i = 0; i < n; i++) cin >> A[i];

	cout << "Brute Force(longest increasing subsequence: "/ << LIS1(A, n);
	return 0;
}
