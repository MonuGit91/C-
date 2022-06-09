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

void BubbleSort(int A[], int n) {
	int round, i;
	bool flag;

	for(round = 1; round < n; round++) {
		flag = true;

		for(i = 0; i < n - round; i++) {
			if(A[i] > A[i+1]) {
				swap(A[i], A[i+1]);
				flag = false;
			}
		}

		if(flag == true) break;
	}
}
int main() {
	int i;
	int A[10];

	for(i = 0; i < 10; i++) A[i] = 10-i;

	BubbleSort(A, 10);

	for(int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}
