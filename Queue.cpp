/********************************************************************
*** NAME	    : Jevic Tshilumba                                 ***
*** CLASS	    : CSC 300                                         ***
*** ASSIGNMENT	: 4                                               ***
*** DUE DATE	: 17-05-2022                                      ***
*** INSTRUCTOR	: Ken Gamradt	                                  ***
*********************************************************************/

#include <iostream>
#include "Queue.h"

using namespace std;

//*****************************
// default constructor function                                      
//*****************************
Queue::Queue( const short value ) : queue(nullptr), Q_SIZE(value), front(-1), back (-1)
{
    queue = new (nothrow) QElement [Q_SIZE];
}

//*************************************************
// inserts a new element to the back of the queue *                                     
//*************************************************

void Queue::enQueue( const QElement element)
{

    if (isFull())
    {
        cout << "can't use" << element << endl;
        return;
    }

   else if (isEmpty())
    {
        front++;
        back++;
    }
    else   
    {
        back++;
    }


}
//**********************************************************
// removes an existing element from the front of the queue *                                     
//**********************************************************

void Queue::deQueue( QElement & element)
{
    if (isEmpty())
    {
        return;
    }

    if(front == back)
    {
        element = queue[front];
        front = -1;
        back = -1;
    }
    else 
    {
        element = queue[front];
        front++;
    }
}


//****************************************************
// destructor function – destroys the existing queue *                                     
//****************************************************

Queue::~Queue()
{
    QElement element;

    while(!isEmpty())
    {
        deQueue(element);
    }
}

//************************************************************************
// returns true if the current queue instance is empty – false otherwise *                                     
//************************************************************************

bool Queue::isEmpty() const
{
    if(front == -1 && back == -1)
        return true;
    else
        return false;
}
//***********************************************************************
// returns true if the current queue instance is full – false otherwise *                                     
//***********************************************************************

bool Queue::isFull() const
{
    if ((back + 1) == front)
        return true;
    else   
        return false;
}

//***********************************************************
// creates an initialized empty queue (+) default size of 3 *                                     
//************************************************************

Queue::Queue( Queue & queu) : queue(nullptr), Q_SIZE(queu.Q_SIZE), front(-1), back(-1)
{
    queue = new (std::nothrow) QElement [Q_SIZE];

    QElement num;

    Queue one (Q_SIZE);

    while (!queu.isEmpty())
    {
        queu.deQueue(num);
        one.enQueue(num);
    }

    while (!one.isEmpty())
    {
        one.deQueue(num);
        queu.enQueue(num);
        enQueue(num);
    }

}

//********************************************************************
// displays the contents of the queue from the front to the back (*) *                                     
//********************************************************************

void Queue::view()
{
    Queue ele(Q_SIZE);

    QElement element;

    cout << "FRONT - ";

    while (!isEmpty())
    {
        deQueue (element);
        cout << element << "- ";
        ele.enQueue(element);
    }

    while (!ele.isEmpty())
    {
        ele.deQueue(element);
        enQueue(element);
    }
}
