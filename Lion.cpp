#include <string>
#include "Lion.h"
#include <ctime>
using namespace std;


	

	lion::lion(void){
	starveCount = 0;
	moved = false;
	breedCount =0;
	breedNumber =7;
	;
	}//default Constructor
	lion::lion(World *world, int x, int y ){
	this->world = world;
	this->x = x;
	this->y = y;
	moved = false;
	};//Constructor with Prams
	lion::~lion(){};//deconstructor

	//method to handle moving for the lion
	void lion::move(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20])
	{
	int open[8][2] ={{NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL}};

	int eat[8][2] ={{NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL}};
	int rando;
	int count = 0;
	int eatCount =0;
	upper = upper+n;
	upper2=upper2+n2;
	for(n; n < upper; n++)
	{

		for(int no = n2; no < upper2; no++)
		{
			if(n != pos || no != pos2)
			{
				if(grid[n][no] != NULL && grid[n][no]->getSpecies()=="ANT")
				{
					eat[eatCount][0] = n;
					eat[eatCount][1] = no;
					eatCount++;

				}else{
					open[count][0] = n;
					open[count][1] = no;
					count++;
				}
			}//end if
		}//end inner for
	}//end outter for
	if(eatCount > 0)
	{
		srand(time(0)); //seed with time
		rando = (0 + rand() %eatCount);
					grid[eat[rando][0]][eat[rando][1]]->~Organism();
					grid[eat[rando][0]][eat[rando][1]]=this;
					grid[pos][pos2] = NULL;
					starveCount=0;
	}else{
	
	srand(time(0)); //seed with time
	rando = (0 + rand() %8);
	if(open[rando][0] == NULL){
	starveCount++;
	}else if(grid[open[rando][0]][open[rando][1]] == NULL){
	grid[open[rando][0]][open[rando][1]] = this;
	grid[pos][pos2] = NULL;
	starveCount++;
	}else{
	starveCount++;}
	}
	breedCount++;
}//end method move.

	//Breeding method
	void lion::spawn(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20])
	{
		if(breedCount == breedNumber)
		{
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
				}
				
			}//end inner for
		}//end outter for
		if(count == 0){

		}else{
		int rando;
		srand(time(0)); //seed with time
		rando = (0 + rand() %count);
		grid[open[rando][0]][open[rando][1]] = new lion;
		
		breedCount=0;
		}//end If Count
	}//end if breedCount = breedNumber
		
}//end method move.


	//a method to return which species this is
	string lion::getSpecies(){
		return "LION";
		
	};

	
	
	void lion::endTurn()
	{
		moved = true;
	};

	bool lion::getMoved()
	{
		return moved;
	};

	void lion::isTurn()
	{
		moved = false;
	};

	void lion::Starve(int x, int y, Organism *grid[][20])
	{
		if(starveCount >= 3)
		{
			grid[x][y]->~Organism();
			grid[x][y]=NULL;
		}

	};
	
//	 ostream& operator<<( ostream &output, Organism *organism ){};

	