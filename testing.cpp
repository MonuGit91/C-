#include <iostream>
using namespace std;

class A{
public:
	static int a;
	void app() {
		cout << a;
	}
};
int A::a = 10;

int sol(auto a) {
	cout << a;
}
int main()
{
	cout << (sol(10));
    return 0;
}
