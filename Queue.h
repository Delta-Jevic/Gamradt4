/********************************************************************
*** NAME	    : Jevic Tshilumba                                 ***
*** CLASS	    : CSC 300                                         ***
*** ASSIGNMENT	: 4                                               ***
*** DUE DATE	: 17-05-2022                                      ***
*** INSTRUCTOR	: Ken Gamradt	                                  ***
*********************************************************************/

#ifndef QUEUE_H                                                 // Gaurd
#define QUEUE_H

typedef double QElement; 

class Queue {

public:                                                        // exportable
// General description of each the ADT operations/functions - exportable operations only
       Queue(...);                                            // replace ... with required arguments
       Queue( Queue &);                                        // reuse enQueue & deQueue
       ~Queue();                                               // reuse deQueue 
       void enQueue( const QElement Element);
       void deQueue( QElement & );
       void view();                                            // reuse enQueue & de Queue
private:                                                       // non-exportable
// No private member documentation - implementation details are hidden/abstracted away
       const short Q_SIZE;                                     // must be initializaed
       typedef QElement * QPointer;
       QPointer queue;
       short front, back;
       bool isEmpty() const;
       bool isFull() const;

};

#endif                                                          // Guard