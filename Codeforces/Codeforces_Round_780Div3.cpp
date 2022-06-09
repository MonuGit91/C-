#include <iostream>
using namespace std;

class Q1 {
	int a, b;
	public:
	void setter() {
		cin >> a >> b;
	}

	int canNotPay() {
		if(b == 0) return a +1;
		if(a == 0) return 1;
		else {
			return (2*b + a) + 1;
		}
	}
};

class Q2 {
	int n;
	vector<int> candies;

	private:
	bool check(string &str) { 
		for(int i = 0; i < str.size()-1; i) {
			if(str[i] == srt[i+1]) {
				i += 2;
			}
			else return false;

			return true;
		}
	}

	public:
	void setter() {
		string str;
		cin >> str;	
	}

	
	int getter() {
		int ans = 0;
		
		return ans;
	}
};

int main()
{
	int t;

	cin >> t;
	while(t--) {
		Q1 obj;

		obj.setter();
		cout << obj.getter() << endl;
	}

    return 0;
}
