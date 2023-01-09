//----------------------------------------------------------------------------------
// CLASS: Execution
//
// Author: Gurdit Singh, 7880489
//
// REMARKS: This class is reading the input file and then executing the simulation.
//
//----------------------------------------------------------------------------------

#pragma once
#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
using namespace std;
#include "List.h"
#include "Queue.h"
#include "Arrival.h"
#include "Prepare.h"

class PriorityQueue;




class Execution
{
private:

    int time ;

    int expiry ;

    int currTime;

    int orderId;

    bool loop;

    int totalOrders;

    double totalRevenue;

    int numIngredients;

    string meal;

    List * orderList;

    PriorityQueue * eventList;

public:

    Execution();

    void execute( char* [], int);

    void readLine(char **argv, int argc, string line);

    void createPrepareEvent(Arrival *, int);

    void createCompleteServiceEvnt(Prepare *p);

    void processSimulation(char **argv, int argc, string line, ifstream &inputFile, int);

    void createArrivalEvent(char **argv, int argc, string line, ifstream & inputFile);
};