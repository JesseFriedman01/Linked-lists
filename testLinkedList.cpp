#include "LinkedList.h"
#include <iostream>

using namespace std;

void print_line();

int main()
{
	// create new LinkedList object
    LinkedList listA;
    
    // call insert function member of listA and insert 1 in the 0th node 
    listA.insert(1,0);
    // call insert function member of listA and insert 2 in the 1st node 
    listA.insert(2,1);
    // call insert function member of listA and insert 3 in the 2nd node 
    listA.insert(3,2);
    // call insert function member of listA and insert 5 in the 3rd node 
    listA.insert(5,3);
    // call insert function member of listA and insert 7 in the 4th node
    listA.insert(7,4);
    // call insert function member of listA and insert 7 in the 4th node (note that there is already a node in this position)
    listA.insert(6,4);
   
    cout << "List A:" << endl << endl;
	
	// call display function member of listA    
    listA.display();

	print_line();
	
	// create new LinkedList object
    LinkedList listB;
    
    // call insert function member of listB and insert 3 in the 0th node 
    listB.insert(3,0);
    // call insert function member of listB and insert 7 in the 1st node 
    listB.insert(7,1);
    // call insert function member of listB and insert 8 in the 2nd node 
    listB.insert(8,2);
    // call insert function member of listB and insert 23 in the 3rd node 
    listB.insert(23,3);
    // call insert function member of listB and insert 26 in the 4th node 
    listB.insert(26,4);
    // call insert function member of listB and insert 34 in the 5th node 
    listB.insert(34,5);
    
    cout << "List B:" << endl << endl;
    
    // call display function member of listB    
    listB.display();
 
	// create new LinkedList object    
	LinkedList listC;
	
	// call insert function member of listC and insert 10 in the 0th node 	
	listC.insert(10,0);
	// call insert function member of listC and insert 3 in the 1st node 
	listC.insert(3,1);
	// call insert function member of listC and insert 26 in the 0th node (note that there is already a 0th node)
	listC.insert(26,0);
	
	print_line();
	    
    cout << "List C (pre assignment operator):" << endl << endl;
    
    // call display function member of listC
    listC.display();
    
    // set ListC equal to listA via the assignment operator (will create a deep copy)
    listC = (listA);
    
    print_line();
    
    cout << "List C (post assignment operator -- List C = List A):" << endl << endl;
    
    // call display function member of listC
    listC.display();
    
	// create new LinkedList object and copy listB to listD via the copy constructor (will create a deep copy)
    LinkedList listD (listB);
    
    print_line();
    
    cout << "List D (via copy constructor -- List D is a copy of List B):" << endl << endl;
    
	// call display function member of listC    
    listD.display();
    
    print_line();
    
    int pos_to_erase;
    
    cout << "Enter the position of the node that you wish to erase in List D: ";
    cin >> pos_to_erase;
    
    // call erase function member with the pos_to_erase as input    
    listD.erase(pos_to_erase);
    
    cout << "\nList D (after node erased in position " << pos_to_erase << "):" << endl << endl;
    
    // call display function member of listD
    listD.display();
     
    print_line();
    
    int val_to_find;
        
    cout << "Enter a value to find in List D: ";
    cin >> val_to_find;
    
    // set loc equal to the return value of the function member find from calling object listD with the input as the numeric value to find
    int loc = listD.find( val_to_find );
    
    if ( loc == -1 )
    	cout << "\nValue not found!" << endl;
    else
    	cout << "\nValue found at position: " << loc << endl;
     
	print_line();
        	
	cout << "List A and B merged into new list (in ascending order including duplicates): " << endl;
	
	// create new LinkedList object
	LinkedList mergedList;
	
	// call function member merge from calling object mergedList with listA and listB as inputs
	mergedList.merge ( listA, listB );
	
	// call display function member of listD
	mergedList.display();
	
	print_line();
	
	cout << "Merged list reversed:\n" << endl;
	
	// call reverse function member of mergedList
	mergedList.reverse();

	// call display function member of listD	
	mergedList.display();

}

void print_line()
{
	cout << "___________________________\n" << endl;	
}
