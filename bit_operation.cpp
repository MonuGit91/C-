#include <iostream>
using namespace std;

int get_bit(int number, int position)
{
	return ((number & (1 << position)) != 0);
}

int set_bit(int number, int position)
{
	return (number | (1 << position));
}

void print_binary(int number)
{
	int i;
	int position = 0;
	for(int j = 0; j < 8; j++)
        {
                i = get_bit(number, position++);
                cout << i << "\n";
        }
}


int main()
{

	int number = '5';
	int position = 0;
	int i;


//-----------------------------------------------Get Bit-----------------------------------
	cout << "\n\nGET BIT \nbinary of: " << number << endl;
	print_binary(number);


//-----------------------------------------------Set Bit-----------------------------------

	cout << "\nSET BIT in: " << number << endl;

	position = 0;
	int zero_one = 0;
	int k = 2;

	for(int j = 0; j < 8; j++)
	{
		cout << "position: " << position << " bit: " << get_bit(number, position) << endl;

		number = set_bit(number, position);

		cout << "position: " << position << " bit: " << get_bit(number, position) << endl << endl;

		if(k%2 == 0) zero_one = 0;
		k++;
		position++;
	}
	cout << "\n\n FINAL NUMBER: " << number << endl;
	print_binary(number);

//---------------------------------------------clear bit------------------------------------------
	
	cout << "\n\nCLEAR BIT at position\n;
	
	return 0;
}
