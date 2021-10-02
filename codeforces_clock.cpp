#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}		
	
		int i = a, j = b;
		bool flag = true;
		while(i != 0 && j > a)
		{
			if(j == c)
			{
			 	cout << i << endl;
				flag = false;
				break;
			}
			i--;
			j--;
		}
		if(!flag) continue;
		i = a, j = b;
		while(i < b)
		{
			if(i == c)
			{
				cout << j << endl;
				flag = false;
				break;
			}
			i++;
			j++;
		}
		if(flag) cout << -1 << endl;
	}
}
