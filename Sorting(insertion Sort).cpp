// #include tells the preprocessor to include these header file in the program
// iostream is the header file which contains all the functions of program like cout, cin etc 

#include <iostream>
using namespace std;

//Declaration of functon
void insertionSort(int *, int);
void insertionSortRecursive(int *, int );

// Main function
int main()
{
	int i;
    int A[10];

    for(i = 0; i < 10; i++) A[i] = 10-i;

    insertionSort(A, 10);
	insertionSortRecursive(A, 10);

    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }   
    cout << endl;

    return 0;
}

// Inserstion Sort Normal
void insertionSort(int *A, int n) {
	int round, i, temp;

	for(round = 1; round < n; round++) {
		temp = A[round];
		
		for(i = round - 1; i > -1 && A[i] > temp; i--) {
			A[i+1] = A[i];
		}
		A[i+1] = temp;
	}
	return;
}

//Inserstion Sort using Recursion
void insertionSortRecursive(int *A, int n) {
	if(n == 1) return;

	insertionSortRecursive(A, n-1);
	
	int temp = A[n-1];
	int i;
	for(i = n-2; i > -1 && A[i] > temp; i--) {
		A[i+1] = A[i];
	}

	A[i+1] = temp;

	return;
}

