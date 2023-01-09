// --------------------------------------------------------------------------------------------
// CLASS    : completeService
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : This class is creating new complete Service event when order is served.
//
//---------------------------------------------------------------------------------------------

#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class completeService: public Event
{
public:
    completeService(int times, int odrId, double price);
    void print();
    double getRevenue();

private:
    double revenue;

};