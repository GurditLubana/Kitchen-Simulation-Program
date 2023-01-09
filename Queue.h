// ----------------------------------------------
// CLASS    : Queue
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Implementing data structure Queue.
//
//------------------------------------------------

#pragma once
#include "List.h"
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Queue: public List
{
public:
    Queue();
    bool insert(Event *) ;

};