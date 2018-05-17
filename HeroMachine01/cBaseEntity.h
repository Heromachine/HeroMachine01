#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

class BaseEntity
{
private:
	unsigned int ID = 0;

public:
	BaseEntity() {}
	BaseEntity(int id) { ID = id; }

	void setID(int id) { ID = id; }
	unsigned int getID() { return ID; }




};

#endif // !BASE_ENTITY_H

