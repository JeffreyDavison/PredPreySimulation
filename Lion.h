#ifndef _Lion_H
#define _Lion_H

#include "Organism.h"

class lion : public Organism
{
	
private:
	int starveCount;
	bool moved;


public:
	lion();
	lion( World *world, int width, int height );
	virtual ~lion();

	
	void move(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]);
	void spawn(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]);
	string getSpecies();
	
	void endTurn();
	void isTurn();
	bool getMoved();
	void Starve(int x, int y, Organism *grid[][20]);
};

#endif
