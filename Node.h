// --------------------------------------------------------------------------------------------
// CLASS    : Node
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Node class created a new node to store events in the list.
//
//---------------------------------------------------------------------------------------------


#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

//class ListItem;

class Node {
private:
    Event *data;
    Node *next;
public:
    Node(Event*, Node*);
    Node *getNext();
    virtual Event *getData();
    void setNext(Node*);
};



