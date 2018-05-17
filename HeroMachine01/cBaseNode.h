#ifndef BASE_NODE_H
#define BASE_NODE_H
#include <vector>

#include "cBaseEntity.h"
using namespace std; 
class BaseNode : public BaseEntity
{
private: 
	int X = 0;
	int Y = 0;
	int Z = 0;

	vector<int> vecPos;

public:
	BaseNode() {}
	virtual ~BaseNode() {}
	BaseNode(int x, int y, int z)
	{
		X = x;
		Y = y;
		Z = z;

		vecPos.push_back(X);
		vecPos.push_back(Y);
		vecPos.push_back(Z);
	}
	void setPosition(int x, int y, int z)
	{
		X = x;
		Y = y;
		Z = z;

		vecPos.push_back(X);
		vecPos.push_back(Y);
		vecPos.push_back(Z);
	}

	void setPosX(int x)
	{
		X = x;
	}
	void setPosY(int y)
	{
		Y = y;
	}
	void setPosZ(int z)
	{
		Z = z;
	}
	int getPosX()
	{
		return X;
	}
	int getPosY()
	{
		return Y;
	}
	int getPosZ()
	{
		return Z;
	}

	vector<int> getVectPos()
	{
		return vecPos;
	}
};
#endif // !BASE_NODE_H

