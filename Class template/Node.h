/*
 * Node.h
 *
 *  Created on: Oct 9, 2016
 *      Author: Sam
 */
#ifndef NODE_H_
#define NODE_H_

/***** Convert this to a class template to handle
 ***** multiple types of data stored in the nodes. */

using namespace std;

template <typename T>
class Node
{
public:
    Node(T);
    ~Node();

    T data;
    Node<T> *next;
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr)
{
}

template <typename T>
Node<T>::~Node()
{
}

#endif /* NODE_H_ */




