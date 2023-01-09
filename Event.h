// -----------------------------------------------------------------------
// CLASS    : Event
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Event class is the parent class of Arrival,
//            Prepare and completeService class and creating a new event.
//
//------------------------------------------------------------------------


#pragma once
#include <string>
#include <iostream>
using namespace std;

class Event
{
public:
    Event();


    virtual void print()  ;
    virtual int getTime();
    int getOrderId();
    int getExpiry();
    virtual int getPrepTime();
    virtual double getPrepPrice() ;

protected:
    int time ;
    int expiry ;
    string meal;
    int numIngredients;
    int id;
    int prepTime;
    double price;



};