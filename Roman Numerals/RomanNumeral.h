/*
 * RomanNumeral.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Sam
 */

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>

using namespace std;

class RomanNumeral
{
public:
    RomanNumeral();
    RomanNumeral(string roman);
    RomanNumeral(int value);

    string getRomanNumeral();
    int getDecimal();

    friend RomanNumeral operator +(const RomanNumeral roman1, const RomanNumeral roman2);
    friend RomanNumeral operator -(const RomanNumeral roman1, const RomanNumeral roman2);
    friend RomanNumeral operator *(const RomanNumeral roman1, const RomanNumeral roman2);
    friend RomanNumeral operator /(const RomanNumeral roman1, const RomanNumeral roman2);

    friend bool operator ==(const RomanNumeral roman1, const RomanNumeral roman2);
    friend bool operator !=(const RomanNumeral roman1, const RomanNumeral roman2);

    friend ostream& operator <<(ostream& outs, const RomanNumeral roman1);
    friend istream& operator >>(istream& ins, RomanNumeral& roman1);

private:
    string roman;      // Roman numeral as a string
    int    decimal;    // decimal value of the Roman numeral

    void toRoman();    // calculate string from decimal value
    void toDecimal();  // calculate decimal value from string

    int value(char roman_char);  // calculate value from corresponding Roman character
};

#endif /* ROMANNUMERAL_H_ */
