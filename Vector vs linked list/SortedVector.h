/*
 * SortedVector.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Sam
 */

#ifndef SORTEDVECTOR_H_
#define SORTEDVECTOR_H_


#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class SortedVector
{
public:
    SortedVector();
    virtual ~SortedVector();

    void prepend(int value);
    void append(int value);
    bool find(int value) const;
    int get_value(int i) const;
    void clear();
    bool check();

private:
    vector<int> data;
};



SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

/***** Complete this file. *****/

bool SortedVector::check()
{
    if (data.size() == 0) return true;

    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}

void SortedVector::prepend(int value)
{
	vector<int>::iterator it = data.begin();
	data.insert(it, value);
}

void SortedVector::append(int value)
{
	data.push_back(value);
}

bool SortedVector::find(int value) const
{
	/*vector<int>::const_iterator const_it;
	for(const_it = data.begin(); const_it != data.end(); ++const_it)
	{
		if(*const_it == value) return true;
	}
	return false;*/

	vector<int>::const_iterator const_it = data.begin();
	while(const_it != data.end())
	{
		if(*const_it == value) return true;
		const_it++;
	}
	return false;
}

int SortedVector::get_value(int i) const
{
	return data.at(i);
}

void SortedVector::clear()
{
	vector<int>::iterator it;
	for(it = data.begin(); it != data.end();)
	{
		it = data.erase(it);
	}
}

#endif /* SORTEDVECTOR_H_ */
