#include <string>
#include <iomanip>
#include <cmath>
#include <iostream>
#include "ROBOT.h"
using namespace std;

// Global 2 dimensional arry [10][10]
char grid[10][10];

using namespace std;
//Default Constructor
Robot::Robot() {
	xLocation = 0;
	yLocation = 0;
	cargoBed = false;
	load = '.';

}

//If (x,y) are in the correct grid parameters move plus 1 until they reach given value
bool Robot::moveTo(int x, int  y)
{
	if (x <= 10 && x >= -10 && y <= 10 && y >= -10)
	{
		if (x > 0)
		{
			for (int i = 0; i <= x; i++)
			{
				xLocation = i;
			}
		}
		if (x < 0)
		{
			for (int i = 0; i >= x; i--)
			{
				xLocation = i;
			}
		}
		if (y > 0)
		{
			for (int i = 0; i <= y; i++)
			{
				yLocation = i;
			}
		}
		if (y < 0)
		{
			for (int i = 0; i >= y; i--)
			{
				yLocation = i;
			}
		}
	}
	else
	{
		false;
	}
	return 0;
}
//verifies that there is a load at x,y location and that the cargoBed is Empty.
//Then makes cargoBed True & picks up load.
bool Robot::pickup(int x, int y)
{
	if (grid[x][y] != '.' && cargoBed == false)
	{
		Robot::moveTo(x, y); // Move to Location
		load = grid[x][y]; // Pick up Load
		cargoBed = true; //Place load in CargoBed.
		grid[x][y] = '.';
	}
	else
	{
		cout << " Cargo bed is full or there is no load to pick up. \n";
	}

	return 0;

}



//Sets cargoBed to true if robot has a load.
//Sets cargoBed to false if robot does not have a load.
void Robot::setCargo(bool cargo) {
	if (load > 0)
	{
		cargoBed = true;
	}
	else
		cargoBed = false;
}
//Sets Robot's load to char value and makes cargoBed true.
void Robot::setLoad(char robotLoad) {
	load = robotLoad;
	cargoBed = true;
}
// Set Functions for XLocation & YLocation. Lets the robot only move 1 space at a time.
void Robot::setX(int x) {

	int diffInX = xLocation - x;
	int xSteps = abs(diffInX);
	if (diffInX > 0)
	{
		for (int i = 0; i < xSteps; i++)
		{
			xLocation--;
		}
	}
	else
	{
		for (int i = 0; i < xSteps; i++)
		{
			xLocation++;
		}
	}

}
void Robot::setY(int y) {

	int diffInY = yLocation - y;
	int ySteps = abs(diffInY);
	if (diffInY > 0)
	{
		for (int i = 0; i < ySteps; i++)
		{
			yLocation--;
		}
	}
	else
	{
		for (int i = 0; i < ySteps; i++)
		{
			yLocation++;
		}
	}

}
bool Robot::dropOff(int x, int y)
{
	if (grid[x][y] == '.' && cargoBed == true)
	{
		Robot::moveTo(x, y); // Move to Location
		grid[x][y] = load; // Drop Off
		cargoBed = false; // Cargo bed is empty
		load = '.';
		xLocation = x;
		yLocation = y;

	}

	return 0;
}

//Get Functions
int Robot::getX() { return xLocation; }
int Robot::getY() { return yLocation; }
bool Robot::getCargo() { return cargoBed; }
char Robot::getLoad() { return load; }
void Robot::printRobot()
{
	cout << " The Robot X Location is = " << getX() << "\n";
	cout << " The Robot Y Location is = " << getY() << "\n";
	cout << " The Robot Load is = " << getLoad() << "\n";
	cout << " Robot has a load (0 is False & 1 is True): " << getCargo();
}
//Print Grid Function
void print2D(char grid[][10])
{
	for (int row = 0; row < 10; row++)
	{
		cout << "\n";
		for (int column = 0; column < 10; column++)
		{
			cout << grid[row][column];

		}
	}
}
// Overload << operator
ostream& operator<<(ostream& out, Robot r)
{
	out << "(" << r.getX() << "," << r.getY() << ")" << ":" << r.getLoad();

	return out;
}

//Dynamically create new robot and pick up all remaining loads.
void clear(char grid[][10])

{

	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			if (grid[row][column] != '.')
			{
				Robot* robotArrayPointer = new Robot(row, column);
				robotArrayPointer->pickup(row, column);
				delete robotArrayPointer;
			}
		}
	}

}


int main()
{//Create Grid
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			grid[row][column] = '.';
		}
	}
	// Create 2 Robot Objects and place 'B' & 'C' on Grid.
	grid[3][8] = 'B';
	grid[2][6] = 'C';
	print2D(grid);
	Robot r1(2, 2);
	Robot r2(1, 1);
	cout << "\n" << "R1 = " << r1 << endl;
	cout << "R2 = " << r2 << endl;
	// ---------------------Part J-----------------
	r1.moveTo(9, 2);
	r2.moveTo(3, 4);
	print2D(grid);
	cout << "\n" << "R1 = " << r1 << endl;
	cout << "R2 = " << r2 << endl;
	// ---------------------Part K-----------------
	r1.pickup(3, 8);
	r1.dropOff(9, 9);
	print2D(grid);
	cout << "\n" << "R1 = " << r1 << endl;
	cout << "R2 = " << r2 << endl;
	//----------------------Part L-------------------
	r2.pickup(2, 6);
	r2.dropOff(0, 0);
	print2D(grid);
	cout << "\n" << "R1 = " << r1 << endl;
	cout << "R2 = " << r2 << endl;

	//------------------Part M-----------------------
	cout << " Board Cleared ";
	clear(grid);
	print2D(grid);


	return 0;
}

