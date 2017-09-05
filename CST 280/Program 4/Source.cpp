// This Program reads in raw data and out puts ...
// Author James Wetters

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;


// Prototypes
void fileInput(int W[3][7], int A[3][7], int P[3][7]);
int stringToInt(string convert);
void zero(int device[3][7]);
void print(int W[3][7], int A[3][7], int P[3][7]);
void printWeek(int W[3][7], int A[3][7], int P[3][7], int week);
void printTotal(int W[3][7], int A[3][7], int P[3][7], int week);
void overall(int W[3][7], int A[3][7], int P[3][7]);

int main()
{

	// Initilize variables
	int w[3][7], a[3][7], p[3][7];
	int goodData = 0;

	// Zero out 2d arrays
	zero(w);
	zero(a);
	zero(p);

	// Input data into three 2d arrays
	fileInput(w,a,p);

	// Print 3 weeks and totals
	print(w,a,p);

	system("pause");
	return 0;
}

//************************************************************************
//	 File Input
//
// Inputs from a text document
//************************************************************************

void fileInput(int W[3][7], int A[3][7], int P[3][7])
{
	// Input
	ifstream inputFile("rawData.txt");

	// Test file, will close if file fails to open
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// Prime read
	int week, day;
	string temp;

	getline(inputFile, temp, ',');
	char device = temp[0];

	getline(inputFile, temp, ',');
	week = stringToInt(temp);

	getline(inputFile, temp);
	day = stringToInt(temp);

	if (device == 'W')
	{
		W[week - 1][day]++;
	}
	else if (device == 'A')
	{
		A[week - 1][day]++;
	}
	else if (device == 'P')
	{
		P[week - 1][day]++;
	}

	// Step through collum
	
	while (!inputFile.eof())
	{
		int j = 0;
		// Step through row
		// Get Device
		getline(inputFile, temp, ',');
		char device = temp[0];

		// Get Week
		getline(inputFile, temp, ',');
		week = stringToInt(temp);

		// Get Day
		getline(inputFile, temp);
		day = stringToInt(temp);

		// Find device and add one to the day of the week
		if (device == 'W')
		{
			W[week - 1][day]++;
		}
		else if (device == 'A')
		{
			A[week - 1][day]++;
		}
		else if (device == 'P')
		{
			P[week - 1][day]++;
		}
	}

	// Close file
	inputFile.close();
}


//************************************************************************
//	cstrings to int 
//
// Recivies a string line 
// Converts to a number to send back
//************************************************************************

int stringToInt(string convert)
{
	// Convert string to cstring to number
	int number = atoi(convert.c_str());

	return number;
}


//************************************************************************
//	Zero 
//
// Recivies a 2d array 
// Zeros out all spots of the array
//************************************************************************

void zero(int device[3][7])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			device[i][j] = 0;
		}
	}
}

//************************************************************************
//	Print 
//
// Recivies a 2d array 
// Prints 3 weeks of data and a total
//************************************************************************

void print(int W[3][7], int A[3][7], int P[3][7])
{
	// Initilize variables
	int week = 0;

	// Print weeks
	while (week < 3)
	{
		// Print the week
		printWeek(W, A, P, week);

		// Increment week by 1
		week++;
	}

	overall(W, A, P);
}


//************************************************************************
//	Print 
//
// Recivies a 2d array 
// Prints 3 weeks of data
//************************************************************************

void printWeek(int W[3][7], int A[3][7], int P[3][7], int week)
{
	// Initilize variables
	int total = 0;

	// Top Line
	cout << "Week" << week + 1 << setw(13) << "Su" << setw(4) << "Mo";
	cout << setw(4) << "Tu" << setw(4) << "We" << setw(4) << "Th";
	cout << setw(4) << "Fr" << setw(4) << "Sa" << setw(7);
	cout << "Total" << endl;

	// First Line
	cout << "Web" << setw(15);

	for (int j = 0; j < 7; j++)
	{
		
		cout << W[week][j] << " ";
		total = total + W[week][j];
	}
	cout << " " << total << endl;

	// Secound Line
	total = 0;
	cout << "App" << setw(15);
	for (int j = 0; j < 7; j++)
	{
		
		cout << A[week][j] << " ";
		total = total + A[week][j];
	}
	cout << " " << total << endl;

	// Third Line
	total = 0;
	cout << "Phone" << setw(13);
	for (int j = 0; j < 7; j++)
	{
		
		cout << P[week][j] << " ";
		total = total + P[week][j];
	}
	cout << " " << total << endl;

	// Fourth line
	printTotal(W, A, P, week);
}


//************************************************************************
//	Print 
//
// Recivies a 2d array 
// Prints Total
//************************************************************************

void printTotal(int W[3][7], int A[3][7], int P[3][7], int week)
{
	// Initilize variables
	int finalTotal = 0;
	int total = 0;

	// Row header
	cout << "Total" << setw(13);

	// Collums
	for (int j = 0; j < 7; j++)
	{
		// Reset Total
		total = 0;

		// Find the total for each device
		total = total + W[week][j];
		total = total + A[week][j];
		total = total + P[week][j];

		// Write total
		cout << total << " ";

		// Add totals
		finalTotal = finalTotal + total;
	}

	// Write Final Total
	cout << " " << finalTotal << "\n" << endl;
}


//************************************************************************
//	Print 
//
// Recivies a 2d array 
// Prints 3 weeks of data and a total
//************************************************************************

void overall(int W[3][7], int A[3][7], int P[3][7])
{
	// Initilize variables
	int total = 0;
	int finalTotal = 0;
	int overAll[3][7];

	// Zero Out Array
	zero(overAll);

	cout << "Overall" << setw(11) << "Su" << setw(4) << "Mo";
	cout << setw(4) << "Tu" << setw(4) << "We" << setw(4) << "Th";
	cout << setw(4) << "Fr" << setw(4) << "Sa" << setw(7);
	cout << "Total" << endl;

	// Populate Array overAll
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			overAll[0][j] = overAll[0][j] + W[i][j];
			overAll[1][j] = overAll[1][j] + A[i][j];
			overAll[2][j] = overAll[2][j] + P[i][j];
		}
	}
	

	// Write Overall

	// First Line
	cout << "Web" << setw(15);

	for (int j = 0; j < 7; j++)
	{

		cout << W[0][j] << " ";
		total = total + W[0][j];
	}
	cout << " " << total << endl;

	// Secound Line
	// Reset total
	total = 0;
	cout << "App" << setw(15);
	for (int j = 0; j < 7; j++)
	{

		cout << A[1][j] << " ";
		total = total + A[1][j];
	}
	cout << " " << total << endl;

	// Third Line
	// Reset total
	total = 0;
	cout << "Phone" << setw(13);
	for (int j = 0; j < 7; j++)
	{

		cout << P[2][j] << " ";
		total = total + P[2][j];
	}
	cout << " " << total << endl;
	
	// Fourth Line
	// Row header
	cout << "Total" << setw(13);
	// Reset final total
	finalTotal = 0;
	// Reset total
	total = 0;

	// Collums
	for (int j = 0; j < 7; j++)
	{
		total = 0;

		total = total + W[0][j];
		total = total + A[1][j];
		total = total + P[2][j];
		cout << total << " ";
		finalTotal = finalTotal + total;
	}

	// Write Final Total
	cout << " " << finalTotal << "\n" << endl;
}