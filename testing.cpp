#include <iostream>
//#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    priority_queue<int> values; 
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        values.push(temp);
    }

    while(q--) {
        int x, y;
        cin >> x >> y;

        int sum = 0;
        int left = x - y;
        int arr[left+1];
        int k = 0;
        for(int i = 0; i < x; i++) {
            if(left <= 0){
                arr[k++] = values.top();
                values.pop();
                sum += arr[k-1];
            }
            else {
                arr[k++] = values.top();
                values.pop();
            }
            left--;
            
        }
        cout << sum << endl;
        for(int i = 0; i < k; i++) {
            values.push(arr[i]);
        }
    }
}
/*
5 3
5 3 1 5 2
3 2
1 1
5 3

8
5
6
*/