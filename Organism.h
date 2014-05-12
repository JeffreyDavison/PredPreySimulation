#ifndef _Organism_H
#define _Organism_H

#include <iostream>

using namespace std;

class World;

class Organism
{
protected:
	int x;
	int y;
	int width;
	int height;
	bool moved;
	World *world;
	int breedCount;
	int breedNumber;

	enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	Organism();
	Organism( World *world, int width, int height );
	virtual ~Organism();

	 virtual void move(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20])=0;
	 virtual void spawn(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20])=0;
	 virtual string getSpecies()=0;
	//virtual string getSpecies();

	 virtual void endTurn()=0;
	 virtual void isTurn()=0;
	 virtual bool getMoved()=0;

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
