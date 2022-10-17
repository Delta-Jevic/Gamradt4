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

//******************************************************************************************
// default constructor function – creates an initialized empty queue (+) default size of 3 *                                     
//******************************************************************************************

Queue::Queue( Queue & que) : queue(nullptr), Q_SIZE(que.Q_SIZE), front(-1), back(-1)  
{
    queue = new (std::nothrow) QElement [Q_SIZE];

    QElement value;

    Queue first (Q_SIZE);

    while (!first.isEmpty())
    {
        first.deQueue(value);
        que.enQueue(value);
        enQueue(value);
    }

}
//*************************************************
// inserts a new element to the back of the queue *                                     
//*************************************************

void Queue::enQueue( const QElement element)
{

    if (isFull())
    {
        cout << element << endl;
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