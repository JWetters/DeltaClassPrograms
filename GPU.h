//
// Author James Wetters

#ifndef GPU_H
#define GPU_H
using namespace std;

class graphicsCard
{
private:
	// Data members
	int		id;
	string	cardName;
	int		cores;
	int		clock;
	int		memory;
	double	fillRate;

public:
	int size;
	// Constructor
	graphicsCard();
	graphicsCard(int sId, string sCardName, int sCores, int sClock, int sMemory, double sFillRate);

	// Gets
	int getId() const
	{ return id; }
	string getCardName() const
	{ return cardName; }
	int getCores() const
	{return cores; }
	int getClock() const
	{ return clock; }
	int getMemory() const
	{ return memory; }
	double getFillRate() const
	{ return fillRate; }

	// Sets
	void setId(int change)
	{ id = change; }
	void setCardName(string change)
	{ cardName = change; }
	void setCores(int change)
	{ cores = change; }
	void setClock(int change)
	{ clock = change; }
	void setMemory(int change)
	{memory = change; }
	void setFillRate(double change)
	{ fillRate = change; }

// Member Functions
	//add new member
	void addGraphicsCard(int& size);

};
#endif