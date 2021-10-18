#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, H; cin >> n >> H;
		priority_queue<int> Q;

		for(int i = 0; i < n; i++)
		{
			int ai; cin >> ai;
			Q.push(ai);
		}
		
		int count = 0;
		while(Q.empty() == 0)
		{
			int a = Q.top(); Q.pop();
			H -= a; count++;

			if(H <= 0)
			{
				cout << count << endl; 
				break;
			}
			if(Q.empty() == 0)
			{
				int b = Q.top();
				H -= b; count++;
				
				if(H <= 0)
                {
                   cout << count << endl;
                   break;
                }
 				Q.push(a);
			}
		}
	}
    return 0;
}
