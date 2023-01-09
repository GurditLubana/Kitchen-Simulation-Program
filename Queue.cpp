// ----------------------------------------------
// CLASS    : Queue
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Implementing data structure Queue.
//
//------------------------------------------------


#include "Queue.h"
#include "Node.h"
#include "List.h"
#include "Event.h"


Queue::Queue():List(){} // constructor

//-------------------------------------------------------------------
// insert
//
// PURPOSE      : inserts new event at last of the Queue.
// PARAMETERS   : It takes event object as a parameter which
//                needs to be inserted in the list.
// Returns      : returns true if inserted successfully, else false
//-------------------------------------------------------------------

bool Queue::insert(Event * item) {

    bool result = false;

    Node* newNode = new Node(item, nullptr);

    if(item != nullptr)
    {
        if(head == nullptr)
        {
            head  = newNode;
            result = true;

        }

        else if( head != nullptr) {
            Node *temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
            result = true;
        }

    }
    return result;
}




