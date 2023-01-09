// -----------------------------------------------------------------------
// CLASS    : Event
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : Event class is the parent class of Arrival,
//            Prepare and completeService class and creating a new event.
//
//------------------------------------------------------------------------


#include "Event.h"

Event::Event()  //constructor
{
    time =0;
    expiry =0;
    meal = " ";
    numIngredients = 0;
    id = 0;
    prepTime = 0;
    price = 0;
}


void Event::print() {

    cout<<"Time: " << time << ", FoodOrder " <<id;
}




int Event::getTime() {
    return time;
}


//-------------------------------------------------------------------
// getPrepTime
//
// PURPOSE      : Calculates the total time taken to prepare the order.
//
// Returns      : returns an integer value of preparation time.
//-------------------------------------------------------------------

int Event::getPrepTime() {

    int  basePrepTime = 0;
    if(meal.compare("Salad")== 0){
        basePrepTime = 3 ;
    }
    else if(meal.compare("Burger")== 0){
        basePrepTime = 4 ;
    }
    else if(meal.compare("Pizza")== 0){
        basePrepTime = 6 ;
    }
    else if(meal.compare("Stew")== 0){
        basePrepTime = 7 ;
    }

    prepTime = (basePrepTime + numIngredients);

    return prepTime;

}

//-------------------------------------------------------------------
// getPrepPrice
//
// PURPOSE      : Calculates the total revenue generated from the order
//
// Returns      : returns a double value of the revenue.
//-------------------------------------------------------------------

double Event :: getPrepPrice()
{
    double basePrice = 0;
    if(meal.compare("Salad") == 0){
        basePrice = 6.99;
    }
    else if(meal.compare("Burger")== 0){
        basePrice = 8.99;
    }
    else if(meal.compare("Pizza")== 0){
        basePrice = 12.99;
    }
    else if(meal.compare("Stew")== 0){
        basePrice = 14.99;
    }

    price = (basePrice + numIngredients);

    return price;
}


int Event:: getOrderId()
{
    return id;
}





int Event::getExpiry() {
    return expiry;
}
