// Name ID Source
// Author James Wetters

#include "nameId.h"


NameID::NameID()
{
	int convertedIData;

	string data, first, last, fullN;

	ifstream inNameIDFile("nameid.txt");

	// Test File
	if (inNameIDFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// Prime read
	getline(inNameIDFile, data, ',');
	goodData = 0;

	while (!inNameIDFile.eof())
	{
		first = data;

		getline(inNameIDFile, data, ',');

		last = data;

		fullN = first + " " + last;

		name[goodData] = fullN;

		//cout << fullN << "   ";

		getline(inNameIDFile, data);

		convertedIData = atoi(data.c_str());

		//cout << convertedIData << endl;

		ID[goodData] = convertedIData;
		
		getline(inNameIDFile, data, ',');

		goodData++;
	}

	inNameIDFile.close();
	inNameIDFile.clear();
}


string NameID::findName(int custID)
{
	bool found = false;
	int i = 0;
	string notFound = " ";

	while (found != true && i <= goodData)
	{
		if (ID[i] == custID)
		{
			found = true;
		}
		else i++;

	}

	if (found == true)
	{
		return name[i];
	}

	return notFound;
}