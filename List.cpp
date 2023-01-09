// --------------------------------------------------------------------------------------------
// CLASS    : List
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : List is the parent class of the data structures- Queue, stack and priority queue.
//
//---------------------------------------------------------------------------------------------

#include <iostream>
#include "List.h"
#include "Node.h"


List::List(): head(nullptr) {} //constructor

Node* List:: getHead()
{
    return head;
}

//-------------------------------------------------------------------
// deleteNode
//
// PURPOSE      : deletes the top most node/event of the list.
// PARAMETERS   : It takes no parameters

// Returns      : returns the event which was deleted.
//-------------------------------------------------------------------

Event* List::deleteNode() {
    Event* result = new Event();

    if(head!= nullptr)
    {
        result = head->getData();
        head = head->getNext();
    }


    return result;
}

//-------------------------------------------------------------------
// print
//
// PURPOSE      : prints all the nodes/events of the list.
// PARAMETERS   : It takes no parameters

//-------------------------------------------------------------------


void List:: print()
{

    Node* newHead = head;
    while( newHead!= nullptr)
    {
        Event * x = dynamic_cast<Event*>(newHead->getData());

            x->print();

        newHead =  newHead->getNext();
    }
}

//-------------------------------------------------------------------
// isEmpty
//
// PURPOSE      : it checks if the list is empty or not
// PARAMETERS   : It takes no parameters

// Returns      : returns true if list is empty, else false.
//-------------------------------------------------------------------

bool List::isEmpty() {

    bool result = false;
    if(head == nullptr)
    result = true;

    return result;
}

bool List::priorityInsert(Event *item) {
    return false;
}


