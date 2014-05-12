#include <string>
#include "Ant.h"
#include <ctime>
using namespace std;


	

	ant::ant(void){
	moved = false;
	breedCount = 0;
	breedNumber = 4;
	}//default Constructor

	ant::ant(World *world, int width, int height ){
	moved = false;
	};//Constructor with Prams
	ant::~ant(){};//deconstructor

	//method to handle moving for the ant
	void ant::move(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20])
	{
	int open[4][2] ={{NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL},
					 {NULL,NULL,}};
					 
	int count = 0;
	upper = upper+n;
	upper2=upper2+n2;
	for(n; n < upper; n++)
	{

		for(int no = n2; no < upper2; no++)
		{
			if((n == pos && no != pos2)||(n != pos && no == pos2))
			{
					open[count][0] = n;
					open[count][1] = no;
					count++;
			}//end if
		}//end inner for
	}//end outter for
	
	int rando;
	srand(time(0)); //seed with time
	rando = (0 + rand() %4);
	if(open[rando][0] == NULL){
	}else{
	if(grid[open[rando][0]][open[rando][1]] == NULL){
	grid[open[rando][0]][open[rando][1]] = this;
	grid[pos][pos2] = NULL;
	}else{
	}
	}
	breedCount++;
	
}//end method move();.



	

	//Breeding method
	void ant::spawn(int n, int n2, int upper, int upper2, int pos, int pos2, Organism *grid[][20]){
	
	if(breedCount == breedNumber)
	{	
	int open[4][2] ={{n,n2},
					 {n,n2},
					 {n,n2},
					 {n,n2,}};
					 
	int count = 0;
	upper = upper+n;
	upper2=upper2+n2;
	for(n; n < upper; n++)
	{

		for(int no = n2; no < upper2; no++)
		{
			if((n == pos && no != pos2)||(n != pos && no == pos2))
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
	if(count == 0){
		breedCount =0;
	}else{
	int rando;
	srand(time(0)); //seed with time
	rando = (0 + rand() %count);

	grid[open[rando][0]][open[rando][1]] = new ant;
	breedCount =0;
	}
	
	
	}
}//end Spawn

	//a method to return which species this is
	
	string ant::getSpecies(){
		return "ANT";
	};

	

	void ant::endTurn()
	{
		moved = true;
	};

	bool ant::getMoved()
	{
		return moved;
	};

	void ant::isTurn()
	{
		moved = false;
	};
	
	//ostream& operator<<( ostream &output, Organism *organism ){};

	