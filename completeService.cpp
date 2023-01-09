// --------------------------------------------------------------------------------------------
// CLASS    : completeService
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : This class is creating new complete Service event when order is served.
//
//---------------------------------------------------------------------------------------------

#include "completeService.h"

completeService::completeService(int times, int odrId, double price) { //constructor

    time = times;
    id = odrId;
    revenue = price;


}
void completeService:: print(){

    Event::print();
    cout<< " has been served! Revenue grew by: $"<< revenue<<endl;
}

double completeService::getRevenue() {
    return revenue;
}
