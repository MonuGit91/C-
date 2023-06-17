#include <iostream>
#include <fstream>
using namespace std;

void writeInFile()
{
	fstream file1;

	file1.open("file handeling.txt", ios::trunc | ios::out | ios::in);//---> clear, write, read 
    if(file1.is_open())
    {
        file1 << "hello world\n";
        file1 << " this is second line\n";
        file1.close();
    }

    file1.open("file handeling.txt", ios::app);
    {
        if(file1.is_open())
        {
            int i = 1;
            file1 << i << "\n";
            file1.close();
        }
    }
}

void readFile()
{
	fstream file1;

	file1.open("untitled.txt", ios::in);
    if(file1.is_open())
    {
        string line;
        while(getline(file1, line))
        {
            cout << line << " : " << line.size() << endl;
        }
        file1.close();
    }
}

int main()
{
	writeInFile();
	readFile();
	
	system("date");

	return 0;
}
