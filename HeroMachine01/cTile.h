#ifndef CLASS_TILE_H
#define CLASS_TILE_H
#include"cBaseNode.h"

class Tile: public BaseNode
{
private:
	int iWidth;
	int iHeight;
	int iDirtAmount = 0;
	char tileValue;

	vector<int> neigbors;
	
	int starttime = NULL;
	int endtime = NULL;
	bool bClean = true; 
	bool bVisited = false;

	bool bNeigborsfound = false; 
	
public:

	Tile() {}
	Tile(int w, int h)
	{
		iWidth = w;
		iHeight = h;	
	}
	Tile(int size)
	{
		iWidth = size;
		iHeight = size;
	}



	//BOOL FUNCTIONS
	bool isClean()
	{
		if (iDirtAmount > 0)
		{
			bClean = false;
		}
		if (iDirtAmount == 0)
			return bClean;
	}

	bool isVisited()
	{
		return this->bVisited;
	}

	bool isNeigborsFound()
	{

		return this->bNeigborsfound;
	}

	
	//INT FUNCTIONS



	int getStartTime()
	{
		return starttime;
	}


	int getEndTime()
	{
		return starttime;
	}
	void setEndTime(int e)
	{
		endtime = e;
	}



	//CHAR FUNCTIONS
	char getTileValue()
	{
		return tileValue;

	}


	//VOID FUNCTIONS
	void setIsNeigborsFound(bool b)
	{
		this->bNeigborsfound = b;
	}
	void setIsVisited(bool b)
	{
		this->bVisited = b;
	}

	void setStartTime(int s)
	{
		this->starttime = s;
	}
	void setClean(bool b)
	{
		this->bClean = b;
	}
	void setTileValue(char x)
	{
		this->tileValue = x;
	}
	void cleanTile(int cleanAmount)
	{
		if (iDirtAmount > 0)
			iDirtAmount -= cleanAmount;
	}
	void dirtyTile(int dirtAmount)
	{
		if (iDirtAmount == 0)
			iDirtAmount += dirtAmount;
	}
	void printTileInfo()
	{
		cout << "\tPOSITION: " << this->getPosX() << ", " << this->getPosY() << ", " << this->getPosZ() << "\n";
		cout << "\t      ID: " << this->getID()<< "\n";
		cout << "\t   Value: " << this->getTileValue() << "\n\n";
	}



};
#endif // !CLASS_TILE_H
