// ------------------------------------------------------
// CLASS    : PriorityQueue
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Implementing data structure Priority Queue.
//
//------------------------------------------------

#pragma once

#include "List.h"
#include "Arrival.h"

class PriorityQueue: public List
{
public:
    PriorityQueue();
    bool insert(Event *) ;
    bool priorityInsert( Event *item);
};