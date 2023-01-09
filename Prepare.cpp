// --------------------------------------------------------------------------------------------
// CLASS    : Prepare
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : This class is creating new Prepare event when chef starts to prepare the next order.
//
//---------------------------------------------------------------------------------------------



#include "Prepare.h"

Prepare::Prepare(int times, int num, int prepTimes, double prepCost) {
    time = times;
    id = num;
    prepTime = prepTimes;
    price = prepCost;
}

void Prepare::print() {

    Event::print();
    cout << " is getting prepared by the chef! "<<endl;

}

int Prepare:: getPrepTime()
{
    return prepTime;
}

double Prepare:: getPrepPrice()
{
    return price;
}
