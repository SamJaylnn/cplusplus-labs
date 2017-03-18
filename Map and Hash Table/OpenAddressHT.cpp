/*
 * OpenAddressHT.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: Timmy
 */

#include <iostream>
#include <iomanip>
#include "OpenAddressHT.h"
#include "HashEntry.h"

using namespace std;

/**
 * Default constructor
 */
OpenAddressHT::OpenAddressHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
OpenAddressHT::OpenAddressHT(int size) : HashTable(size)
{
    /***** Complete this member function. *****/
	for(int i = 0; i < size; i++) {
		table.push_back(nullptr);
	}
}

/**
 * Destructor. Delete all the entries in the table.
 */
OpenAddressHT::~OpenAddressHT()
{
    /***** Complete this member function. *****/
	//table.clear();
	//delete table;
	for(int i = 0; i < size; i++) {
		if (table[i] != nullptr) {
			delete table[i];
		}
	}
}

/**
 * Return an entry at a given index of the hash table.
 * @param index the index.
 * @return the entry.
 */
HashEntry *OpenAddressHT::get_entry(const int index) const
{
    /***** Complete this member function. *****/
	return table[index];
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return the hash table index of the entry if found, else of an empty slot.
 */
int OpenAddressHT::search(const string& key, int& probe_count)
{
    /***** Complete this member function. *****/

    // Initial probe index.
    int index = hash(key);
    while (table[index] != nullptr && table[index]->word != key)
    {
    	probe_count++;
        index = next_index(index);

    }
    probe_count++;
    return index;  // of the found entry or of an empty slot







/*    int index = hash(key);
    int originalIndex = index;
    while (index < table.size()) {
    	probe_count++;
    	if (table[index] == nullptr) {
    	    return index;
    	}
    	if(table[index]->word == key) {
			return index;
		}
    	index = next_index(originalIndex);  // probe the next slot
    }
    return index;
*/
    /*
    while (table[index] != nullptr && table[index]->word != key) {
    	probe_count++;
    	index = next_index(index);
    }
    return index;
    */

    /*
    index %= table.size();
    while (index < originalIndex) {
    	probe_count++;
    	if (table[index] == nullptr) {
    	    return index;
    	}
    	if(table[index]->word == key) {
			return index;
		}
    	index = next_index(index);  // probe the next slot
    }
	*/
  //  return -1;  // of the found entry or of an empty slot
}

/**
 * If an entry isn't already in the table, enter it with a
 * frequency count of 1. If the entry already exists,
 * update it by incrementing its frequency count by 1.
 * Count the number of probes from the initial search.
 * @param key the key of the entry to enter or update.
 * @return the index of the newly entered or updated entry.
 */
int OpenAddressHT::enter(const string& key, int& probe_count)
{
    // Search for the entry key.
    int index = search(key, probe_count);

    /***** Complete this member function. *****/
  //  if(index == -1) {
  //  	return -1;
  //  }

    if(table[index] != nullptr && table[index]->word == key) {
    	table[index]->count++;
    	return index;
    }
    else if (table[index] == nullptr){
    	HashEntry *entry;
    	entry = new HashEntry(key);
    	table[index] = entry;
    }

    return index;
}

/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void OpenAddressHT::dump() const
{
    /***** Complete this member function. *****/
	for(int i = 0; i < table.size(); i++) {
		if(table[i] != nullptr) {
			cout << table[i]->word << " " << table[i]->count << endl;
		}
	}
}



