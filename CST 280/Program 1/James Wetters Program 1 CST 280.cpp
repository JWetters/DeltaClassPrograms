// This program takes user input and outputs a month calander 
// and prints a sunrise and sunset table for the given month
// Author James Wetters
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "datefun.h"
#include "sun.h"

using namespace std;

// Initilize Constants
const int MAXARRAY = 20;

// Function Prototypes
void airportInputFile(double latitudeArray[], double longitudeArray[], string cityArray[], char timeZoneArray[], int& token);
void userInput(double latitudeArray[], double longitudeArray[], string cityArray[], char timeZoneArray[], int& token, int&month, int& year, int& currentAirport);
void printResults(double latitudeArray[], double longitudeArray[], char timeZoneArray[], int& month, int& year, int& currentAirport);

int main()
{
	// Initilize variables
	int token = 0;
	int month = 0;
	int year = 0;
	int currentAirport;
	char continueProgram = 'y';

	// Setting up file input
	ifstream inputFile;

	//Initilize 4 main arrays
	double latitudeArray[MAXARRAY];
	double longitudeArray[MAXARRAY];
	string cityArray[MAXARRAY];
	char timeZoneArray[MAXARRAY];

	// Read in file
	airportInputFile(latitudeArray, longitudeArray, cityArray, timeZoneArray, token);

	// User choice to stay in the program
	while (continueProgram == 'y' || continueProgram == 'Y')		// Do the body of the function atleast once
	{
		// User input
		userInput(latitudeArray, longitudeArray, cityArray, timeZoneArray, token, month, year, currentAirport);

		// Calculate and print calander and sun rise and set times
		printResults(latitudeArray, longitudeArray, timeZoneArray, month, year, currentAirport);

		// User decision to stay in the program
		cout << "\n" << "Do you wish to continue? Y or N" << endl;
		cin >> continueProgram;
	}

	system("pause");
	return 0;
}

// Functions ***********************************************************

// Input File

void airportInputFile(double latitudeArray[], double longitudeArray[], string cityArray[], char timeZoneArray[], int& token)
{
	// Open file
	ifstream inputFile("cityinfo.txt");

	// Test file
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		exit(-1);
	}

	// Read in file
	for (int x = 0; !inputFile.eof(); x++)
	{
		inputFile >> cityArray[x];
		
		inputFile >> latitudeArray[x];
		
		inputFile >> longitudeArray[x];
		
		inputFile >> timeZoneArray[x];
		
		token = x;
		
	}

	// Set Token
	token = token - 1;
}

// User Input

void userInput(double latitudeArray[], double longitudeArray[], string cityArray[], char timeZoneArray[], int& token, int&month, int& year, int& currentAirport)
{
	// Initilize variables
	string cityAirportID;
	bool pass = false;
	// Prompt user
	cout << "Enter a month # 1-12, a 4 digit year and a 3 character city airport identifier." << endl;


	// User enters month
	cin >> month;

	// Month check
	while (month < 1 || month > 12)
	{
		cout << "Please enter a valid month 1-12." << endl;
		cin >> month;
	}

	// User enters year
	cin >> year;
	while (year <= 1970 || year > 9999)
	{
		cout << "Please enter a valid 4 digit year." << endl;
		cin >> year;
	}

	// User enters airport ID
	cin >> cityAirportID;

	// Check city airport ID
	while (pass == false)
	{
		// Lable output
		cout << "\n" <<  month << " " << year << " " << cityAirportID << endl;

		// Find city airport ID in the array
		for (int i = 0; i <= token; i++)
		{
			if (cityAirportID.compare(cityArray[i]) == 0)
			{
				// Airport found, currentAirport is set to the index for
				// the parallel arrays
				currentAirport = i;
				pass = true;
			}
		}

		// Check if found
		if (pass == false)	// Not found if statment is true
		{
			// If city airport ID is not found than reprompt the user
			cout << "Enter valid city airport ID. " << endl;
			cin >> cityAirportID;
		}
	}
}

	void printResults(double latitudeArray[], double longitudeArray[], char timeZoneArray[], int& month, int& year, int& currentAirport)
	{
		// Initilize Variables
		int monthLength;
		bool dayLightSavings = false;

		// Test for day light savings
		if (month >= 3 && month <= 11)
		{
			dayLightSavings = true;
		}

		// Find the lenght of the month in number of days
		monthLength = DaysInMonth(month, year);

	for (int day = 1; day <= monthLength; day++)
	{
		// Initilize Variables
		int weekDayCode;
		int sunRise = 0;
		int sunSet = 0;
		char weekDayString[4];
		char rise[8];
		char set[8];
		
		// Find the week day sun - sat
		// get week day code
		weekDayCode = weekDay(month,day,year);

		// Translate weekday code
		dayCode(weekDayCode,weekDayString);

		// Finde the sun rise an sun set
		// recive 2 cstrings rise and set
		Sun_Rise_Set(latitudeArray[currentAirport], longitudeArray[currentAirport], month, day, year, timeZoneArray[currentAirport], dayLightSavings, rise, set);

		// Print to the screen for each day
		cout << " " << day;
		cout << " " << weekDayString << " ";
		cout << "Sun Rise: " << rise << "  ";
		cout << "Sun Set : " << set << endl;
	}
}

	// Functions ***********************************************************