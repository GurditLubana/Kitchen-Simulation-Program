// --------------------------------------------------------------------------------------
// CLASS: Execution
//
// Author: Gurdit Singh, 7880489
//
// REMARKS: This class is reading the input file and then executing the simulation.
//
//--------------------------------------------------------------------------------------



#include <string>
#include <iostream>
#include "PriorityQueue.h"
#include "Execution.h"
#include "Arrival.h"
#include "Prepare.h"
#include "completeService.h"
#include "Node.h"
#include "Stack.h"

using namespace std;


Execution::Execution(){  //constructor
    time = 0;
    expiry = 0;
    numIngredients = 0;
    meal = "";
    eventList = new PriorityQueue();
    orderId = 0;
    loop = false;
    totalRevenue = 0;
    totalOrders=0;

}

//-------------------------------------------------------------------
// execute
//
// PURPOSE      : this method is executing our program, by first reading the input file
//                and then fun simulation according to the version.
//
//-------------------------------------------------------------------


void Execution::execute( char* argv[], int argc) {

    string filename = argv[1];
    string version = argv[2];
    cout << "The filename is: " << filename << endl << "The version selected is: " << version <<endl<<endl;
    int v = stoi(version);

    if(v >0 && v < 4) // our program will execute only if asked version is between the range 1 to 3
    {
        ifstream inputFile;
        inputFile.open(filename);  // opening the file for reading
        string line;

        createArrivalEvent(argv,argc,line,inputFile); // creating first instance of arrival in the event list to initialize our program.
        currTime = time;

        if(v == 1)         //
        {
            orderList = new Queue();  // if user chose version 1, simulation will handle food orders as first come first served.
        }
        else if (v == 2)
        {
            orderList = new Stack();  // if user chose version 2, simulation will handle food orders as last come first served.
        }

        else if (v == 3)
        {
            orderList = new PriorityQueue(); // if user chose version 3, simulation will handle food orders as  maximum revenue, first served.
        }

        processSimulation(argv, argc, line,inputFile, v);  // run simulation.

        cout<< endl <<".....simulation ended."<<endl<<"-Total number of orders completed: " << totalOrders <<endl;
        cout<< "-Total revenue: " <<  totalRevenue << endl<< endl<<"Programmed by Gurdit Singh" <<endl;
    }
    else
    {
        cout<<"The version you entered is "<< v << ". Please enter version between 1 to 3. " <<endl;
    }

}


//-------------------------------------------------------------------
// processSimulation
//
// PURPOSE      : this method is executing the event driven simulation for each version
//
// PARAMETERS   : it is taking arguments as a paramters and then the input file and version of the simulation.
//-------------------------------------------------------------------


void Execution:: processSimulation(char* argv[], int argc,  string line, ifstream &inputFile, int version)
{


    Event* eve ;

        while(!eventList->isEmpty()){
        if(!eventList->isEmpty())
        {
            eve = eventList->deleteNode();

            // first we will delete the first node of the event list and store it and will check the instance of that event.

            Arrival *a = dynamic_cast<Arrival *>(eve);
            Prepare* p = dynamic_cast<Prepare* >(eve);
            completeService* c = dynamic_cast<completeService *>(eve);

            if(p!= nullptr) // if top most event is of prepare instance, it will read next arrivals and will create complete service instance.
            {
                p->print();

                int time2 = p->getTime() + p->getPrepTime(); // checking what time will food be ready to be served.
                createCompleteServiceEvnt(p);
                while(time <= time2 && !loop)
                {
                    createArrivalEvent(argv, argc,  line, inputFile);
                }


            }
            else if(c!= nullptr)  //if top most event is of completeService instance, chef will start preparing next order
            {
                c->print();
                bool condition = false;
                while(!condition)
                {

                    if(!orderList->isEmpty())
                    {
                        Arrival *nextArrival = dynamic_cast<Arrival *>(orderList->getHead()->getData());
                        if ((currTime + nextArrival->getPrepTime()) <= (nextArrival->getTime() + nextArrival->getExpiry())) {
                            createPrepareEvent(nextArrival, currTime);
                            condition = true;

                        }
                        else
                        {
                            orderList->deleteNode(); // after completely serving the order, code will delete that order from the order list.
                        }
                    }
                    else
                    {
                        condition = true;
                        orderList->deleteNode();
                    }
                }

            }

            else if(a!= nullptr)  //if top most event is of prepare instance, it will read next arrivals and will create complete service instance.
            {
                a->print();
                if(eventList->isEmpty())
                {
                    createPrepareEvent(a, currTime);
                }

                if(version != 3){orderList->insert(a);}

                else if (version == 3){orderList->priorityInsert(a);}  // if order list is a priority queue, insertion be processed according to the max revenue.
            }

        }
            createArrivalEvent(argv,argc,line,inputFile);

    }
}

//-------------------------------------------------------------------
// readLine
//
// PURPOSE      : Reads each line of the file and assign the values of time, expiry and meal accordingly.
//
//-------------------------------------------------------------------

void Execution :: readLine(char* argv[], int argc,  string line)
{
    if(argc != 3)
    {
        cout<<"USAGE: FileReadingExample.exe filename simulationType"<<endl;
        cout<<"where simulationType is either 1, 2 or 3."<<endl;
    }
        stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
        string token;
        int counter = 0;
        numIngredients = 0;

        while (sst >> token)  //grabing one token at a time, until there is no token left
        {
            if (counter == 0) //reading time
                time = stoi(token);
            else if (counter == 1) //reading expiry
                expiry = stoi(token);
            else if (counter == 2) //reading meal type
                meal = token;
            else //counting ingredients from here (if counter > 2)
            {
                numIngredients++;
            }
            counter++;
        }
}


//-------------------------------------------------------------------
// createPrepareEvent
//
// PURPOSE      : Creates a new prepare event in the event list.
// PARAMETERS    : an Arrival event , and int time when preparation was started.
//
//-------------------------------------------------------------------


void Execution::createPrepareEvent(Arrival *a, int tym) {

    Prepare * p = new Prepare(tym, a->getOrderId(), a->getPrepTime(), a->getPrepPrice());
    eventList->insert(p);

}



//-------------------------------------------------------------------------
// createCompleteServiceEvent
//
// PURPOSE       : Creates a new Complete service event in the event list.
// PARAMETERS    : it takes one prepare event's instance as a parameter.
//
//-------------------------------------------------------------------------


void Execution:: createCompleteServiceEvnt(Prepare* p)
{
    //cout << orderId<< " completeService done"<< endl;
    int timee = p->getTime() + p->getPrepTime();
    completeService* c = new completeService( timee, p-> getOrderId() , p->getPrepPrice());
    eventList->insert(c);
    currTime = timee;
    orderList->deleteNode();
    totalOrders++;
    totalRevenue += p->getPrepPrice();
}



//---------------------------------------------------------------------------------------------------------------
// createArrivalEvent
//
// PURPOSE       : Creates a new Arrival event in the event list after reading each line from the input file.
// PARAMETERS    : it is taking arguments as a parameters and then the input file and version of the simulation.
//
//---------------------------------------------------------------------------------------------------------------

void Execution:: createArrivalEvent(char* argv[], int argc,  string line, ifstream &inputFile)
{

    if (getline(inputFile, line))
    {readLine(argv, argc, line);
        orderId++;
        Arrival * newArrival = new Arrival(time,orderId, expiry,meal,numIngredients);
        eventList->insert(newArrival);
       // cout << orderId<< " inserted in event list"<< endl;
    }
    else
    {
        loop = true;
    }




}
