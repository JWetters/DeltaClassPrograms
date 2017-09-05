#include <iostream>
#include <string>
#include "GPU.h"

using namespace std;

//************************************************************************
//	Constructor 
//
// Initilizes object member variables when called
//************************************************************************

graphicsCard::graphicsCard(int sId, string sCardName, int sCores, int sClock, int sMemory, double sFillRate)
{
	id = sId;
	cardName = sCardName;
	cores = sCores;
	clock = sClock;
	memory = sMemory;
	fillRate = sFillRate;
}

graphicsCard::graphicsCard()
{}

//************************************************************************
//	Add A Graphics Card
//
// Adds a Graphics Card
//************************************************************************

void graphicsCard::addGraphicsCard(int& size)
{
	// User enters ID#
	cout << "Enter ID#: " << endl;
	cin >> id;

	// User enters Graphics Card Name
	cout << "Enter the graphics card name: " << endl;
	cin >> cardName;

	// User enters Cores
	cout << "Enter the number of cores of the graphics card: " << endl;
	cin >> cores;

	// User enters Clock speed
	cout << "Enter the clock speed of the graphics card MHz: " << endl;
	cin >> clock;

	// User enters Memory Config
	cout << "Enter the memory configuration of the graphics card in GB: " << endl;
	cin >> memory;

	// User enters Texture Fill Rate
	cout << "Enter the texture fill rate of the graphics card: " << endl;
	cin >> fillRate;

	size = size + 1;
}
