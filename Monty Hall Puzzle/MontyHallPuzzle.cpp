/*
 * MontyHallPuzzle.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: Sam
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>     /* srand, rand */

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

void simulate(int sequence, int& win1, int& win2);
Door hideCar();
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);
Door makeFirstChoice();
Door makeSecondChoice(Door firstDoor, Door openedDoor);

Door randomDoor(Door selectedDoor);
Door randomDoorNot(Door aDoor, Door anotherDoor);

void printHeader();

/**
 * Main
 */
int main()
{
    int win1 = 0, win2 = 0;

    srand(time(NULL));  // seed the random number generator
    printHeader();

    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);

    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
}

/***** Complete this program. ****/
void printHeader()
{
	cout << "    #     Car   First  Opened  Second    Win    Win" << endl;
	cout << "         here  choice    door  choice  first second" << endl;
}


void simulate(int sequence, int& win1, int& win2)
{
	Door carBehindDoor = hideCar();    // select a door with a car randomly
	Door firstChoiceDoor = makeFirstChoice();    // make first choice
	Door openedDoor = openDoor(firstChoiceDoor, carBehindDoor);    // Monty opens a door
	Door secondChoiceDoor = makeSecondChoice(firstChoiceDoor, openedDoor);   // second choice

	cout << setw(5) << sequence;
	cout << setw(8) << carBehindDoor;
	cout << setw(8) << firstChoiceDoor;
	cout << setw(8) << openedDoor;
	cout << setw(8) << secondChoiceDoor;

	// To see whether the first or the second choice wins
	if  (firstChoiceDoor == carBehindDoor)
	{
		win1++;
		cout << setw(7) << "yes" << setw(7) <<endl;
	}
	else if (secondChoiceDoor == carBehindDoor)
	{
		win2++;
		cout << setw(14) << "yes" <<endl;
	}
}


Door hideCar()
{
	return rand()%3+1;
}


Door makeFirstChoice()
{
	return rand()%3+1;
}


Door openDoor(Door firstChoiceDoor, Door carBehindDoor)
{
	Door openedDoor;

	if (firstChoiceDoor == carBehindDoor)        // first door choice was correct
		openedDoor = randomDoor(carBehindDoor);  // Monty randomly opens one of the other two doors
	else
		openedDoor = randomDoorNot(firstChoiceDoor, carBehindDoor);  // first door choice was incorrect
																	 //  Monty opens the door hides a goat

	return openedDoor;
}


Door randomDoor(Door selectedDoor)
{
	Door doorNum[3] = {1, 2, 3};

	if (selectedDoor != 3)
	{
		for (int i = 0; i <=1; i++)
		{
			if (doorNum[i] == selectedDoor) //Exchange the selected Door number
			{								//with the last element of the array
				Door temp = doorNum[2];
				doorNum[2] = doorNum[i];
				doorNum[i] = temp;
			}
		}
	}

	return doorNum[rand()%2];				//Get a random door which is
}											//not selected at first round


Door randomDoorNot(Door aDoor, Door anthorDoor)
{
	for (Door doorWillOpen = 1; doorWillOpen <= 3; doorWillOpen++)
	{
		if ((doorWillOpen != aDoor) && (doorWillOpen != anthorDoor))
			return doorWillOpen;			//return the door hides a goat
	}
}


Door makeSecondChoice(Door firstDoor, Door openedDoor)
{
	for (Door secondDoor = 1; secondDoor <= 3; secondDoor++)
	{
		if ((secondDoor != firstDoor) && (secondDoor != openedDoor))
			return secondDoor;			//return the door which is not selected
	}
}




