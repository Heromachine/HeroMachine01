#ifndef CLASS_VACCUM_H
#define CLASS_VACCUM_H
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <time.h>  
#include "cBaseNode.h"
#include "Grid.h"

static const string AVAILIBLE_ACTIONS = "RLUD";



class Vaccum : public BaseNode
{
private:
	bool isGridKnown = false;
	Grid gridVac;

	vector<int> goalState;
	vector<int> initState;
	vector <char> moves;

	bool isFinished = false;
	bool isIdle = false;
	int gridSize;
	int stepsTaken = 0;
	int tilesFound = 0;

	//char cSequence = 64;


	//void randInitState();
	//int stateDis(vector<int> pState1, vector<int> pState2);



public:

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Vaccum(Grid &grid, unsigned int tileID, bool bIdleOn)
	{

		if (grid.getTileValue(tileID) == '|')
		{
			cerr << "THIS TILE IS IN ACCESSABLE";
		}
		else
		{
			this->gridSize = grid.getMod();
			Clean03(grid, tileID, tileID, bIdleOn);
		}


	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void Clean(Grid &grid, int currentState)
	
	{
		srand(time(NULL));


		int squaresCleaned = 0;

		int x;

		while (grid.getDirtyAmount() > 0)//(!allclean)
		{		


			squaresCleaned++;
			cout << "\n \n";
			char act = AVAILIBLE_ACTIONS[rand() % 4];

			cout << "\n ACT: " << act << endl;
			cout << "\n CS:  " << currentState << endl;



			switch (act) {

			case 'L':				
				if (!(grid.getTileID(currentState) % gridSize == 0))
				{
					{
						currentState -= 1;
					}
				}
				break;

			case 'R':
				if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
				{
					{
						currentState += 1;
					}

				}
				
				break;

			case 'U':
				if (grid.getTileID(currentState) >= gridSize)
				{
					currentState -= gridSize;
				}
					
				break;

			case 'D':
				if (grid.getTileID(currentState) <= (gridSize * gridSize) - gridSize)
				{
					currentState += gridSize;					
				}

				break;


			default:
				cout << "Invalid action.\n";

			}


			grid.setTileValue(currentState, '0');

		}

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////


	void Clean03(Grid &grid, int previousstate, int currentState, bool bIdleOn)
	{
		++stepsTaken;


		if (bIdleOn)
		if (grid.getDirtyAmount() == 0 || isIdle == true)
		{
			isFinished = true;
			if (isIdle)
			cout << "\n=====RAN INTO SAME TILE: IDLE MODE ON=====\n";
		}



		if (!isFinished)
		{
			if (grid.getTileValue(currentState) == 'x')
			{
				grid.setTileValue(currentState, '0');
				grid.decreaseDirtyAmount();
			}
			else
			if (grid.getTileValue(currentState) == ' ')
			{
				grid.setTileValue(currentState, '-');
			}
			else 
			if (grid.getTileValue(currentState) == '-')
			{
				isIdle = true; 

			}

			grid.setTileVisited(currentState);
			
			vector <int> moves;

			if (grid.isTileNeighborsFound(currentState) == false)
			{
				moves = getNeighbors03(grid, currentState);
				grid.setNeigborsFound(currentState);
			}

			if (moves.size() > 0 && grid.getDirtyAmount() > 0)
			{
				cout << "SIZE OF MOVES: " << moves.size() << endl;
				for (int i = 0; i < moves.size(); i++)
				{
					grid.consolePrintFloorGrid();
					cout << "\nCURRENT STATE " << currentState << endl;
					cout << "Steps Taken: " << stepsTaken << endl;
					if (grid.getDirtyAmount() > 0)
					{
						Clean03(grid, currentState, moves[i], bIdleOn);
					}
					else
						break;

				}
			}
		}



	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void Clean02(Grid &grid, int previousstate, int currentState)
	{
		++stepsTaken;


		if (grid.getDirtyAmount() > 0)
		{

			if (grid.getTileValue(currentState) == 'x')
			{
				grid.setTileValue(currentState, '0');
				grid.decreaseDirtyAmount();
			}
			else
			if (grid.getTileValue(currentState) == ' ')
			{
				grid.setTileValue(currentState, '-');
			}

			grid.setTileVisited(currentState);


			if (system("CLS")) system("clear");
			//grid.consolePrintFloorGrid();

			cout << "\nCURRENT STATE " << currentState << endl;
			cout<<"Steps Taken: "<< stepsTaken << endl;

			vector <int> moves;

			if (grid.isTileNeighborsFound(currentState) == false)
			{
				moves = getNeighbors02(grid, currentState);
				grid.setNeigborsFound(currentState);
			}


			if (moves.size() > 0 && grid.getDirtyAmount() > 0)
			{
				cout << "\nSIZE OF MOVES: " << moves.size() << endl;
				for (int i = 0; i < moves.size(); i++)
				{

					Clean02(grid, currentState, moves[i]);
				}

			}
			//else
			//{

			//	if (grid.getTileValue(currentState) == 'x')
			//	{
			//		grid.setTileValue(currentState, '0');
			//		grid.decreaseDirtyAmount();
			//	}
			//	else
			//		if (grid.getTileValue(currentState) == ' ')
			//		{
			//			grid.setTileValue(currentState, '_');
			//		}

			//	grid.setTileVisited(currentState);
			//	grid.consolePrintFloorGrid();

			//}
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<int> getNeighbors04(Grid &grid, int currentState)
	{
		vector<int> moves;
		int attemps = 0;

		bool done = false;

		while (!done)
		{
			attemps++;
			bool one = false;
			bool two = false;
			bool three = false;
			bool four = false; 


			int chance = (rand() % 4 + 1);
			if (attemps > 4)
			{
				chance = 5;
			}
			switch (chance)
			{				
			case 1:
				//CHECK IF CURRENT NODE FAR LEFT
				if (!one)
				if (!(grid.getTileID(currentState) % gridSize == 0))
				{
					//CHECK IF LEFT NODE IS VISITED
					//if (grid.isTileVisited(currentState - 1) == false)
					moves.push_back(currentState - 1);
					one = true;
					//done = true;
				}
				//break;
			case 2:
				//CHECK IF CURRENT NODE BOTTOM 
				if(!two)
				if ((grid.getTileID(currentState) > (gridSize * gridSize) - gridSize))
				{
					//CHECK IF LOWER NODE IS VISITED
					//if (grid.isTileVisited(currentState + gridSize) == false)
					moves.push_back(currentState + gridSize);
					two = true;
					//done = true;
				}
				//break;
			case 3:
				//CHECK IF CURRENT NODE FAR RIGHT
				if (!three)
				if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
				{
					//CHECK IF RIGHT NODE IS VISITED
					//if (grid.isTileVisited(currentState + 1) == false)
					moves.push_back(currentState + 1);
					three = true;					
					//done = true;
				}
			case 4:
				//CHECK IF CURRENT NODE TOP
				if(!four)
				if ((grid.getTileID(currentState) >= gridSize))
				{
					////CHECK IF UPPER NODE IS VISITED
					//if (grid.isTileVisited(currentState - gridSize) == false)
					moves.push_back(currentState - gridSize);
					four = true;
					//done = true;
				}
			case 5:
				cout << "\nNO MORE MOVES\n";
				done = true;
			}
		}
   		return moves;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<int> getNeighbors03(Grid &grid, int currentState)
	{
		vector<int> moves;

		//CHECK IF CURRENT NODE FAR LEFT
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{
			//CHECK IF LEFT NODE IS VISITED
			//if (grid.isTileVisited(currentState - 1) == false)
			moves.push_back(currentState - 1);

		}
		//CHECK IF CURRENT NODE BOTTOM 
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			//CHECK IF LOWER NODE IS VISITED
			//if (grid.isTileVisited(currentState + gridSize) == false)
			//{
			moves.push_back(currentState + gridSize);
			//}
		}

		//CHECK IF CURRENT NODE FAR RIGHT
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{
			//CHECK IF RIGHT NODE IS VISITED
			//if (grid.isTileVisited(currentState + 1) == false)
			//{
			moves.push_back(currentState + 1);
			//}

		}

		//CHECK IF CURRENT NODE TOP
		if ((grid.getTileID(currentState) >= gridSize))
		{
			////CHECK IF UPPER NODE IS VISITED
			//if (grid.isTileVisited(currentState - gridSize) == false)
			//{
			moves.push_back(currentState - gridSize);
			//}

		}



		return moves;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<int> getNeighbors02(Grid &grid, int currentState)
	{
		vector<int> moves;

		//CHECK IF CURRENT NODE FAR LEFT
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{
			//CHECK IF LEFT NODE IS VISITED
			//if (grid.isTileVisited(currentState - 1) == false)
				moves.push_back(currentState - 1);

		}
		//CHECK IF CURRENT NODE BOTTOM 
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			//CHECK IF LOWER NODE IS VISITED
			//if (grid.isTileVisited(currentState + gridSize) == false)
			//{
				moves.push_back(currentState + gridSize);
			//}
		}
		
		//CHECK IF CURRENT NODE FAR RIGHT
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{
			//CHECK IF RIGHT NODE IS VISITED
			//if (grid.isTileVisited(currentState + 1) == false)
			//{
				moves.push_back(currentState + 1);
			//}

		}

		//CHECK IF CURRENT NODE TOP
		if ((grid.getTileID(currentState) >= gridSize))
		{
			////CHECK IF UPPER NODE IS VISITED
			//if (grid.isTileVisited(currentState - gridSize) == false)
			//{
				moves.push_back(currentState - gridSize);
			//}

		}



		return moves;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////


	vector<int> getNeighbors(Grid &grid, int currentState)
	{
		vector<int> moves;

		//CHECK IF CURRENT NODE FAR LEFT
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{
			//CHECK IF LEFT NODE IS VISITED
			if (grid.isTileVisited(currentState - 1) == false)
				moves.push_back(currentState - 1);
			
		}

		//CHECK IF CURRENT NODE FAR RIGHT
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{
			//CHECK IF RIGHT NODE IS VISITED
			if (grid.isTileVisited(currentState + 1) == false)
			{
				moves.push_back(currentState + 1);
			}
			
		}

		//CHECK IF CURRENT NODE TOP
		if ((grid.getTileID(currentState) >= gridSize))
		{	
			//CHECK IF UPPER NODE IS VISITED
			if (grid.isTileVisited(currentState - gridSize) == false)
			{
				moves.push_back(currentState - gridSize);
			}
			
		}

		//CHECK IF CURRENT NODE BOTTOM 
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			//CHECK IF LOWER NODE IS VISITED
			if (grid.isTileVisited(currentState + gridSize) == false)
			{
				moves.push_back(currentState + gridSize);
			}
			


		}

		return moves;
	}

};
#endif // !CLASS_VACCUM_H

