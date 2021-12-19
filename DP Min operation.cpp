#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minOperation1(string s1, string s2)
{
	if((s1.size() == 0) || (s2.size() == 0))
	{
		return max(s1.size(), s2.size());
	}

	if(s1[0] == s2[0])
	 {
		 int ans = minOperation1(s1.substr(1), s2.substr(1));
		 return ans;
	 }

	int a = 1 + minOperation1(s1.substr(1), s2.substr(1));
	int b = 1 + minOperation1(s1, s2.substr(1));
	int c = 1 + minOperation1(s1.substr(1), s2);

	int ans = min(a, min(b, c));
	return ans;
}

int minOperation2(string s1, string s2)
{
	vector<vector<int>> *A(new vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1)));

	

}

int main()
{
	string s1 = "abc", s2 = "cba";
	cout << "min operation(Brute force): " << minOperation1(s1, s2) << endl;
	cout << "min operation(Memoization): " << minOperation2(s1, s2) << endl;
    return 0;
}
