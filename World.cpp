#include <iostream>
#include <string>
#include "World.h"
#include "Organism.h"
#include "Ant.h"
#include "Lion.h"
#include <ctime>
#define _VARIADIC_MAX = 10;

using namespace std;

Organism *grid[GRID_HEIGHT][GRID_WIDTH];



World::World()
{
   int i,j;
   for (i=0; i<GRID_HEIGHT; i++)
   {
       for (j=0; j<GRID_WIDTH; j++)
       {
           grid[i][j]=NULL;     
       }
   }
  

   grid[5][5] = new lion();
   grid[15][15] = new lion();
   grid[10][10] = new lion();
   grid[15][5] = new lion();
   grid[5][15] = new lion();

   int antPlace = 100;
   srand(time(0)); //seed with time
   int rando, rando2;
	
   do
   {
	rando = (0 + rand() %GRID_HEIGHT);
	rando2 = (0 + rand() %GRID_WIDTH);

	if(grid[rando][rando2] == NULL)
	{
		grid[rando][rando2] = new ant;
		antPlace--;
	}

   }while(antPlace > 0);
}
 
	World::~World(){};
	void World::setTurns(){
		for(int x=0;x<GRID_HEIGHT;x++)
		{
			for(int y=0;y<GRID_WIDTH;y++)
			{
				if(grid[x][y] != NULL)
				{
					grid[x][y]->isTurn();
				}//end if !NULL
			}//end inner for
		}//end outter for
	}//end set turn

	string World::print(int x, int y)
	{
		if(grid[x][y] != NULL){
		if(grid[x][y]->getSpecies() == "ANT")
		{
			return "O";	
		}else{
			return "X";
		}
		}else{
			return " ";
		}
		
	};

	



	void World::starve()
	{
		for(int x=0;x<GRID_HEIGHT;x++)
		{
			for(int y=0;y<GRID_WIDTH;y++)
			{
				if(grid[x][y] != NULL)
				{
					if(grid[x][y]->getSpecies() == "LION")
					{
						dynamic_cast<lion*>(grid[x][y])->Starve(x,y,grid);
					}//end if Lion

				}//end if !NULL
			}//end inner for
		}//end outter for
	};

	void World::move(string type){
		for(int x=0;x<GRID_HEIGHT;x++)
		{
			for(int y=0;y<GRID_WIDTH;y++)
			{
		
				if(grid[x][y] != NULL)
				{ 
					bool thing = grid[x][y]->getMoved();
					if(thing == false && grid[x][y]->getSpecies() == type)
					{
						if(x > 0 && x < (GRID_HEIGHT -1) && y > 0 && y < (GRID_WIDTH -1))
						{
						//middle
						grid[x][y]->endTurn();
						grid[x][y]->move(-1+x,-1+y, 3, 3, x, y, grid);
						}
						else if(x == 0 && y == 0)
						{
						//top left
						grid[x][y]->endTurn();
						grid[x][y]->move(0, 0, 2, 2, x, y, grid);
						}
						else if(x == 0 && y == (GRID_WIDTH -1))
						{
						//top right
						grid[x][y]->endTurn();
						grid[x][y]->move(0+x, -1+y, 2, 1, x, y, grid);
						}
						else if (x == 0)
						{
						//top
						grid[x][y]->endTurn();
						grid[x][y]->move(0+x, -1+y, 2, 3, x, y, grid);
						}
						else if(x==(GRID_HEIGHT-1) && y==0)
						{
						//bottom left
						grid[x][y]->endTurn();
						grid[x][y]->move(0+x,-1+y, 3, 2, x, y, grid);
						}
						else if(y==0)
						{
						//left
						grid[x][y]->endTurn();
						grid[x][y]->move(-1+x, 0+y, 2, 3, x, y, grid);
						}
						else if(x==(GRID_HEIGHT -1)&&y==(GRID_WIDTH -1))
						{
						//bottom right
						grid[x][y]->endTurn();
						grid[x][y]->move( -1+x, -1+y, 2, 2, x, y, grid);
						}
						else if(y==(GRID_WIDTH -1))
						{
						//right
						grid[x][y]->endTurn();
						grid[x][y]->move(-1+x, -1+y, 3, 2, x, y, grid);
						}
						else if(x==(GRID_HEIGHT -1))
						{
						//bottom
						grid[x][y]->endTurn();
						grid[x][y]->move(-1+x, -1+y, 2, 3, x, y, grid);
						}
					}
				}//end if null	
			}//end inner if
		}//end outer if

	};
	void World::breed(string type){
	for(int x=0;x<GRID_HEIGHT;x++)
		{
			for(int y=0;y<GRID_WIDTH;y++)
			{
		
				if(grid[x][y] != NULL)
				{ 
					if(grid[x][y]->getSpecies() == type)
					{
						if(x > 0 && x < (GRID_HEIGHT -1) && y > 0 && y < (GRID_WIDTH -1))
						{
						//middle
						grid[x][y]->spawn(-1+x,-1+y, 3, 3, x, y, grid);
						}
						else if(x == 0 && y == 0)
						{
						//top left
						grid[x][y]->spawn(0, 0, 2, 2, x, y, grid);
						}
						else if(x == 0 && y == (GRID_WIDTH -1))
						{
						//top right
						grid[x][y]->spawn(0+x, -1+y, 2, 1, x, y, grid);
						}
						else if (x == 0)
						{
						//top
						grid[x][y]->spawn(0+x, -1+y, 2, 3, x, y, grid);
						}
						else if(x==(GRID_HEIGHT-1) && y==0)
						{
						//bottom left
						grid[x][y]->spawn(0+x,-1+y, 3, 2, x, y, grid);
						}
						else if(y==0)
						{
						//left
						grid[x][y]->spawn(-1+x, 0+y, 2, 3, x, y, grid);
						}
						else if(x==(GRID_HEIGHT -1)&&y==(GRID_WIDTH -1))
						{
						//bottom right
						grid[x][y]->spawn( -1+x, -1+y, 2, 2, x, y, grid);
						}
						else if(y==(GRID_WIDTH -1))
						{
						//right
						grid[x][y]->spawn(-1+x, -1+y, 3, 2, x, y, grid);
						}
						else if(x==(GRID_HEIGHT -1))
						{
						//bottom
						grid[x][y]->spawn(-1+x, -1+y, 2, 3, x, y, grid);
						}
					}
				}//end if null	
			}//end inner if
		}//end outer if
	
	};
	

	//ostream& operator<<( ostream &output, World &world ){};

