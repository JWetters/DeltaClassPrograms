#include "listoftripsegments.h"
//#include "dynStack.h"
#include "tripsegment.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "dynStack.h"

using namespace std;


//************************************************************************
// Constructor
// 
//************************************************************************

ListOfTripSegments::ListOfTripSegments()
{
	// Variable declarations
	ifstream infile;
	//double fromLat, toLat, fromLon, toLon;
	//double distance, totalDist;

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

		// Dynamically allocated with pointers
		// push
		//push();
		//NodeType<doulbe> theStack(20);
		//TripSegment *pointer;
		//*pointer TripSegment(fromLat, fromLon, toLat, toLon, distance);

		//push(TripSegment(fromLat, fromLon, toLat, toLon, distance));

		// Accumulate trip leg distance
		totalDist += distance;

		// Adjust to set up for next trip leg - "to" position becomes "from"
		fromLat = toLat;
		fromLon = toLon;

		// Read forward for "from" coordinate of next leg
		infile >> toLat >> toLon;
	}

	// Print reversed
	// while(!theStack.isEmpty)
	//{
	// theStack.pop(->print());
	//}


	print();
}

//************************************************************************
// Print
// 
// 
//************************************************************************

void ListOfTripSegments::print()
{
	// Write total
	cout << "Total hiking: " << setprecision(3) << fixed << getTotalDist() << " miles" << endl;
}


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
double ListOfTripSegments::GreatCircleDist(double la1, double lo1, double la2, double lo2)
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
double ListOfTripSegments::Deg_Rad(double angle)
{
	double const pi = 3.1415926;
	return angle * pi / 180.0;
}




//************************************************************************
// List of Trip Segments Deconstructor
//
// 
//************************************************************************
//ListOfTripSegments::~ListOfTripSegments()
//{
	// Loop through pointer array
	//for (int i = 0; i < PMAXARRAY; i++)
	//{
		// Delete each pointer
		//delete pArray[i];
	//}
//}

