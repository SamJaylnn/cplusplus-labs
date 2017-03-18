/*
 * StudentScores.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Sam
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";

typedef string* StrArrayPtr;
typedef int* IntArrayPtr;

void createArray(int numOfStu, int lineCount, string line, StrArrayPtr& nameArray, IntArrayPtr* &scoreArray);
void printTheOutput(int numOfStu, StrArrayPtr firstLine, StrArrayPtr nameArray, IntArrayPtr* scoreArray);

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME.c_str());
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    StrArrayPtr nameArray, firstLine = new string[2];
    IntArrayPtr* scoreArray;
    string line;

    int lineCount = 0, numOfStu = 0;
	while(getline(input, line))
	{
		lineCount++;
		if (lineCount == 1)
		{

			int i = 0;
			stringstream ssin(line);

			// get the first line parameter, including course name and student number
			while (ssin.good() && i < 2)
			{
				ssin >> firstLine[i];
				++i;
			}
			stringstream(firstLine[1]) >> numOfStu;
			nameArray = new string[numOfStu];
			scoreArray = new IntArrayPtr[numOfStu];
		}
		else
		{
			createArray(numOfStu, lineCount, line, nameArray, scoreArray); // generate name array and score array; pass
		}
	}
	printTheOutput(numOfStu, firstLine, nameArray, scoreArray); // print out the result

	// delete the arrays
	for (int i = 0; i < numOfStu; i++) delete[] scoreArray[i];

	delete[] scoreArray;
	delete[] nameArray;
	delete[] firstLine;

	return 0;
}


void createArray(int numOfStu, int lineCount, string line, StrArrayPtr& nameArray, IntArrayPtr* &scoreArray)
{
	string firstName, lastName, scoreNumStr;
	int scoreNumInt, arrayRow = lineCount - 2, arrayColum;

	stringstream ssin(line);
	ssin >> firstName;
	ssin >> lastName;

	nameArray[arrayRow] = firstName + " " + lastName;

	ssin >> scoreNumStr;
	stringstream(scoreNumStr) >> scoreNumInt;

	scoreArray[arrayRow] = new int[scoreNumInt + 1];
	scoreArray[arrayRow][0] = scoreNumInt;

	for(arrayColum = 1; arrayColum <= scoreNumInt; arrayColum++)
	{
		ssin >> scoreArray[arrayRow][arrayColum];
	}
}


void printTheOutput(int numOfStu, StrArrayPtr firstLine, StrArrayPtr nameArray, IntArrayPtr* scoreArray)
{
	cout << "STUDENT SCORES for " << firstLine[0] << endl << endl;
	for (int i = 0; i < numOfStu; i++)
	{
		cout << nameArray[i] << endl;
		if (scoreArray[i][0] == 0) cout << "   (none)";
		else
		{
			for (int j = 1; j <= scoreArray[i][0]; j++)
			{
				cout.width(5);
				cout << right << scoreArray[i][j];
			}
		}
		cout << "\n" << "\n";
	}
}
