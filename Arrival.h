// --------------------------------------------------------------------------------------------
// CLASS    : Arrival
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : This class is creating new Arrival event when there is new order.
//
//---------------------------------------------------------------------------------------------


#pragma once
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Arrival : public Event
{
public:
    Arrival(int, int, int, string,int);
    void print();

};