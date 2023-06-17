#include <iostream>
using namespace std;

int main()
{
	for(int i = 4; i >= 0; i--) {
		for(int j = 0; j < 9; j++) {
			if(j < i) {
				cout << " ";
			}
			else{
				if(j >= i && j < 9-i) {
					cout << "*";
				}
			}
		}
		cout << endl;
	}
	for(int i = 0; i <= 4; i++) {
		for(int j = 0; j < 9; j++) {
			if(j < i) {
				cout << " ";
			}
			else{
				if(j >= i && j < 9-i) {
					cout << "*";
				}
			}
		}
		cout << endl;
	}
}
