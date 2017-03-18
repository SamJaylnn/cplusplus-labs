/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 */
#include <iostream>
#include <vector>
#include <time.h>

#include <cstdlib>
#include <ctime>
#include <chrono>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"

using namespace std;
using namespace std::chrono;

const bool DUMP = false;

void testBST();
void testAVL();

void makeTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer,
              string kind);

void testTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer);

void searchTree(BinarySearchTree<int>& tree);

vector<int> VALUES;
vector<int> SEARCH_VALUES;

/**
 * Main.
 */
int main( )
{
    cout << setw(8) << "Size";
    cout << setw(20) << "BST insert(ms)";
    cout << setw(20) << "BST insert probe";
    cout << setw(20) << "BST insert compare";
    cout << setw(20) << "BST search(ms)";
    cout << setw(20) << "BST search probe";
    cout << setw(20) << "BST search compare";
    cout << setw(8) << "Size";
    cout << setw(20) << "AVL insert(ms)";
    cout << setw(20) << "AVL insert probe";
    cout << setw(20) << "AVL insert compare";
    cout << setw(20) << "AVL search(ms)";
    cout << setw(20) << "AVL search probe";
    cout << setw(20) << "AVL search compare";
    cout << endl;



	int size = 10000;
	for (int i = 0; i < size; i++)
	{
		VALUES.push_back(rand()%100000);
		SEARCH_VALUES.push_back(rand()%100000);
	}

	for (int j = 0; j < 10 ; j++)
	{
		//cout << endl;
		//cout << "* BINARY SEARCH TREE *"  << endl;
		testBST();

		//cout << endl;
		//cout << "* AVL TREE *" << endl;
		testAVL();

		cout << endl;

		for (int i = 0; i < 10000; i++)
		{
			VALUES.push_back(rand()%(100000));
			SEARCH_VALUES.push_back(rand()%100000);
		}
	}
}

/**
 * Run the test with a binary search tree.
 */
void testBST()
{
//    cout << endl;
//    cout << "**********************" << endl;
//    cout << "* BINARY SEARCH TREE *" << endl;
//    cout << "**********************" << endl;

		BinarySearchTree<int>  tree;
		BinaryTreeChecker<int> checker(tree);
		BinaryTreePrinter<int> printer(tree);
		makeTree(tree, checker, printer, "BST");
		searchTree(tree);

    //testTree(tree, checker, printer);
}

/**
 * Run the test with an AVL tree.
 */
void testAVL()
{
//    cout << endl;
//    cout << "************" << endl;
//    cout << "* AVL TREE *" << endl;
//    cout << "************" << endl;

    AvlTree<int> tree;
    BinaryTreeChecker<int> checker(tree);
    BinaryTreePrinter<int> printer(tree);
    makeTree(tree, checker, printer, "AVL");
    searchTree(tree);
    //testTree(tree, checker, printer);
}


//static const int VALUES[] = {
//    62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,49,82,37,
//    94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28
//};

/**
 * Make a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param maxNodes the maximum number of nodes to generate.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param insertPrint true if print a message after each node insertion
 */
void makeTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer,
              string kind)
{
	steady_clock::time_point start_time = steady_clock::now();

    for (int n : VALUES)
    {
        tree.insert(n);  // insert into tree
     //   checker.add(n);  // store with the tree checker
    }

    steady_clock::time_point end_time = steady_clock::now();
    long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
    cout << setw(8) << VALUES.size();
    cout << setw(20) << elapsed_time;
    cout << setw(20) << tree.probe_count;
    cout << setw(20) << tree.compare_count;
    tree.clear_count();

    //cout << VALUES.size() << "Insertion time: " << elapsed_time << " milliseconds." << endl;

//    cout << endl;
//    cout << "*****" << endl;
//    cout << "***** COMPLETED " << kind << " TREE:" << endl;
//    cout << "*****" << endl << endl;
//    printer.print();
}

/**
 * Test a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 */
void testTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer)
{
    int status = BinaryTreeChecker<int>::NO_ERROR;

    // Delete the root node each time through the loop.
    // Print the tree after each deletion.

    steady_clock::time_point start_time = steady_clock::now();

    while (!tree.isEmpty())
    {
        BinaryNode<int> *root = tree.getRoot();
        int data = root->data;
    //    cout << endl << "Deleted root node " << data << ":" << endl;

        tree.remove(data);
        checker.remove(data);

//        cout << endl;
//        printer.print();

        status = checker.check(DUMP);
        if (status != BinaryTreeChecker<int>::NO_ERROR) break;
    }

    steady_clock::time_point end_time = steady_clock::now();
    long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
    cout << "delete! " << elapsed_time << " milliseconds." << endl;

    // What was the status?
    string msg;
    switch (status)
    {
        case BinaryTreeChecker<int>::NO_ERROR:
        {
            msg = ">>>>> The tree is now empty.";
            break;
        }
        case BinaryTreeChecker<int>::DATA_MISMATCH:
        {
            msg =  ">>>>> Data mismatch.";
            break;
        }
        case BinaryTreeChecker<int>::INSUFFICIENT_DATA:
        {
            msg =  ">>>>> Data missing from tree.";
            break;
        }
        case BinaryTreeChecker<int>::REMAINING_DATA:
        {
            msg =  ">>>>> Data remaining in tree.";
            break;
        }
    }
    cout << msg << endl;
}

/**
 * Search a binary tree.
 * @param tree the tree to search.
 */
void searchTree(BinarySearchTree<int>& tree)
{
	steady_clock::time_point start_time = steady_clock::now();

    for (int n : SEARCH_VALUES)
    {
        tree.contains(n);  // search tree
    }

    steady_clock::time_point end_time = steady_clock::now();
    long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
    cout << setw(20) << elapsed_time;
    cout << setw(20) << tree.probe_count;
    cout << setw(20) << tree.compare_count;


    //cout << SEARCH_VALUES.size() << "Search time: " << elapsed_time << " milliseconds." << endl;
}
