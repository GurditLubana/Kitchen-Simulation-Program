// --------------------------------------------------------------------------------------------
// CLASS    : Arrival
//
// Author   : Gurdit Singh, 7880489
//
// REMARKS  : This class is creating new Arrival event when there is new order.
//
//---------------------------------------------------------------------------------------------

#include "Arrival.h"

Arrival::Arrival(int times, int num, int expry, string meals, int ingr) {   //constructor

    time = times;
    expiry = expry;
    meal = meals;
    numIngredients = ingr;
    id = num;

}


void Arrival::print() {

    int prepTimes = this->getPrepTime();
    double prices = this->getPrepPrice();

    Event::print();
    cout << " arrives -> Expiry: " << expiry;
    cout << " - Meal: " << meal << " - Ingredients: " << numIngredients;
    cout << " - Prep. time: " << prepTimes << " Price: $" << prices << endl;

}