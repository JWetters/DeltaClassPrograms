// Quiz Item 
// Author James Wetters
#include "tripsegment.h"

//************************************************************************
// Constructor
// 
//************************************************************************

TripSegment::TripSegment(double fromla , double  tola , double fromlo , double tolo, double ptpdistance)
{

	fromLat = fromla;
	toLat = tola;
	fromLon = fromlo;
	toLon = tolo;
}



void TripSegment::print()
{
	/// Write line for one trip leg
	cout << setprecision(3) << fixed;
	cout << fromLat << "," << fromLon << " ==> ";
	cout << toLat << "," << toLon << " = ";;
	cout << setprecision(1) << fixed << pointToPointDis << " miles" << endl;
}
