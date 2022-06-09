#include <iostream>	
using namespace std;

void upperStar(int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n*2-1+i; j++) {
			if(j < 2*n-1-i-1) cout << " ";
			else cout << "*";
		}cout << endl;
	}
}

void upperMidStar(int n) {
	for(int i = 0; i < n; i++) {
		for(int  j = 0; j < 3*n - i; j++) {
			if(j < i) cout << " ";
			else {
				cout << "*";
			}
		}cout << endl;
	}
}

void lowerStar(int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < 2*n-i; j++) {
			if(j < n+i) cout << " ";
			else cout << "*";
		}cout << endl;
	}
}

void lowarMidStar(int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < (2*n+1)+1+i; j++) {
			if(j < n-2-i) cout << " ";
			else cout << "*";
		}cout << endl;
	}
}

int main() {
	upperStar(3);
	upperMidStar(3);
	lowarMidStar(3);
	lowerStar(3);
}
