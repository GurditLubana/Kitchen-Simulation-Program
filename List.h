// --------------------------------------------------------------------------------------------
// CLASS    : List
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : List is the parent class of the data structures- Queue, stack and priority queue.
//
//---------------------------------------------------------------------------------------------

#pragma once

#include <string>
#include <iostream>
using namespace std;
#include "Arrival.h"

class Event;

class Node;
//class ListItem;

class List
{

public:
    List();
    virtual Node* getHead() ;
    virtual bool insert(Event *) = 0;
    virtual Event* deleteNode();
    virtual bool isEmpty();
    void print();

    virtual bool priorityInsert(Event *item);


protected:
    Node * head;


};