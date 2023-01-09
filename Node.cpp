// --------------------------------------------------------------------------------------------
// CLASS    : Node
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Node class created a new node to store events in the list.
//
//---------------------------------------------------------------------------------------------


#include "Node.h"

Node::Node(Event* item, Node *nextNode) : data(item), next(nextNode){} // constructor

Event *Node::getData(){
    return data;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* newNext){
    next = newNext;
}




