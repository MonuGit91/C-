#include <iostream>
#include <vector>
#include <string>
using namespace std;

string timeConversion(string str)
{
	int h1 = int(str[0] - '0');
        int h2 = int(str[1] - '0');     
        int hh = ((h1 * 10) + h2);

	string military_time;	
	
// For AM:
	if(str[str.size()-2] == 'A')
	{
		if(hh == 12) 
		{
			military_time += "00";
			military_time += str.substr(2, str.size()-4);
			return military_time;
		}
		return str.substr(0, str.size()-2);
	}
// For PM:
	if(hh == 12)
	{
		military_time += "12";
                military_time += str.substr(2, str.size()-4);
		return military_time;
	}	

	hh += 12;
	military_time += ('0' + (hh / 10));
	military_time += ('0' + (hh % 10));
	military_time += str.substr(2, str.size()-4);

	return military_time;
}
int main()
{
	vector<string> v;
	
	for(int i = 0; i < 10; i++)
	{
		v.push_back("0");
		v[i] += '0' + i;
		v[i] += ":01:11AM";
	}
	
	
	v.push_back("10:01:11AM");
	v.push_back("11:01:11AM");
	v.push_back("12:01:11AM");	

	for(int i = 13; i < 23; i++)
	{
		v.push_back("0");
                v[i] += ('0' + i-13);
                v[i] += ":01:11PM";
	}

        v.push_back("10:01:11PM");
        v.push_back("11:01:11PM");
	v.push_back("12:01:11PM");

	for(int i = 0; i < v.size(); i++) cout << v[i] << endl;

	cout << endl;

	for(int i = 0; i < v.size(); i++)
	{
		string result = timeConversion(v[i]);
		cout << result << "\n";
	}

    return 0;	
}
