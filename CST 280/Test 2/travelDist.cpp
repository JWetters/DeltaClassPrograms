// This program reads a file of GPS waypoints collected during a Minnesota
// hiking trip.  It calculates the trip legs between waypoints, calculates
// the distance for each leg, and then totals the trip

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "listoftripsegments.h"
using namespace std;

// Utility functions necessary for calculations
//double GreatCircleDist(double la1, double lo1, double la2, double lo2);
//double Deg_Rad(double angle);

int main()
{
	/*
	// Variable declarations
	ifstream infile;
	double fromLat, toLat, fromLon, toLon;
	double distance, totalDist;

	// Read and validate file
	infile.open("waypoints.txt");
	if (infile.fail())
	{
		cout << "Problem opening file";
		exit(-1);
	}

	totalDist = 0;               // Initialize accumulator

	// Read loop
	// Read two lines inititally to get first trip leg.  Enter loop with one
	// entire trip determined to prime the calculations.  From there, the "to"
	// coordinate becomes the "from" coordinate before the next let is
	// determined.
	infile >> fromLat >> fromLon;
	infile >> toLat >> toLon;
	while (!infile.eof())
	{
		// Calculate distance
		distance = GreatCircleDist(fromLat, fromLon, toLat, toLon);

		// Write line for one trip leg
		cout << setprecision(3) << fixed;
		cout << fromLat << "," << fromLon << " ==> ";
		cout << toLat << "," << toLon << " = ";;
		cout << setprecision(1) << fixed << distance << " miles" << endl;

		// Accumulate trip leg distance
		totalDist += distance;

		// Adjust to set up for next trip leg - "to" position becomes "from"
		fromLat = toLat;
		fromLon = toLon;

		// Read forward for "from" coordinate of next leg
		infile >> toLat >> toLon;
	}

	// Write total
	cout << "Total hiking: " << setprecision(3) << fixed << totalDist << " miles" << endl;

	*/

	// The Object aproch

	ListOfTripSegments a;




	system("pause");
	return 0;
}

/*
//***************************************************************
// This function receives two sets of geographical coordinates
// and returns the great circle distance betweent them.
// Preconditions:
//    Latitude/longitude values in radians
//    Value ranges:  -90.0 <= Latitudes <= 90.0
// -180.0 <= Longitudes <= 180.0
// Postconditions:
//    Coordinate parameters are unchanged
//    Return value (distance) in kilometers
//***************************************************************
double GreatCircleDist(double la1, double lo1, double la2, double lo2)
{
	const double RADIUS_EARTH = 3963.189; // in miles

	// Convert local variables to radians
	la1 = Deg_Rad(la1);
	lo1 = Deg_Rad(lo1);
	la2 = Deg_Rad(la2);
	lo2 = Deg_Rad(lo2);
	return RADIUS_EARTH * acos(sin(la1) * sin(la2)
		+ cos(la1) * cos(la2) * cos(lo2 - lo1));
}

//***************************************************************
// This function receives a value in degrees and returns the
// equivalent angle in radians
//***************************************************************
double Deg_Rad(double angle)
{
	double const pi = 3.1415926;
	return angle * pi / 180.0;
}

*/