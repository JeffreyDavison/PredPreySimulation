#ifndef _WORLD_H
#define _WORLD_H

#include <iostream>

using namespace std;

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class World
{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
	World();
	virtual ~World();

	Organism *getOrganism( int x, int y );
	void setOrganism( Organism *organism, int x, int y );

	void move(string type);
	void starve();
	void breed(string type);
	
	string getSpeciesOrganism(int x, int y);
	string print(int x, int y);
	void setTurns();
	
	friend ostream& operator<<( ostream &output, World &world );

};

#endif
