#ifndef LISTOFTRIPSEGMENTS_H
#define LISTOFTRIPSEGMENTS_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

// Constants
const int PMAXARRAY = 20;

class ListOfTripSegments
{
private:
	// DATA MEMBERS
	double fromLat, toLat, fromLon, toLon;
	double distance, totalDist;

	// DATA MEMBERS
	ListOfTripSegments *pArray[PMAXARRAY];

public:
	// SETS
	void setDistance(double change)
	{
		distance = change;
	}

	void setTotalDist(double change)
	{
		totalDist = change;
	}

	// GETS
	double getDistance() const
	{
		return distance;
	}

	double getTotalDist() const
	{
		return totalDist;
	}

	// MEMBER FUNCTIONS
	ListOfTripSegments();
	//virtual void generateQuestion() = 0;
	void print();
	// Utility functions necessary for calculations
	double GreatCircleDist(double la1, double lo1, double la2, double lo2);
	double Deg_Rad(double angle);
};
#endif 