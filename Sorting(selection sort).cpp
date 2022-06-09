#include <iostream>
using namespace std;
/*
void swap(int &a, int &b) {
    if(a == b) return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
*/
void selectionSort(int A[], int n) {
	int round, i, minValInd;

	for(round = 1; round < n; round++) {
		minValInd = round-1;

		for(i = round; i < n; i++) {
			if(A[minValInd] > A[i]) minValInd = i;
		}
		swap(A[round-1], A[minValInd]);
	}
}

int main() {
    int i;
    int A[10];

    for(i = 0; i < 10; i++) A[i] = 10-i;

    selectionSort(A, 10);

    for(int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }   
    cout << endl;

    return 0;
}
