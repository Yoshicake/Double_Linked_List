#include "DoubleLinkedList.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    count = 0;
    head = nullptr;
}

void DoubleLinkedList::insert(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    Node* currentNode;
    Node* previous = nullptr;
    if (!head) {
        head = newNode;
        newNode->next = nullptr;
        newNode->previous = nullptr;
    }
    else {

        currentNode = head;
        previous = nullptr;

        while ((currentNode != nullptr) && (currentNode->value < value)) {
            previous = currentNode;
            currentNode = currentNode->next;
        }

        if (previous == nullptr) {
            head = newNode;
            newNode->next = currentNode;
            newNode->previous = nullptr;
            currentNode->previous = newNode;
        }
        else {
            newNode->next = currentNode;
            previous->next = newNode;
            newNode->previous = previous;
            if (currentNode != nullptr) {
                currentNode->previous = newNode;
            }
        }
    }
    count++;
}

void DoubleLinkedList::merge(DoubleLinkedList *absorbedList) {
    Node* currentNode = absorbedList->head;
    Node* nextNode = currentNode->next;
    while (currentNode != nullptr) {
        insert(currentNode->value);
        delete currentNode;
        absorbedList->count--;
        currentNode = nextNode;
        if (currentNode != nullptr) {
            nextNode = currentNode->next;
        }
    }
    
}

void DoubleLinkedList::remove(int value) {
    int index = 0;
    Node* currentNode;
    Node* previous = nullptr;
    Node* next = nullptr;

    if (!head) {
        cout << "No list." << endl;
    }

    if (head->value == value) {
        currentNode = head->next;
        currentNode->previous = nullptr;
        delete head;
        head = currentNode;
        count--;
    } else {
        currentNode = head;
        while ((currentNode != nullptr) && (currentNode->value != value)) {
            previous = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode) {   
            if (currentNode->next != nullptr) {
                next = currentNode->next;
                next->previous = previous;
            }
            previous->next=currentNode->next;
            delete currentNode;
            count--;
        } else {
            cout << "Value does not exist." << endl;
        }
    }    
}

const int &DoubleLinkedList::operator[](int index) {
    if ((index >= count) || (index < 0)) {
        throw IndexOutOfBoundsException();
    } else {
        Node* currentNode = head;
        for (int i = 1; i < index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->value;
    }
}

int DoubleLinkedList::getCount() const {
    return count;
}

void DoubleLinkedList::display(int reverse) const {
    if (reverse == false) {
        Node* currentNode = head;
        cout << "List in ascending order: ";
        for (int i = 0; i < count; i++) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
    } else if (reverse == true) {
        Node* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        cout << "List in descending order: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << currentNode->value << " ";
            currentNode = currentNode->previous;
        }
    }
    cout << endl
         << endl;
}