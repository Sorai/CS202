#include <iostream>
#include <fstream>

using namespace std;

void readFile(char (&machine)[10][3][30]);
void outputFile(char (&machine)[10][3][30], char outputFile[50]);

int main()
{
	char machine[10][3][30];
	char outputFileName[50];

	readFile(machine);
	
	//gets output file name
	cout << "Please name your output file" << endl;
	cin >> outputFileName;
	
	outputFile(machine, outputFileName);
}

/*
	Reads the symbols.txt file
	Runs through the machine 3D array
	Places strings from symbols.txt into machine 3D array
*/
void readFile(char (&machine)[10][3][30])
{
	ifstream file("symbols.txt", ios::in);
	

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			file >> machine[i][j];
		}
	}
	file.close();
}

/*
	Creates an ouput file using the user given name
	Runs through the machine 3D array
	Places the char arrays from machine into the output file
*/
void outputFile(char (&machine)[10][3][30], char outputFile[50])
{
	ofstream outFile(outputFile);

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			outFile << machine[i][j] << endl;
		}
	}

	outFile.close();
}
