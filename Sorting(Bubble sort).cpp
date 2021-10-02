#include <iostream>
using namespace std;

void BubbleSort(int A[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-1-i; j++)
		{
				if(A[j] > A[j+1]) 
				{
					int temp = A[j];
					A[j] = A[j+1];
					A[j+1] = temp;
				}
		}
	}
}

int main()
{
	int A[] = {10,9,8,7,6,5,4,3,2,1};

	BubbleSort(A, 10);

	for(int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
