// ------------------------------------------------------
// CLASS    : PriorityQueue
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Implementing data structure Priority Queue.
//
//------------------------------------------------


#include "Node.h"
#include "PriorityQueue.h"
#include "Event.h"


PriorityQueue::PriorityQueue():List() {} //constructor


//-------------------------------------------------------------------
// insert
//
// PURPOSE      : inserts new event in the Priority Queue, with time being the priority.
// PARAMETERS   : It takes event object as a parameter which
//                needs to be inserted in the list.
// Returns      : returns true if inserted successfully, else false
//-------------------------------------------------------------------



bool PriorityQueue::insert(Event* item)
{
    bool result = false;

    Node* temp = head;
    Node* newNode = new Node(item, nullptr);

    if(head == nullptr || head->getData()->getTime() > item->getTime())
    {
        newNode->setNext(head);
        head = newNode;
        result = true;
    }
    else //if( head != nullptr)
    {

        if(head->getData()->getTime() == item->getTime())
        {
            if(head->getData()->getOrderId() > item->getOrderId())
            {
                newNode->setNext(head);
                head = newNode;
                result = true;
            }
            else if (head->getData()->getOrderId() < item->getOrderId())
            {

                newNode->setNext(head->getNext());
                head->setNext(newNode);

                result = true;
            }
        }
        else
        {
            Node *temp = head;

            Event *y = dynamic_cast<Event *>(item);

            bool loop = false;
            while(temp->getNext() != nullptr && loop == false)
            {
                Event *x = dynamic_cast<Event *>(temp->getNext()->getData());

                if( x->getTime() >= y->getTime())
                {
                    if(x->getTime() == y->getTime())
                    {
                        if(x->getOrderId() > y->getOrderId())
                        {
                            loop = true;
                        }
                    }
                }

                temp = temp->getNext();
            }

            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
            result = true;
        }
    }




    return result;
}






//--------------------------------------------------------------------------------------------
// priorityInsert
//
// PURPOSE      : inserts new event in the Priority Queue, with revenue being the priority.
// PARAMETERS   : It takes event object as a parameter which
//                needs to be inserted in the list.
// Returns      : returns true if inserted successfully, else false
//--------------------------------------------------------------------------------------------

bool PriorityQueue::priorityInsert(Event* item) {

    Arrival* k = (dynamic_cast<Arrival *>(item));

    List::priorityInsert(item);
    bool result = false;
    Node* newNode = new Node(item, nullptr);

    if(head == nullptr ||k->getPrepPrice() > dynamic_cast<Arrival*>(head->getData())->getPrepPrice())
    {
        newNode->setNext(head);
        head  = newNode;
        result = true;
    }

    else if( head != nullptr) {
        Node *temp = head;
        bool loop = false;
        while(temp->getNext() != nullptr && loop == false)
        {
            Arrival *x = dynamic_cast<Arrival *>(temp->getNext()->getData());
            if( x->getPrepPrice() < k->getPrepPrice())
            {
                loop = true;
            }
            else
            {
                temp = temp->getNext();
            }

        }

        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        result = true;
    }

    return result;
}