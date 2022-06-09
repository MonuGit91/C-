#include <iostream>
#include <string>
using namespace std;

class Q1 {
	public:
	int n;
	string s;
	
	Q1() {

	}

	void getter() {
		cin >> n >> s;
	}

	int minCosp() {
		int count = 0;

		for(int i = 0; i < n; i++) {
			if(s[i] == '0') {
				int j = i+1;
			
				while(j < n && s[j] != '0') j++;
				if(j-i == 2 && j < n) count++;
				if(j-i == 1 && j < n) count += 2;
			}
		}

		return count;
	}
};

int main()
{
	int t;
	
	cin >> t;
	while(t--) {
		Q1 obj;
		
		obj.getter();
		cout << obj.minCosp() << endl;
	}
    return 0;
}
