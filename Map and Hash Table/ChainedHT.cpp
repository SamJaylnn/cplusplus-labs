/*
 * ChainedHT.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: Timmy
 */

#include <iostream>
#include <iomanip>
#include "ChainedHT.h"
using namespace std;

/**
 * Default constructor.
 */
ChainedHT::ChainedHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
ChainedHT::ChainedHT(int size) : HashTable(size)
{
    /***** Complete this member function. *****/
	for(int i = 0; i < size; i++) {
		table.push_back(nullptr);
	}
}

/**
 * Destructor. Delete all the entries in the collision chains.
 */
ChainedHT::~ChainedHT()
{
    /***** Complete this member function. *****/
	table.clear();
	//delete table;
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return a pointer to the entry if found, else return nullptr.
 */
HashEntry *ChainedHT::search(const string& word, int& probe_count)
{
    int index = hash(word);
    HashNode *check = table[index];
//    HashEntry *ptr = check->entry;

    /***** Complete this member function. *****/

    while(check != nullptr) {
    	probe_count++;
    	if(check->entry->word == word) {
    		//break;
    		return check->entry;
    	}
    	check = check->next;
    }

 //   return ptr;
    return nullptr;
}

/**
 * If an entry isn't already in the table, enter it with a
 * frequency count of 1. If the entry already exists,
 * update it by incrementing its frequency count by 1.
 * Count the number of probes from the initial search.
 * @param key the key of the entry to enter or update.
 * @return a pointer to the newly entered or updated entry.
 */
HashEntry *ChainedHT::enter(const string& word, int& probe_count)
{
    HashEntry *entry_ptr = search(word, probe_count);

    /***** Complete this member function. *****/
    if(entry_ptr == nullptr) {
    	HashNode *previous = table[hash(word)];
    	entry_ptr = new HashEntry(word);
    	HashNode *node;
    	node = new HashNode(entry_ptr);
    	table[hash(word)] = node;
    	table[hash(word)]->next = previous;
    }
    else {
    	entry_ptr->count++;
    }

    return entry_ptr;
}


/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void ChainedHT::dump() const
{
    /***** Complete this member function. *****/
	HashNode *current;
	HashEntry *check;
	for(int i = 0; i < size; i++) {
		current = table[i];
		if (current != nullptr) check = current->entry;
		while(current != nullptr) {
			cout << check->word << " " << check->count << endl;
			current = current->next;
			if (current != nullptr) check = current->entry;
		}
	}


}

/**
 * Compute the average chain length.
 */
double ChainedHT::avg_chain_length() const
{
    /***** Complete this member function. *****/
	double chain_len = 0;
	double num = 0;
	HashNode *current;
	for(int i = 0; i < size; i++) {
		current = table[i];
	//	HashEntry *check = current->entry;
		if(current != nullptr) {
			num++;
		}
		while(current != nullptr) {
			chain_len++;
			current = current->next;
	//		check = current->entry;
		}
	}
	return chain_len/num;
}




