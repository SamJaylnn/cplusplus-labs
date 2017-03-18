/*
 * SortedList.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Sam
 */

#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

class SortedList
{
public:
    SortedList();
    virtual ~SortedList();

    void prepend(int value);
    void append(int value);
    bool find(int value) const;
    int get_value(int i) const;
    void lookthrough();
    void clear();
    bool check();

private:
    list<int> data;
};

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

void SortedList::lookthrough()
{
	list<int>::iterator it = data.begin();
	for(; it != data.end(); it++)
	{
		cout << *it << " ";
	}
}


/***** Complete this file. *****/

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}

void SortedList::prepend(int value)
{
	list<int>::iterator it = data.begin();
	data.insert(it, value);
}

void SortedList::append(int value)
{
	data.push_back(value);
}

bool SortedList::find(int value) const
{
	/*list<int>::const_iterator const_it;
	for(const_it = data.begin(); const_it != data.end(); ++const_it)
	{
		if(*const_it == value) return true;
	}
	return false;*/

	list<int>::const_iterator const_it = data.begin();
	while(const_it != data.end())
	{
		if(*const_it == value) return true;
		const_it++;
	}
	return false;
}

int SortedList::get_value(int i) const
{
	/*if (data.size() -1 - i > i)
	{
		list<int>::const_iterator it = data.begin();
		int j = 0;
		while(j++ != i)
		{
			++it;
		}
		return *it;
	}
	else
	{
		list<int>::const_reverse_iterator it = data.rbegin();
		int j = data.size() - 1;
		while(j-- != i)
		{
			++it;
		}
		return *it;
	}*/

	  if(data.size() -1 > 2 * i)
	  {
	    // go through from begin
	    list<int>::const_iterator ith = data.begin();
	    int j = 0;
	    while(j != i)
	    {
	      ith++;
	      j++;
	    }
	    return *ith;
	  }
	  else
	  {
	    // go reverse direction
	    list<int>::const_reverse_iterator rith = data.rbegin();
	    int j = data.size() - 1;
	    while(j != i)
	    {
	      rith++;
	      j--;
	    }
	    return *rith;
	  }

}

void SortedList::clear()
{
	list<int>::iterator it;
	for(it = data.begin(); it != data.end();)
	{
		it = data.erase(it);
	}
}

#endif /* SORTEDLIST_H_ */
