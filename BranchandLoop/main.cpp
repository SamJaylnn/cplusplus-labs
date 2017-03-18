#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

const string INPUT_FILE_NAME = "GettysburgAddress.txt";

int main()
{
    string line;
    char curr_char, last_char;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int space_count = 0;
    int punctuation_count = 0;


    ifstream input;
    input.open(INPUT_FILE_NAME.c_str());
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    cout << "Statistics for file " << INPUT_FILE_NAME << ":" << endl;
    cout << endl;

    while(input.get(curr_char))
    {
    	if (curr_char == '\n')
    		line_count++;
    	else character_count++;

    	if (!isalnum(curr_char) && isalnum(last_char))
    		word_count++;

    	if (ispunct(curr_char))
    		punctuation_count++;

    	if (curr_char >= 'a' && curr_char <= 'z')
    		lower_count++;

    	if (curr_char >= 'A' && curr_char <= 'Z')
    		upper_count++;

    	if (curr_char == ' ')
    		space_count++;

    	last_char = curr_char;


    }
    /**** Done by Samuel ****/

    /***** Complete this program. *****/
    cout << "Lines: " << line_count << endl;
    cout << "Characters: " << character_count << endl;
    cout << "Words: " << word_count << endl;
    cout << "Lower-case letters: " << lower_count << endl;
    cout << "Upper-case letters: " << upper_count << endl;
    cout << "Spaces: " << space_count << endl;
    cout << "Punctuation marks: " << punctuation_count << endl;

    input.close();
    return 0;
}
