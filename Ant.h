#ifndef _Ant_H
#define _Ant_H

#include "Organism.h"



class ant : public Organism
{
private:
	
public:
	bool moved;
	ant(); 
	ant( World *world, int width, int height );
	virtual ~ant();

	void move(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]);
	void spawn(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]);
	string getSpecies();

	void endTurn();
	void isTurn();
	 bool getMoved();
};

#endif
