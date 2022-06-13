#include <iostream>	
using namespace std;

void upperStar(int n) {
	int baseOfStar = 1;
	for(int i = 2; i <= n; i++) baseOfStar += 2;
	int midOfBase = baseOfStar/2+1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n+midOfBase+i; j++) {
			if(j < n+midOfBase-i-1) cout << " ";
			else cout << "*";
		}cout << endl;
	}
}

void upperMidStar(int n) {
	int baseOfStar = 1;
	for(int i = 2; i <= n; i++) baseOfStar += 2;

	for(int i = 1; i < n; i++) {
		for(int  j = 0; j < 2*n + baseOfStar - i; j++) {
			if(j < i) cout << " ";
			else {
				cout << "*";
			}
		}cout << endl;
	}
}

void lowerStar(int n) {
	int baseOfStar = 1;
	for(int i = 2; i <= n; i++) baseOfStar += 2;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n+baseOfStar-i; j++) {
			if(j < n+i) cout << " ";
			else cout << "*";
		}cout << endl;
	}
}

void lowarMidStar(int n) {
	int baseOfStar = 1;
	for(int i = 2; i <= n; i++) baseOfStar += 2;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (n+baseOfStar)+i; j++) {
			if(j < n-i) cout << " ";
			else cout << "*";
		}cout << endl;
	}
}

int main() {
	int n = 5;
	upperStar(n);
	upperMidStar(n);
	lowarMidStar(n);
	lowerStar(n);
}
