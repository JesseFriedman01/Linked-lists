/*-- LinkedList.h ---------------------------------------------------------------
  This header file defines the data type List for processing lists.
  Basic operations are:
     Constructor
     Destructor
     Copy constructor
     Assignment operator
     empty:    Check if list is empty
     insert:   Insert an item
     erase:    Remove an item
     display:  Output the list
-------------------------------------------------------------------------*/

#ifndef LINKEDLIST
#define LINKEDLIST

typedef int ElementType; // define the type of data in the Linked List
class LinkedList
{
 public:
 /******** Function Members ********/
   /***** Class constructor *****/
   LinkedList();
   /*----------------------------------------------------------------------
     Construct an empty LinkedList object.
   -----------------------------------------------------------------------*/

   /***** Class destructor *****/
   ~LinkedList();
   /*----------------------------------------------------------------------
     Deallocates the memory of a LinkedList object.
     ------------------------------------------------------------------*/

   /***** Copy constructor *****/
   LinkedList(const LinkedList & origList);
   /*----------------------------------------------------------------------
     Construct a copy of a LinkedList object..
   -----------------------------------------------------------------------*/

   /***** Assignment operator *****/
   LinkedList& operator=(const LinkedList & origList);
   /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none 
     Postcondition: A copy of origList has been assigned to this
          object.  A reference to this list is returned.
   -----------------------------------------------------------------------*/

   /***** empty operation *****/
   bool empty() const;
   /*----------------------------------------------------------------------
     Check if a list is empty.
   -----------------------------------------------------------------------*/

   /***** insert and erase *****/
   void insert(ElementType item, int pos);
   /*----------------------------------------------------------------------
     Insert a value into the list at a given position.
   -----------------------------------------------------------------------*/

   void erase(int pos);
   /*----------------------------------------------------------------------
     Remove a value from the list at a given position.
     pos >= 0 and pos < mySize
     
     don't erase from an empty list
     erase the first node
     erase in the middle
     erase the last node
   ----------------------------------------------------------------------*/

   /***** output *****/
   void display() const;
   
   int find(ElementType val);
   /*----------------------------------------------------------------------
    Return the position of a given value in a list, if its exists

    Precondition: user given value is of ElementType
    Postcondition: integer value of position of given value to find is
	returned, if it exists. If not, -1 is returned. 
   -----------------------------------------------------------------------*/
   
   void reverse();
      /*----------------------------------------------------------------------
    Reverses the order of the nodes in the list

    Precondition: 
    Postcondition: modifies existing list such that the order of the nodes in 
	the list are reversed (first node becomes last, last becomes first, etc.). 
   -----------------------------------------------------------------------*/
   
   void merge (const LinkedList & listA, const LinkedList & listB );
    /*----------------------------------------------------------------------
    Merges two lists in ascending order

    Precondition: both lists are already sorted in ascending order
    Postcondition: modifies the list/nodes of calling object such that it 
    will now contain a total number of nodes equal to the size of both lists
    combined, where each node sequential node has an equal or greater data,
    data member compared to the the prior node.
   -----------------------------------------------------------------------*/

 private: // data members
         
    class Node{
          // data members of a Node object:
          public: ElementType data;
                  Node *next;
                  Node();
    };
   /******** Data Members of a Linked List object********/
   int mySize;                // current size of list stored in array
   Node *first;  // pointer to dynamically-allocated array

}; //--- end of List class


#endif 
