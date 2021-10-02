#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> *A = new vector<vector<int>>(10, vector<int>(10, -1));
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++) cout << A->at(i).at(j) << " ";
		cout << endl;
	}
    return 0;
}
