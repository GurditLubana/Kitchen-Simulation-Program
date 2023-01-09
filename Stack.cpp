// ----------------------------------------------
// CLASS    : Stack
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Implementing data structure stack.
//
//------------------------------------------------

#include "Node.h"
#include "Stack.h"

Stack::Stack()
{
    head = nullptr;
}

//-------------------------------------------------------------------
// insert
//
// PURPOSE      : inserts new event in the Stack in the front.
// PARAMETERS   : It takes event object as a parameter which
//                needs to be inserted in the list.
// Returns      : returns true if inserted successfully, else false
//-------------------------------------------------------------------

bool Stack::insert(Event* item) {

    bool result = false;

    if(item != nullptr)
    {

        Node* temp = head;
        Node* newNode =  new Node(item, temp);
        head = newNode;
        result = true;
    }
    return result;

}