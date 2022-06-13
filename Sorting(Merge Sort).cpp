#include <iostream>
using namespace std;

void merge(int A[], int st, int mid, int ed)
{
	int n1 = mid - st + 1;
	int n2 = ed - mid;

	int A1[n1], A2[n2];

	int j = 0, i = 0;
	for(i = st; i <= mid; i++)
	{
		A1[j++] = A[i];
	}

	j = 0;
	for(i = mid+1; i <= ed; i++)
	{
		A2[j++] = A[i];
	}

	i = 0, j = 0;
	int k = st;
	while(i < n1 && j < n2)
	{
		if(A1[i] < A2[j])
		{
			A[k++] = A1[i++];
			continue;
		}
		A[k++] = A2[j++];
	}
	while(i < n1)
	{
		A[k++] = A1[i++];
	}
	while(j < n2)
	{
		A[k++] = A2[j++];
	}

}
void helper(int A[], int st, int ed)
{
	if(st >= ed) return;

	int mid = (st+ed)/2;

	helper(A, st, mid);
	helper(A, mid+1, ed);

	merge(A, st, mid, ed);
}
void mergeSort(int A[], int n)
{
	helper(A, 0, n-1);
}

int main()
{
	int A[] = {10,9,8,7,6,5,4,3,2,1};

	mergeSort(A, 10);

	for(int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
