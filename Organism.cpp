
#include <iostream>
#include "Organism.h"
#include "World.h"
#include <ctime>
using namespace std;
	int x;
	int y;
	int width;
	int height;
	bool moved = false;
	World *world;

	enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };


	Organism::Organism(void){};
	Organism::Organism( World *world, int width, int height){moved = false;};
	Organism::~Organism(){};

	void Organism::move(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]){
	int open[8][2] ={{n,n2},
					 {n,n2},
					 {n,n2},
					 {n,n2},
					 {n,n2},
					 {n,n2},
					 {n,n2},
					 {n,n2}};

	int count = 0;
	upper = upper+n;
	upper2=upper2+n2;
	for(n; n < upper; n++)
	{

		for(int no = n2; no < upper2; no++)
		{
			if(n != pos || no != pos2)
			{
				if(grid[n][no] == NULL)
				{
					open[count][0] = n;
					open[count][1] = no;
					count++;
				}
			}//end if
		}//end inner for
	}//end outter for
	int rando;
	srand(time(0)); //seed with time
	rando = (0 + rand() %count);

	grid[open[rando][0]][open[rando][1]] = this;
	grid[pos][pos2] = NULL;
	
	};
	void Organism::spawn(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]){};
	string getSpecies(){return "";};
	

	void setPosition( int setx, int sety ){x= setx;y = sety;};

	//a method to set the 
	void Organism::endTurn(){moved = true;};
	bool Organism::getMoved(){return moved;}
	void Organism::isTurn(){moved = false;};

	ostream& operator<<( ostream &output, Organism *organism );

