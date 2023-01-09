// --------------------------------------------------------------------------------------------
// CLASS    : Prepare
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : This class is creating new Prepare event when chef starts to prepare the next order.
//
//---------------------------------------------------------------------------------------------



#pragma once
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Prepare: public Event
{
public:

    Prepare(int, int, int,double);
    void print() override;
    int getPrepTime();
    double getPrepPrice();

private:
    int prepTime;
    double price;



};
