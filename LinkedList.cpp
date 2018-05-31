// implementation file for the LinkedList class

#include "LinkedList.h"
#include <iostream>
#include <cassert>
using namespace std;

// g++ -c LinkedList.cpp - just compiles this file
// Node() constructor: initialize the data members with default values
LinkedList::Node::Node()
{
   data = 0;
   next = 0;// points nowhere (null pointer)
}

// Default constructor for the linked list 
// initializes the data members of a new, empty list object
LinkedList::LinkedList()
{
    first = 0;
    mySize = 0;   
}

// destructor
// Traverse the list and deallocate memory for each node in the list
// T(N) = O(?)
LinkedList::~LinkedList()
{
   // declare a pointer to Node
   Node *ptr = 0;
   // loop while ptr ! = 0
   while ( first != 0 )
    {
    	// 0. ptr point to first Node
    	ptr = first;

		// 1. make first point to the next node in the list (keep a connection
		// with the remaining list nodes
		first = ptr -> next;
		
		// 2. deallocate memory for the node pointed by ptr
		delete ptr;
    }
}

// copy constructor = instantiates a new object as a copy of an 
// existing object
// LinkedList l1(l2);
LinkedList::LinkedList(const LinkedList &old)
{
	mySize = 0;
	
   // if old list is empty, then just initialize first and mySize to 0
    if (old.first == 0)
        first = 0;
   else
   {	
    	Node *ptrOld;
	   	
	   	ptrOld = old.first -> next;
		
	   	int i = 0;
	   		   	 
	   	while ( ptrOld != 0 )
	   	{	
	   		if ( i == 0 )
	   			insert ( old.first -> data, 0 );
	   		else
	   		{
				insert ( ptrOld -> data, i );
	   			ptrOld = ptrOld -> next;
   			}
   			
			i++;
	    }
 	}					 
} // end copy constructor

// Assignment operator (operator=)
// code: l1 = l2;  l1 will be a linked list object identical to l2
// compiler generated call to operator= function: l1.operator=(l2); 
LinkedList &LinkedList::operator=(const LinkedList &other)
{
	if (this != &other) // check for self-assignment l1 = l1
	{
 	   if (mySize == other.mySize) // both lists have the same size
 	   {
		    Node *ptrOther;
		   	
		   	ptrOther = other.first -> next;
			
		   	int i = 0;
	   		   	 
		   	while ( ptrOther != 0 )
		   	{	
		   		if ( i == 0 )
		   			insert ( other.first -> data, 0 );
		   		else
		   		{
					insert ( ptrOther -> data, i );
		   			ptrOther = ptrOther -> next;
	   			}
	   			
				i++;	
			}
	    }
        else 
        {
   	        // deallocate memory for all nodes in the calling object
			// cannot call the destructor explicitly, but it is a similar code
			Node *ptr;
			
		    while ( first != 0 )
	    	{
	          	// 0. ptr point to first Node
		    	ptr = first;
		
				// 1. make first point to the next node in the list (keep a connection
				// with the remaining list nodes
				first = ptr -> next;
				
				// 2. deallocate memory for the node pointed by ptr
				delete ptr;
	    	}
	
		    // construct a new link list for the calling object that 
		    // matches each node in the other list 		   
	 	    // starting point = the code from copyConstructor
	 	    	    
	 	    mySize = 0;
	
		    if (other.first == 0)
		        first = 0;
		   	else
		   	{	
		    	Node *ptrOther;
			   	
			   	ptrOther = other.first -> next;
				
			   	int i = 0;
			   		   	 
			   	while ( ptrOther != 0 )
			   	{	
			   		if ( i == 0 )
			   			insert ( other.first -> data, 0 );
			   		else
			   		{
						insert ( ptrOther -> data, i );
			   			ptrOther = ptrOther -> next;
		   			}
		   			
					i++;
			    }
		 	}		
 	  	}
	}
	return *this;
}

bool LinkedList::empty() const
{
   if (mySize == 0)
     return true;
   else 
     return false;
}

// insert a new item in the list after pos nodes
// Pre-conditions: conditions satisfied at the beginning of a function
//  	pos has a valid value
// Post-condition = a new node with newItem data stored in the node at pos
void LinkedList::insert(ElementType newItem, int pos)
{
     assert ((pos >= 0) && (pos <= mySize));
     // initialize pointers to Node objects
     Node *ptrNew, *ptr, *ptrPred, *ptrTemp;
	 // insert in an empty list	or at the beginning of a list 
	 if ( mySize == 0 )
	 {
	 	// create dynamically allocated Node object
		ptrNew = new Node;
		// set data member first to prtNew
		first = ptrNew;
		// set the data member first to newItem
		first -> data = newItem;	
	 }
	 	 
	 else // insert somewhere in the middle of the list
	 {
	  	ptrNew = new Node;
	 		  	
		ptrNew -> data = newItem;

		ptr = first;
			
		int i = 0;
		// if not entering in the beginning of the list and the list isn't empty
		if ( pos != 0 )
		{
			// while there is still a node in the list
			while ( ptr != 0 )
			{
				// if at the right position in the lost (pos)
				if ( i == pos )
				{
					// copy pointer to node in current position in a temporary pointer
					ptrTemp = ptr;
					// the memory address of the prior node's next data member is now the memory address of the new node
					ptrPred -> next = ptrNew;
					// the memory address of the new node's next data member is now the address of the temporary pointer
					ptrNew -> next = ptrTemp;
					// break because there's no need to keep going through the list
					break;
				}	
				i++;
				// always one node behind (i.e. the prior node)
				ptrPred = ptr;
				// set ptr to the next node
				ptr = ptr -> next;	
			}
			// set the prior node's next data member to the new node
			ptrPred -> next = ptrNew;
		}
		
		// entering node at the beginning of the the list but the list isn't empty
		else
		{
			ptrTemp = first;
			first = ptrNew;
			first -> next = ptrTemp;
		}
	}
	mySize++;	
}

void LinkedList::display() const
{
	// set ptr to the memory address of the first node
     Node *ptr = first;
     // while there are still nodes in the list
     while ( ptr != 0 )
     {
     	// print the node's data member
        cout << ptr -> data << endl;
        // advance ptr to the next object
        ptr = ptr -> next;
     }
     cout << endl;
}

void LinkedList::erase(int pos)
{
	assert(pos >=0 && pos <mySize);
	
	// cannot erase a node in am empty list
	if ( empty() )
		cout << "Empty list - nothing to erase " << endl;
	else
	{
		Node *ptr = first;
		// erase the first node in the list ?
		if (pos == 0)
		{
			// set first to to the next node because we are deleting the first node
			first = ptr-> next;
			delete ptr;
		}
		else // erase somewhere in the list except at the beginnig
		{
			Node *ptrPred;	
			
			// iterate through the list until you get to the position that you want to erase
		 	for ( int i = 0; i < pos; i++ )
			{	
				// ptrPred will be equal the node prior to the node to erase
				ptrPred = ptr;
				// ptr will be the node to erase
				ptr = ptr -> next;
			}
		 	// set ptrPred's next data member to the next data member of ptr before its erased
		 	ptrPred -> next = ptr -> next;
		 	delete ptr;
		}
	
		// decrement size of list	
		mySize--;
		}
}

int LinkedList::find(ElementType val)
{
	if ( empty() )
		cout << "Empty list - nothing to find " << endl;
	else
	{
		Node *ptr = first;
		int i = 0;
		// iterate through the list while there are still nodes
		while ( ptr != 0 )	
		{	
			// compare data member of ptr to data that we're looking for (val)
			if ( ptr -> data == val )
				// return the position if it matches
				return i;
			// increment i	
			i++;		
			// increment ptr to the next node	
			ptr = ptr -> next;
		}
		// if val is not found return -1
		return -1;
	}
}

void LinkedList::reverse()
{
	if ( empty() )
		cout << "Empty list - nothing to reverse " << endl;
	else 
		{
		Node *ptrPred = 0, *ptr = first, *ptrNext = 0;
		
		// iterate through the list while there are still nodes
		while ( ptr != 0 ) 
		{
		  // set ptrNext to the next data member of ptr
	      ptrNext = ptr -> next;
			
		  // set next of ptr to the memory address of the prior node	
		  ptr -> next = ptrPred;
		
		  // set the prior node to ptr
		  ptrPred = ptr;
		  
		  //set ptr to ptrNext
		  ptr = ptrNext;
		}
		
		//set first to the prior node (or what was the last node)
		first = ptrPred;
		}
}

void LinkedList::merge (const LinkedList & listA, const LinkedList & listB )
{
	int listA_counter = 0, listB_counter =0;
	
	int total_size = listA.mySize + listB.mySize;
	
	int val_from_A;
	int val_from_B;
	
	Node *ptrA, *ptrB;
	
	// iterate while i is less than the size of both lists combined	
	for (int i = 0; i < total_size; i++ )
	{
		ptrA = listA.first;
		ptrB = listB.first;
		
		// true when at end of array_a
		bool at_end_listA = ( listA_counter >= listA.mySize );	
		// true when at end of array_b	
		bool at_end_listB = ( listB_counter >= listB.mySize );				
		
		// if not at the end of ether list
		if ( !at_end_listA && !at_end_listB )
		{
			// iterate through listA
			for (int j = 0; j < listA.mySize; j++ )
			{
				// examine the node in jth position of listA
				if ( j == listA_counter)
					{
					// set val_from_a equal to the data of that node
					val_from_A = ptrA -> data;
					break;
					}
				// advance to the next node
				ptrA = ptrA -> next;
			}
			
			// same as above but for listB
			for (int k = 0; k < listB.mySize; k++ )
			{
				if ( k == listB_counter)
					{
					val_from_B = ptrB -> data;
					break;
					}
				
				ptrB = ptrB -> next;
			}
			
			// if the data from the node in listA is less than the data from the node in listB
			if ( val_from_A < val_from_B ) 
				{
				// call insert function with this value and the current position of i
				insert ( val_from_A, i );
				// increment listA counter
				listA_counter++;
				}
			// if both lists' data is the same	
			else if ( val_from_A == val_from_B )
				{
				// call insert function twice with both values so its inserted twice in the new list (2 new nodes are created)
				insert ( val_from_A, i );
				insert ( val_from_B, i + 1 );
				// iterate both counters and i 
				listA_counter++;
				listB_counter++;
				i++;	
				}
			// data from node in listA is greater than data in from node in listB	
			else
				{	
				// call insert function to insert this data as a new node in the new list
				insert ( val_from_B, i );
				listB_counter++;	
				}
		}	
	
		else 
		{
			// if at end of listA
			if (at_end_listA)
			{
				// insert the remaining values of listB into the new list (they're already sorted)
				for (int l = 0; l < listB.mySize; l++ )
				{
					if (l == listB_counter )
						insert ( ptrB -> data, i );
				
					ptrB = ptrB -> next;
				}
				listB_counter++;
			}
			
			// if at end of the listB			
			else
			// insert the remaining values of listA into the new list (they're already sorted)
			{
				for (int l = 0; l < listA.mySize; l++ )
				{
					if (l == listA_counter )
						insert ( ptrA -> data, i );
				
					ptrA = ptrA -> next;
				}
				listA_counter++;
			}
		}
	}	
}


