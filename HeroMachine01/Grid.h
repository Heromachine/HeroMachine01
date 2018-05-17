#ifndef CLASS_GRID_H
#define CLASS_GRID_H
#include <iostream>
#include<vector>
#include <fstream>
#include <math.h>
#include <time.h> 
#include<string>

#include "cBaseNode.h"
#include "cTile.h"



using namespace std;

class Grid : public BaseNode
{
private:
	int col;
	int row;
	vector<Tile> tiles;
	int modulous; 
	int iDirtyAmount = 0;
	int tileGap = 0;
	
public:
	Grid() {};
	
	Grid(int x, int y, int z, string fileName, int tilesize)
	{
		this->setPosX(x);
		this->setPosY(y);
		this->setPosZ(z);
		LoadGrid(fileName, tilesize);
	
	}
	Grid(int x, int y, int z)
	{
		setPosition(x, y, z);
	
	}

	bool dirtyChance(int percent)
	{
		//srand(time(NULL));
		int chance = (rand() % 100 + 1);

		
		if ( chance < percent)
		{
			iDirtyAmount += 1;
			return false;

		}
		else 
		return true;
	
	
	}


	//CONSTRUCTOR GENERATES GRID NOT FROM FILE
	Grid(int x, int y, int z, int tilesize, int gridsize, int percent)
	{	

		
		setPosition(x, y, z);
		modulous = gridsize;

		
		for (int i = 0; i < gridsize*gridsize; i++)
		{


			Tile t(tilesize);

			t.setClean(dirtyChance(percent));

			if (t.isClean() == false)
			{
				t.setTileValue('x');
			}
			else
			{
				t.setTileValue(' ');
			}


			

			
			t.setID(i);
			if (t.getID() > 0)
			{
				t.setPosY(this->getPosY());

				if (i%modulous == 0)
				{					
					t.setPosX(this->getPosX());					
					t.setPosZ(tiles.at(i - gridsize).getPosZ() -tilesize);
				}
				else
				{
					t.setPosX(tiles.at(i - 1).getPosX() + gridsize);
					t.setPosZ(tiles.at(i - 1).getPosZ());					
				}		
			}
			else
			{
				t.setPosition(this->getPosX(), this->getPosY(), this->getPosZ());			
			}

			tiles.push_back(t);
		}	
		
	}

	
	vector<int> getGridVectorPos()
	{
		return getVectPos();
	}
	vector<int> getTileVectorPos(int i)
	{
		return tiles.at(i).getVectPos();
	
	}


	void setTilePosition(Tile &t, int gridsize, int tilesize)
	{
		if (t.getID() > 0)
		{
			
			t.setPosY(this->getPosY());

			if (t.getID() % modulous == 0)
			{
				t.setPosX(this->getPosX());
				t.setPosZ(tiles.at(t.getID() - gridsize).getPosZ() - tilesize);
			}
			else
			{
				t.setPosX(tiles.at(t.getID() - 1).getPosX() + gridsize);
				t.setPosZ(tiles.at(t.getID() - 1).getPosZ());
			}
		}
		else if (t.getID() <= 0)
		{
			t.setPosition(this->getPosX(), this->getPosY(), this->getPosZ());
		}
		else
		{
			cout << "\n====================================================================\n";
		}
	
	
	}
	void consolePrintGrid()
	{
		for (int i = 0; i < modulous*modulous; i++)
		{
			if (i % modulous == 0)
			{
				cout << "\n";
			}
				
			//cout << "\n";
			cout << "[(" << i;
			cout << ")"  << tiles.at(i).getPosX();
			cout << ", " << tiles.at(i).getPosY();
			cout << ", " << tiles.at(i).getPosZ();
			cout << " ]";

		}
	
	
	}
	void consolePrintFloorGrid()
	{
		cout << "\n ===================================================\nGRID: \n";
		cout << "Dirty Tiles: " << iDirtyAmount << endl;
		for (int i = 0; i < modulous*modulous; i++)
		{
			if (i % modulous == 0)
			{
				cout << "\n";
			}

			//cout << "\n";
			cout << "[" <<tiles.at(i).getTileValue() << "]";

		}


	}


	void LoadGrid(const string& fileName, int tilesize)
	{
		int x = 0;
		ifstream file;
		file.open((fileName).c_str());

		string line;

		if (file.is_open())
		{
			//cout << "\n\nFILE " << fileName << " is open" << endl;
			
			while (file.good())
			{				
				getline(file, line);			
				
				int linesize = line.size();

				for (int i = 0; i < linesize; i++)
				{
					char currentChar = line.at(i);
					if (currentChar == ' ')
					{
						continue;
					}
					else
					{ 
						Tile t(tilesize);
						t.setID(x);
						t.setTileValue(currentChar);
						tiles.push_back(t);					
						x++;
					}
				}				
			}
		}
		else
		{
			cerr << "UNABLE OPEN FILE" << fileName << endl;
		}

		int a_sqrt = sqrt(x);
		int b_sqrt = a_sqrt;
		//cout << x << "<-------------x\n";
		if (a_sqrt == b_sqrt);
		{	
			modulous = a_sqrt;	
			//cout << modulous << "<-------------Mod\n";
			for (int i = 0; i < x; i++)
			{
				
				this->setTilePosition(this->tiles.at(i), modulous, tilesize);
				//this->tiles.at(i).printTileInfo();

			}
		}

		cout <<"\n GRID SIZE: " << (modulous * modulous) << endl;
		//this->consolePrintGrid();
	}

	void setTileValue(int id, char val)
	{
		
		this->tiles.at(id).setTileValue(val);
	
	}

	int  getTileID(int id)
	{
	
		return this->tiles.at(id).getID();
	
	}

	char getTileValue(int id)
	{
		return this->tiles.at(id).getTileValue();
	}

	void setTileVisited(int id)
	{
		this->tiles.at(id).setIsVisited(true);
		
	}
	void setNeigborsFound(int id)
	{
		this->tiles.at(id).setIsNeigborsFound(true);
	
	}

	bool isTileVisited(int id)
	{

		return this->tiles.at(id).isVisited();
	}

	bool isTileNeighborsFound(int id)
	{
		return this->tiles.at(id).isNeigborsFound();
	}

	bool isTileClean(int id)
	{
		return this->tiles.at(id).isClean();
	
	}
	
	int getDirtyAmount()
	{
		return this->iDirtyAmount;
	}

	void decreaseDirtyAmount()
	{
		this->iDirtyAmount -= 1;
	
	}

	//Tile getTile(unsigned int ID)
	//{
	//	return this->tiles.at(ID);
	//
	//}

	int getMod()
	{
		return modulous;
	}
};
#endif // !CLASS_GRID_H

