#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int r = 1;
	while(r <= t)
	{
		r++;
		string s, a;
		cin >> s;
		if(s.size() == 0) cout << "Case #" << r << ": IMPOSSIBLE" << endl;
		queue<int> q;
		int i;
		for(i = 0; i < s.size(); i++) q.push(i);
		i = 0;
		bool flag = false;
		bool flag2 = false;
		while(q.size() > 1)
		{
			int index = q.front();
			q.pop();

			if(s[i] != s[index])
			{
				a += s[index];
				i++;
				continue;
			}

			q.push(index);

			while(q.front() != index)
			{
				int top = q.front();
				q.pop();
				if(s[i] != s[top])
				{
					a += s[top];
					i++;
					flag = true;
					break;
				}
				q.push(top);
			}
			if(!flag)
			{
				flag2 = true;
				cout << "Case #" << r << ": IMPOSSIBLE" << endl;
				break;
			}
		}

		int index = q.front();
		a += s[index];
		
		for(int k = 0; k < s.size(); k++)
		{
			if((s[k] != a[index]) && (s[index] != a[k]))
			{
				char temp = a[index];
				a[index] = a[k];
				a[k] = temp;
				cout << "Case #" << r << ": " << a << endl;
				flag = true;
			} 
			break;
		}
		if(!flag2 && !flag) cout << "Case #" << r << ": IMPOSSIBLE" << endl;
	}

}
