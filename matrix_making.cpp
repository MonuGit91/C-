#include <iostream>
#include <vector>
using namespace std;

int** make_normal_matrix(int row, int column)
{
	int **A = new int*[row];
	for(int i = 0; i < column; i++)
	{
		A[i] = new int[column];
	}
	return A;
}

void print_normal_matrix(int **A,int row,int column)
{
	for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << A[i][j] << " ";
        }
		cout << endl;
    }
}


vector<vector<int>*>* make_vector_matrix(int row, int column)
{
	vector<vector<int>*> * A = new vector<vector<int>*>(row);
	for(int i = 0; i < column; i++)
    {
		A->at(i) = new vector<int>(column);
    }
	return A;
}

void fill_normal_matrix(int **A, int row, int column)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			A[i][j] = j;
		}
	}
}


void fill_vector_matrix(vector<vector<int>*> *A)
{
	int row = A->size(); // or row = (*A).size();
	int column = A->at(0)->size(); // or column = (*((*A).at(0))).size();
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			A->at(i)->at(j) = j; // cin >> (*((*A).at(i))).at(j);
		}
	}
}
										
void print_vector_matrix(vector<vector<int>*> *A,int row,int column)
{
	for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << A->at(i)->at(j) << " ";
        }
		cout << endl;
    }
}
vector<vector<int>> fill_vector_matrix1(int row, int column)
{														
	vector<vector<int>> A(row, vector<int>(column, 0));
    for(int i = 0; i < row; i++)                      
    {
        for(int j = 0; j < column; j++)
        {
            A[i][j] = j;
        }
    }
	return A;
}
														           //To avoid copy and hanges use
void print_vector_matrix1(vector<vector<int>> A,int row,int column)//const &A
{																   	
	for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << A[i][j] << " ";
        }
		cout << endl;
    }
}

void print_vector_matrix2(vector<vector<int>> *C)
{
	int row = C->size();
	int col = C->at(0).size();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++) cout << C->at(i).at(j) << " ";
		cout << endl;
	}
}

int main()
{
	int row = 3, column = 3;


	cout << "normal_matrix: **A\n";
	int **A;
	A  = make_normal_matrix(row, column);
	fill_normal_matrix(A, row, column);
	print_normal_matrix(A, row, column);

	cout << "vector_matrix1: vector<vector<int>> C\n";
	vector<vector<int>> C(row, vector<int>(column,0));
	C = fill_vector_matrix1(row, column);
	print_vector_matrix1(C, row, column);

	cout << "vector_matrix2: vector<vector<int>> *C\n";
	vector<vector<int>> *C1;//C1(new vector<vector<int>>(row, vector<int>(column, 0)));
	C1 = new vector<vector<int>>(row, vector<int>(column, 0));
	print_vector_matrix2(C1);

	cout << "vector_matrix: vector<vector<int>*> *B\n";
	vector<vector<int>*> *B;//B(new vector<vector<int>*>(row, new vector<int>(column, 0)));
	B = make_vector_matrix(row, column); 
	fill_vector_matrix(B);
	print_vector_matrix(B, row, column);
    return 0;
}
