#include <iostream>

#ifndef ROBOT_H
#define ROBOT_H
//Robot Class
class Robot
{
public:
	//constrcutor
	Robot();
	Robot(int x, int y) {
		xLocation = x;
		yLocation = y;
		cargoBed = false;
		load = '.';}

	//Setters
	void setX(int x);
	void setY(int y);
	void setCargo(bool cargo);
	void setLoad(char load);
	//Getters
	int getX();
	int getY();
	bool getCargo();
	char getLoad();
	//Other Functions
	bool moveTo(int x, int y);
	bool pickup(int x, int y);
	void printRobot();
	bool dropOff(int x, int y);

	
private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;
};
#endif