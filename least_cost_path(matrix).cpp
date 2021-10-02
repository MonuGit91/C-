#include <iostream>
#include <climits>
#include <vector>
#include <vector>
using namespace std;

vector<vector<int>*>* makeMatrix(int row, int column)
{
	vector<vector<int>*>* A;
	A = new vector<vector<int>*>(row);

	for(int i = 0; i < row; i++)
	{
		A->at(i) = new vector<int>(column);
	}
	return A;
}

vector<vector<int>*>* matrixInput(vector<vector<int>*>*A,int row,int column, int value = INT_MIN)
{
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
		 {
			 if(value == INT_MIN) cin >> A->at(i)->at(j);
			 else A->at(i)->at(j) = value;
		 }

	return A;	
}

void printMatrix(vector<vector<int>*> *A)
{
	int row = A->size();
	int column = A->at(0)->size();

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			cout << A->at(i)->at(j) << " ";
		}
		cout << endl;
	}
}



int helpPathCost1(vector<vector<int>*> *A, int row, int column)
{
    if(row == 0 && column == 0) return A->at(0)->at(0);

    if(row < 0 || column < 0) return INT_MAX;

    int a = helpPathCost1(A, row, column-1);
    int b = helpPathCost1(A, row-1, column-1);
    int c = helpPathCost1(A, row-1, column);

    int ans = min(a, min(b, c)) + A->at(row)->at(column);

    return ans;;
}

int pathCost1(vector<vector<int>*> *A, int row, int column)
{
	return helpPathCost1(A, row-1, column-1);
}



int helpPathCost2(vector<vector<int>*> *A, int row, int column, vector<vector<int>*> *B)
{
	if(row == 0 && column == 0) return A->at(0)->at(0);

	if(row < 0 || column < 0) return INT_MAX;

	if(B->at(row)->at(column) != -1) return B->at(row)->at(column);

	int a = helpPathCost2(A, row, column-1, B);
 	int b = helpPathCost2(A, row-1, column-1, B);
 	int c = helpPathCost2(A, row-1, column, B);
 
 	int ans = min(a, min(b, c)) + A->at(row)->at(column);
	B->at(row)->at(column) = ans;

	return ans; 
}

int pathCost2(vector<vector<int>*> *A, int row, int column)
{
	vector<vector<int>*> *B = makeMatrix(row, column);
	int value = -1;
	B = matrixInput(B, row, column, value);

	return helpPathCost2(A, row-1, column-1, B);
}



int pathCost3(vector<vector<int>*> *A, int row, int column)
{
	 vector<vector<int>*> *B = makeMatrix(row, column);
	 B->at(0)->at(0) = A->at(0)->at(0);

	 for(int i = 0; i < row; i++)
	 {
		 for(int j = 0; j < column; j++)
		 {
			 if(i == 0 && j == 0) continue;

			 int a = INT_MAX, b = INT_MAX, c = INT_MAX;

			 if(j-1 >= 0) a = B->at(i)->at(j-1);
			 if(i-1 >= 0 && j-1 >= 0) b = B->at(i-1)->at(j-1);
			 if(i-1 >= 0) c = B->at(i-1)->at(j);

			 B->at(i)->at(j) = min(a, min(b, c)) + A->at(i)->at(j);
		 }
	 }

	 return B->at(row-1)->at(column-1);
}


int main()
{
	vector<vector<int>*> *A;
	int row = 4, column = 3;

	A = makeMatrix(row, column);
	A = matrixInput(A, row, column);
	printMatrix(A);

	cout << "Minimun path cost(Brute force): " << pathCost1(A, row, column) << endl;
	cout << "Minimun path cost(Memoization): " << pathCost2(A, row, column) << endl;
	cout << "Minimun path cost(Dynamically): " << pathCost3(A, row, column) << endl;

    return 0;
}
//01 02 03 04 05 06 07 08 09 10 11 12
