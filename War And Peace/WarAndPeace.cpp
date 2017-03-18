#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Names to search for.
const string MAKAR = "Makar Alexeevich";
const string MAKAR_LastName = "Alexeevich";
const string JOSEPH = "Joseph Bazdeev";
const string JOSEPH_LastName = "Bazdeev";
const string BORIS = "Boris Drubetskoy";
const string BORIS_LastName = "Drubetskoy";

const string INPUT_FILE_NAME = "WarAndPeace.txt";

vector<string> createNameList(); // create a vector contains the names
vector<string> createLastNameList(); // create a vector contains the last names

void searchTheName(string line, int& line_count, int& name_position, int& nameNum, int& flag, vector<string> nameList, vector<string> lastNameList);
void nameComparison(int i, int& flag, int& name_position, int line_count, string line, string targetName);
void lastNameComparison(int name_position, int line_count, string line, string targetName, string targetLastName);


int main()
{
    // print out the header
    std::cout.width(5);
	std::cout << std::right << "LINE";
    std::cout.width(10);
	std::cout << std::right << "POSITION";
	std::cout << "  " << "NAME" << endl;

	string line;
    ifstream input;
    input.open(INPUT_FILE_NAME.c_str());

    int line_count = 0; // line number
    int name_position = 0; // character position of the first letter of the first name
    int flag = 0; // flag is to indicate if the name splits into two lines
    int nameNum = 0; // name number in the nameList vector

    vector<string> nameList = createNameList();
    vector<string> lastNameList = createLastNameList();

    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

	while (getline(input, line))
	{
		searchTheName(line, line_count, name_position, nameNum, flag, nameList, lastNameList);
	}
    return 0;
}

// name searching function
void searchTheName(string line, int& line_count, int& name_position, int& nameNum, int& flag, vector<string> nameList, vector<string> lastNameList)
{
	if (flag == 1) //flag == 1; search the last name in this line
	{
		lastNameComparison(name_position, line_count, line, nameList[nameNum], lastNameList[nameNum]);
		flag = 0;
	}

	++line_count;

	for (int i = 0; i < line.length(); i++)
	{
		for (int j = 0; j < nameList.size(); j++)
		{
			if (nameList[j][0] == line [i])
			{
				nameComparison(i, flag, name_position, line_count, line, nameList[j]);
				nameNum = j;
			}
		}
	}
}

// compare the character with the targeted name
void nameComparison(int i, int& flag, int& name_position, int line_count, string line, string targetName)
{
	int j;

	for (j = 0; j < targetName.length(); j++)
	{
		if (line[i+j] != targetName[j])
		{
			if (i + j == line.length())// if reach the end of this line, search next line
			{
				flag = 1;
				name_position = i + 1;
				break;
			}
		else break; // if the character does not match the name, break
		}
	}

	if (j == targetName.length()) // print out the result if the name matched
	{
		name_position = i + 1;
		std::cout.width(5);
		std::cout << std::right << line_count;
		std::cout.width(10);
		std::cout << std::right << name_position;
		std::cout << "  " << targetName << endl;
	}

}

// compare the character with the targeted last name
void lastNameComparison(int name_position, int line_count, string line, string targetName, string targetLastName)
{
	int i;

	for (i = 0; i < targetLastName.length(); i++)
	{
		if (line[i] != targetLastName[i])
			{
				break; // if the character does not match the name, break
			}
	}

	if (i == targetLastName.length()) // print out the result if the name matched
	{
		std::cout.width(5);
		std::cout << std::right << line_count;
		std::cout.width(10);
		std::cout << std::right << name_position;
		std::cout << "  " << targetName << endl;
	}
}


vector<string> createNameList()
{
	vector<string> nameList;

	nameList.push_back(MAKAR);
	nameList.push_back(JOSEPH);
	nameList.push_back(BORIS);

	return nameList;
}


vector<string> createLastNameList()
{
	vector<string> lastNameList;

	lastNameList.push_back(MAKAR_LastName);
	lastNameList.push_back(JOSEPH_LastName);
	lastNameList.push_back(BORIS_LastName);

	return lastNameList;
}
