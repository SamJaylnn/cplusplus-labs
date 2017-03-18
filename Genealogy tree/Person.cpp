/*
 * Person.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Sam
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"
using namespace std;

/**
 * Constructor
 */
Person::Person(int level, string name):level(level),name(name)
{
}

Person::Person(int level, string name, string spouse):level(level),name(name),spouse_name(spouse)
{
}

/**
 * Destructor
 */
Person::~Person()
{
    unsigned size = children.size();
    unsigned cur = 0;

    while (cur < size)
    {
    	if (children[cur] != nullptr)
		{
    		delete children[cur];
		}
    	cur++;
    }
}

/**
 * Have a child.
 * @param child pointer to the new child.
 */
void Person::have_child(Person *child)
{
	child->parent = this;
    children.push_back(child);
}

/**
 * Print a person.
 */
void Person::print() const
{
	if(parent != nullptr)
	{
		print_bar();
		cout << "|" << endl;
		print_bar();
		cout << "+---" << name;
	}
	else
	{
		cout << name;
	}

    if (spouse_name.length())
    {
    	cout << " (" << spouse_name << ")" << endl;
    }
    else
    {
    	cout << endl;
    }

    unsigned size = children.size();
    unsigned cur = 0;
    while (cur < size)
    {
    	children[cur++]->print();
    }
}

/**
 * Print the vertical bar.
 */
void Person::print_bar() const
{
	if (parent != nullptr && parent->parent != nullptr)
		{
			parent->print_bar();

			vector<Person*>::iterator it = find(parent->parent->children.begin(), parent->parent->children.end(), parent);
			if (distance(parent->parent->children.begin(), it) != parent->parent->children.size() - 1)
			{
				cout << "|   ";
			}
			else
			{
				cout << "    ";
			}
		}
}




