#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Q1 {
	public:
	int n;
	int min, max;

	Q1() {
		min = INT_MAX;
		max = INT_MIN;
	}

	void setter() {
		cin >> n;
		for(int i = 0; i < n; i++) {
			int temp; 

			cin >> temp;
			
			if(temp >= max) max = temp;
			if(temp <= min) min = temp;
		}
	}

	int minOpe() {
   	    return (max - min);
   	}   

};

class Q2 {
	private:
	int a, b, c;

	public:
	Q2() {

	}

	void setter() {
		cin >> this->a >> this->b >> this->c;
	}

	string makeAp() {
//		if(b-a == c - b) return "YES";
//		if(((a + c) % (2*b)) == 0) return "YES";
//		if((2*b - c) > 0 && ((2*b - c) % a) == 0) return "YES";
//		if((2*b - a) > 0 && ((2*b - a) % c) == 0) return "YES";

		if(b-a == c - b) return "YES";
		if(((a + c) % (2*b)) == 0) return "YES";
		if(((2*b)-c > 0) && (((2*b)-c) % a) == 0) return "YES";
		if(((2*b)-a > 0) && (((2*b)-a) % c) == 0) return "YES";

		return "NO";

		return "NO";
	}
};

int main()
{
	int t;
	
	cin >> t;
	while(t--) {
		Q2 obj;

		obj.setter();
		cout << obj.makeAp() << endl;
	}

    return 0;
}

/*
space in selected lines- :s:^:space 4 fimes   
*/
