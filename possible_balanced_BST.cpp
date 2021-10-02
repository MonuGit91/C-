#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//---------------------------------------------dynamically
int posibleCompleteBinaryTrees3(int h)
{
    vector<int> *A = new vector<int>(h+1);
    
    A->at(0) = 1;
    A->at(1) = 1;
    for(int i = 2; i <= h; i++)
    {
        int a = A->at(i-1);
    	int b = A->at(i-2);
    
    	int mod = int(pow(10, 9) + 7);
    
    	int temp1 = int((long(a) * a) % mod);
    	int temp2 = int((2 * long(a) * b) % mod);
    	int ans = (temp1 + temp2) % mod;
    
    	A->at(i) = ans;
    }
    
    return A->at(h);
}


//---------------------------------------------memoization
int helpPosibleCompleteBinaryTrees(int h, vector<int> *A) {
    // Write your code here
    if(h <= 1) return 1;
    
    if(A->at(h) != -1) return A->at(h);
    
    int a = helpPosibleCompleteBinaryTrees(h-1, A);
    int b = helpPosibleCompleteBinaryTrees(h-2, A);
    
    int mod = int(pow(10, 9) + 7);
    
    int temp1 = int((long(a) * a) % mod );
    int temp2 = int((2 * long(a) * b) % mod);
    int ans = (temp1 + temp2) % mod;
    
    A->at(h) = ans;
    return ans;
}

int posibleCompleteBinaryTrees2(int h)
{
    vector<int> *A = new vector<int>(h+1);
    
    A->at(0) = 1;
    A->at(1) = 1;
    for(int i = 2; i <= h; i++) A->at(i) = -1;
    
    return helpPosibleCompleteBinaryTrees(h, A);
}


//---------------------------------------------brute force
int posibleCompleteBinaryTrees1(int h)
{
	if(h <= 1) return 1;

	int a = posibleCompleteBinaryTrees1(h-1);
	int b = posibleCompleteBinaryTrees1(h-2);

	int mod = int(pow(10, 9) + 7);

	int temp1 = int((long(a) * a) % mod );
	int temp2 = int((2 * long(a) * b) % mod);
	int ans = (temp1 + temp2) % mod; //

	return ans;
}

int main()
{
	int h;
	
	cout << "Enter hight of tree: ";
	cin >> h;

	cout << "total posible balanced BST\n";
	cout << "brute force: " << posibleCompleteBinaryTrees1(h) << endl;
	cout << "memoization: " << posibleCompleteBinaryTrees2(h) << endl;
	cout << "dynamically: " << posibleCompleteBinaryTrees3(h) << endl;
    return 0;
}










