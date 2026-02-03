/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
    //std::cout << "starting push " << std::endl;
	/* Your code here */
	node *newNode = new node();
	newNode->data = item;
	newNode->priority = priority;
	
	//std::cout << "starting assignment " << std::endl;
	
	node *currNode = front;
	
    //std::cout << "ending assignment " << std::endl;

	if (front == NULL || front->priority >= priority)
	{
	    newNode->link = front;
	    front = newNode;
	    //std::cout << "ending push" << std::endl;
	    return;
	}
	
	while (currNode->link != NULL)
	{
	    if (currNode->link->priority >= priority)
	    {
	        newNode->link = currNode->link;
	        currNode->link = newNode;
	        //std::cout << "ending push" << std::endl;
	        return;
	    }
	    currNode = currNode->link;
	}
	
	currNode->link = newNode;
	newNode->link = NULL;
	
	//std::cout << "ending push" << std::endl;
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
    //std::cout << "starting top " << std::endl;
    if (front == NULL)
    {
        //std::cout << "ending top" << std::endl;
        return NULL;
    }
	node *out = front;
	void *outData = out->data;
	//front = front->link;
	//delete out;
	//std::cout << "ending top" << std::endl;
	return outData;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
    //std::cout << "starting pop " << std::endl;
	node *pastFront = front;
	if (front == NULL)
    {
       // std::cout << "ending pop" << std::endl;
        return;
    }
	front = front->link;
	delete pastFront;
	//delete pastFront;
	//std::cout << "ending pop" << std::endl;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
//	std::cout << "starting display " << std::endl;
	
	/* Use the following out command for the data */
	node *ptr = front;
	while (ptr)
	{
	    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
	    ptr = ptr->link;
	}
	
//	std::cout << "ending display" << std::endl;
}
	