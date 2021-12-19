#include <iostream>
using namespace std;
int* subsequences(int *arr) {
	int* arr1 = new int[3];
	arr1[0] = arr[0];
	arr1[1] = arr[1];
	if(arr[2] == arr[0] + arr[1]) {
		arr1[2] = arr[3];
	}
	else arr1[2] = arr[2];

	return arr1;
}
int main()
{
	int testCase;
	int* arr = new int[7];

	cin >> testCase;
	while(testCase--) {
		for(int i = 0; i < 7; i++) {
			cin >> arr[i];
		}
		int* arr1 = subsequences(arr);
		for(int i = 0; i <= 2; i++) {
			cout << arr1[i] << " ";
		}
		cout << endl;
	}

    return 0;
}
