/*
 * RomanNumerals.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Sam
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "RomanNumeral.h"

using namespace std;

/**
 * Default constructor.
 */
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}

// Constructor with string parameter.
RomanNumeral::RomanNumeral(string roman) : roman(roman)
{
	toDecimal();
}

// Constructor with integer parameter.
RomanNumeral::RomanNumeral(int value) : decimal(value)
{
	toRoman();
}

// Public getter function, return string.
string RomanNumeral::getRomanNumeral()
{
	return roman;
}

// Public getter function, return integer value.
int RomanNumeral::getDecimal()
{
	return decimal;
}

// Calculate string from decimal value.
void RomanNumeral::toRoman()
{
	int value = decimal;
	int remainder, quotient, rankInRomanSet = 0, digits = 1;
	char romanNumberSet[] = "IVXLCDM";
	vector<char> roman_vector;

	while (value /= 10)
	{
		digits *= 10;
		rankInRomanSet += 2;
	}

	value = decimal;

	do
	{
		remainder = (value / digits) % 5;
		quotient = (value / digits) / 5;

		if (remainder == 4)
		{
			if (quotient == 0)
			{
				roman_vector.push_back(romanNumberSet[rankInRomanSet]);
				roman_vector.push_back(romanNumberSet[rankInRomanSet + 1]);
			}
			else
			{
				roman_vector.push_back(romanNumberSet[rankInRomanSet]);
				roman_vector.push_back(romanNumberSet[rankInRomanSet + 2]);
			}
		}
		else
		{
			if (quotient == 1) roman_vector.push_back(romanNumberSet[rankInRomanSet + 1]);
			for (int i = 0; i < remainder; i++)
				roman_vector.push_back(romanNumberSet[rankInRomanSet + 0]);
		}

		value = value % digits;
		rankInRomanSet -= 2;

	} while (digits /= 10);

	string str(roman_vector.begin(), roman_vector.end());
	roman = str;
}

// Calculate decimal value from string.
void RomanNumeral::toDecimal()
{
	char roman_char[roman.length() + 1];
	strcpy(roman_char, roman.c_str());
	int cur_roman_value, prev_roman_value = value(roman_char[0]);

	decimal = 0;

	for(int i = 0; i < roman.length(); i++)
	{
		cur_roman_value = value(roman_char[i]);

		if (cur_roman_value <= prev_roman_value)
		{
			decimal += cur_roman_value;
		}
		else
		{
			decimal = decimal - 2 * prev_roman_value + cur_roman_value;
		}

		prev_roman_value = cur_roman_value;
	}
}

// Calculate value from corresponding Roman character.
int RomanNumeral::value(char roman_char)
{
	switch (roman_char)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: cout << "That is not a possible Roman Number.";
	}
	return 0;
}

// Overload + operator.
RomanNumeral operator +(const RomanNumeral roman1, const RomanNumeral roman2)
{
	RomanNumeral roman_result(roman1.decimal + roman2.decimal);
	return roman_result;
}

// Overload - operator.
RomanNumeral operator -(const RomanNumeral roman1, const RomanNumeral roman2)
{
	RomanNumeral roman_result(roman1.decimal - roman2.decimal);
	return roman_result;
}

// Overload * operator.
RomanNumeral operator *(const RomanNumeral roman1, const RomanNumeral roman2)
{
	RomanNumeral roman_result(roman1.decimal * roman2.decimal);
	return roman_result;
}

// Overload / operator.
RomanNumeral operator /(const RomanNumeral roman1, const RomanNumeral roman2)
{
	RomanNumeral roman_result(roman1.decimal / roman2.decimal);
	return roman_result;
}

// Overload == operator.
bool operator ==(const RomanNumeral roman1, const RomanNumeral roman2)
{
	if (roman1.decimal == roman2.decimal) return true;
	else return false;
}

// Overload != operator.
bool operator !=(const RomanNumeral roman1, const RomanNumeral roman2)
{
	if (roman1.decimal != roman2.decimal) return true;
	else return false;
}

// Overload << operator.
ostream& operator <<(ostream& outs, const RomanNumeral roman1)
{
	outs << "[" << roman1.decimal << ":" << roman1.roman << "]";
	return outs;
}

// Overload >> operator.
istream& operator >>(istream& ins, RomanNumeral& roman1)
{
	ins >> roman1.roman;
	roman1.toDecimal();
	return ins;
}



const string INPUT_FILE_NAME = "RomanNumeral.txt";

void test1();
void test2(ifstream& in);

/**
 * Main. Run the two tests.
 */
int main()
{
    test1();

    ifstream in;
    in.open(INPUT_FILE_NAME.c_str());
    if (in.fail())
    {
        cout << "Input file open failed: " << INPUT_FILE_NAME;
        return -1;
    }

    test2(in);
    return 0;
}

/**
 * A test with some predefined Roman numerals
 * and an arithmetic and a relational expression.
 */
void test1()
{
    cout << "Test 1" << endl << endl;

    RomanNumeral r1(53);
    RomanNumeral r2("MCMXLIX");
    RomanNumeral r3("XXXIV");
    RomanNumeral r4(1949);

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;
    cout << "r4 = " << r4 << endl;

    RomanNumeral result = r1 + r2/r3;
    cout << "result = r1 + r2/r3 = "
         << r1 << " + " << r2 << " / " << r3
         << " = " << result << endl;

    cout << endl;

    if (r2 == r4)
    {
        cout << r2 << " and " << r4 << " are equal." << endl;
    }
    else
    {
        cout << r2 << " and " << r4 << " are unequal." << endl;
    }

    if (r1 == r3)
    {
        cout << r1 << " and " << r3 << " are equal." << endl;
    }
    else
    {
        cout << r1 << " and " << r3 << " are unequal." << endl;
    }
}

/**
 * A test that reads, parses, and executes
 * arithmetic expressions with Roman numerals.
 * @param in the input stream
 */
void test2(ifstream& in)
{
    cout << endl;
    cout << "Test 2" << endl << endl;

    // Read and process each expression, one per line,
    // each in the form    r1 op r2
    // where r1 and r2 are the two Roman numeral operands,
    // and arithmetic operator op is either + - * or /
    RomanNumeral r1;
    while (in >> r1)     // read r1
    {
        RomanNumeral r2, result;
        char op;
        in >> op >> r2;  // read op and r2

        switch (op)
        {
            case '+':
                result = r1 + r2;
                break;

            case '-':
                result = r1 - r2;
                break;

            case '*':
                result = r1*r2;
                break;

            case '/':
                result = r1/r2;
                break;
        }

        // Output the operands, the operator, and the result.
        cout << r1 << " " << op << " " << r2
             << " = " << result << endl;
    }
}
