/*
Creator: Jeffrey Davion
Language: c++

This assignment was to make a simulation of ants vs ant Lions. 
in the simulations ants can move up down left and right, ant lions can move in all directions.
if an Ant Lion moves onto an ant it will eat it. 
if the ant Lion goes too many turns without eating it will die. 
both creatures breed after a set number of turns. the simulation runs for 100 ticks and will pause. 

To start the simulation at start and pause press enter. 


*/


#include <iostream>
#include <string>
#include "World.h"
#include <windows.h> // WinApi header
#include <stdio.h>
#include <time.h>



World WorldObj;

using namespace std;
int windowSize = system("mode con lines=23 cols=50");


void printboard(int ticks);
bool count(int ticks);
void delay(int milliseconds);


int main(){
	int ticks =0;
	bool ELE = false;
	do
	{
	count(ticks);
	printboard(ticks);
	cin.get();
	for(int i2=0;i2<100;i2++)
	{
	ELE = count(ticks);
	if(ELE ==false){
	printboard(ticks);
	delay(1000);
	WorldObj.setTurns();
	WorldObj.move("LION");//move lions
	WorldObj.move("ANT");//move ants
	WorldObj.starve();//starve lions
	WorldObj.breed("ANT");//breed ants
	WorldObj.breed("LION");//breed lions
	
	ticks++;//ticks plus
	}
	
	
	if(ELE == true)//if ele exit
		i2 = 100;
	}
	}while(ELE != true);
	count(ticks);
	printboard(ticks);

	cin.get();
	return 0;
}
//print board with colour
void printboard(int ticks)
{
	HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int ants = 0;
	int lions = 0;

	for(int i=0;i<20;i++)
	{
		cout << endl;
		for(int i2=0;i2<20;i2++)
		{
		if(WorldObj.print(i,i2) == "O")
		{
		SetConsoleTextAttribute(hConsole, 9);
		ants++;
		}else if(WorldObj.print(i,i2) == "X")
		{
		SetConsoleTextAttribute(hConsole, 12);
		lions++;
		}else if(WorldObj.print(i,i2) == " "){
		SetConsoleTextAttribute(hConsole, 0);
		}
		
		cout << WorldObj.print(i,i2);

		}//end inner for
	}//end outter for

	SetConsoleTextAttribute(hConsole, 15);
	//cout << endl <<"Ticks: " << ticks << "     Ants: " << ants << "     Lions: " << lions << endl;
	cout<<endl;
	
}//end Print Board

//count the ants and lions
bool count(int ticks)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int ants = 0;
	int lions = 0;

	for(int i=0;i<20;i++)
	{
		cout << endl;
		for(int i2=0;i2<20;i2++)
		{
		if(WorldObj.print(i,i2) == "O")
		{
		ants++;
		}else if(WorldObj.print(i,i2) == "X")
		{
		lions++;
		}
		}//end inner for
	}//end outter for

	if(ants==0 || lions == 0)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 15);
		cout << " ELE at " << ticks << "  Ticks.    Ants: " << ants << "     Lions: " << lions << endl;
		return true;
	}else{
		cout << " Ticks: " << ticks << "  Ants: " << ants << "     Lions: " << lions << endl;
		return false;
	}


}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}