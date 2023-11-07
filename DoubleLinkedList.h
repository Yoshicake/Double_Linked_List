#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

using namespace std;

class DoubleLinkedList {
    private:
        struct Node{
        
            int value;
            Node *previous;
            Node *next;
            
        };
        Node* head;

        int count;


    public:
        DoubleLinkedList();
        virtual void insert(int value);
        virtual void merge(DoubleLinkedList *absorbedList);
        virtual void remove(int value);
        virtual const int& operator[](int index);
        virtual int getCount() const;
        virtual void display(int reverse = false) const;
};












#endif