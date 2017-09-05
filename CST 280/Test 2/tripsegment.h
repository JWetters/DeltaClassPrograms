// Quiz Item
// Author James Wetters
#ifndef TRIPSEGMENT_H
#define TRIPSEGMENT_H
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <cmath> 
#include "listoftripsegments.h"

using namespace std;

class TripSegment : public ListOfTripSegments
{
private:
	// DATA MEMBERS
	double fromLat, toLat, fromLon, toLon, pointToPointDis;

public:
	// SETS
	void setFromLat(double change)
	{
		fromLat = change;
	}

	void setToLat(double change)
	{
		toLat = change;
	}

	void setFromLon(double change)
	{
		fromLon = change;
	}

	void setToLon(double change)
	{
		toLon = change;
	}

	void setPointToPointDis(double change)
	{
		pointToPointDis = change;
	}

	// GETS
	double getFromLat() const
	{
		return fromLat;
	}

	double getToLat() const
	{
		return toLat;
	}

	double getFromLon() const
	{
		return fromLon;
	}

	double getToLon() const
	{
		return toLon;
	}

	double getPointToPointDis() const
	{
		return pointToPointDis;
	}
	
	// MEMBER FUNCTIONS
	TripSegment(double fromla, double  tola, double fromlo, double tolo, double ptpdistance);
	void print();

};
#endif 