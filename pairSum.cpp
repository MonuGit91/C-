#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int size, int sum) {
	unordered_map<int, int> map;
	int pair = 0;
	for(int i = 0; i < size; i++) {
		map[arr[i]]++;
	}
	
	for(int i = 0; i < size; i++) {
		int remaning = sum - arr[i];
		
		if(map.count(remaning) != 0) {
			if(arr[i] == remaning) {
				int n = map[remaning]-1;
				pair += (n*(n+1))/2;

				map[remaning] = 0;
				continue;
			}

			pair += (map[arr[i]] * map[remaning]);
			map[arr[i]] = 0;
			map[remaning] = 0;
		}
	}
	return pair;
}

int main()
{
	int t; cin >> t;
	while(t--){
	int n;
	cin >> n; 
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int sum;
	cin >> sum;
	cout << pairSum(arr, n, sum);
	}
	return 0;
}
