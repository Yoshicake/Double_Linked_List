#include "DoubleLinkedList.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

int main() {
    DoubleLinkedList firstList;
    firstList.insert(5);
    firstList.insert(2);
    firstList.insert(1);
    firstList.insert(3);
    
    firstList.insert(6);
    firstList.insert(7);
    firstList.insert(3);
    cout << "First List:" << endl;
    firstList.display();
    firstList.display(true);
    cout << "Removing 3, 1, 10, and 7" << endl;
    firstList.remove(3);
    firstList.remove(1);
    firstList.remove(10);
    firstList.remove(7);
    firstList.display();
    cout << "First List Count: " << firstList.getCount() << endl;
    DoubleLinkedList secondList;
    cout << "First number in the list: " << firstList[1] << endl;
    DoubleLinkedList three;
    
    secondList.insert(10);
    secondList.insert(8);
    secondList.insert(20);
    cout << endl << "Second List:" << endl;
    secondList.display();
    cout << endl << "Merging" << endl;
    firstList.merge(&secondList);
    secondList.display();
    firstList.display();



}