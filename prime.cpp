#include <iostream>
#include <cmath>
using namespace std;

class Prime {
public:
	static bool isPrime(int n) {
		if(n <= 1) return false;
		
		for(int i = 2; i < sqrt(n); i++) {
			if(n % i == 0) return false;
		}
		return true;
	}
};
int main() {
	cout << Prime::isPrime(11);
	Prime *p = new Prime();
	cout << p->isPrime(11);
	return 0;
}
