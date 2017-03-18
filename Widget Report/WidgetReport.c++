/*
 * WidgetReport.c++
 *
 *  Created on: Sep 24, 2016
 *      Author: Sam
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class WidgetReport
{
public:
    WidgetReport(ifstream& in);  // constructor
    void showReport();

private:
    int count_int;
    int state_total;
    int plant_total;
    int dept_total;
    int grand_total;

    string state;
    string plant;
    string dept;
    string empid;
    string name;
    string count;

    ifstream& input;  // reference to the input stream

    void print();
    void statistic();
    void totalWedget(int i, string prev_dept, string prev_plant, string prev_state);
};

const string INPUT_FILE_NAME = "widgets.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME.c_str());
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    WidgetReport wegitReport(input);
    wegitReport.showReport();

    input.close();
    return 0;
}


WidgetReport::WidgetReport(ifstream& in) : input(in)
{
	// initialize the value of member variables
    input >> state >> plant >> dept >> empid >> name >> count;
    // set all integer type variables to 0
    count_int = state_total = plant_total = dept_total = grand_total = 0;
}


void WidgetReport::showReport()
{
	string firstName, lastName;
	string prev_state, prev_plant, prev_dept;

	// print the header
	print();
	cout << "\n";

	input >> state >> plant >> dept >> empid >> firstName >> lastName >> count;
	name = firstName + " " + lastName;
	prev_state = state;
	prev_plant = plant;
	prev_dept = dept;

	statistic();

	print();

    while(input.good()){
    	input >> state >> plant >> dept >> empid >> firstName >> lastName >> count;
    	name = firstName + " " + lastName;

    	// totalWedget is triggered if state, plant or dept changes
    	if(prev_state != state) totalWedget(3, prev_dept, prev_plant, prev_state);
    	else if(prev_plant != plant) totalWedget(2, prev_dept, prev_plant, prev_state);
    	else if(prev_dept != dept) totalWedget(1, prev_dept, prev_plant, prev_state);

    	prev_state = state;
    	prev_plant = plant;
    	prev_dept = dept;

     	//if(input.eof()) break; //revised needed

    	statistic();

    	print();
       }

    totalWedget(4, prev_dept, prev_plant, prev_state);
}


// print out the data
void WidgetReport::print()
{
	cout.width(5);
	cout << right << state;
	cout.width(6);
	cout << right << plant;
	cout.width(5);
	cout << right << dept;
	cout.width(6);
	cout << right << empid;
	cout.width(6);
	cout << right << count;
	cout << " " << name << "\n";
}


// calculate the total widgets of each state, plant and department
void WidgetReport::statistic()
{
	stringstream(count) >> count_int;
	state_total += count_int;
	plant_total += count_int;
	dept_total += count_int;
	grand_total += count_int;
}


// print out total widgets of the coordinated state, plant and department
void WidgetReport::totalWedget(int i, string prev_dept, string prev_plant, string prev_state)
{
	if(i == 1 || i == 2 || i == 3 || i == 4)
	{
		cout << "\n";
		cout.width(28);
		cout << right << dept_total << " TOTAL FOR DEPT  " << prev_dept << " *\n";
		dept_total = 0;

		if(i == 2 || i == 3 || i == 4)
		{
			cout.width(28);
			cout << right << plant_total << " TOTAL FOR PLANT " << prev_plant << " **\n";
			plant_total = 0;

			if(i == 3 || i == 4)
			{
				cout.width(28);
				cout << right << state_total << " TOTAL FOR STATE " << prev_state << " ***\n";
				state_total = 0;

				if(i == 4)
				{
					cout << "\n";
					cout.width(28);
					cout << right << grand_total << " GRAND TOTAL        " << "****\n";
				}
			}
		}
	}
	if(i == 1 || i == 2 || i == 3) cout << "\n";
}
