#include <iostream>
using namespace std;

void merge(int arr[], int n, int arrL[], int l, int arrR[], int r) {
	int i = 0, j = 0, k = 0;
		
	while(i < l && j < r) {
		if(arrL[i] < arrR[j]) {
			arr[k++] = arrL[i++];
		}
		else {
			arr[k++] = arrR[j++];
		}
	}
	while(i < l) {
		arr[k++] = arrL[i++];
	}
	while(j < r) { 
		arr[k++] = arrR[j++];
	}
}


void mergeSort(int arr[], int n) {
	if(n == 1) return;
	int mid = n/2;
	int arrL[mid];
	int arrR[n-mid];
		
	for(int i = 0; i < mid; i++) {
		arrL[i] = arr[i];
	}
	for(int i = 0; i < n-mid; i++) {
		arrR[i] = arr[mid+i];
	}
		
	mergeSort(arrL, mid);
	mergeSort(arrR, n-mid);
		
	merge(arr, n, arrL, mid, arrR, n-mid);	
}

void print(int* arr, int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++) cin >> arr[i];

	mergeSort(arr, n);
	print(arr, n);
	return 0;
}
/*
9
9 8 7 6 5 4 3 2 1
*/