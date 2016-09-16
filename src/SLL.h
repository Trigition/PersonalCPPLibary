#ifndef _SLL_H_
#define _SLL_H_

#include <cstddef>

#include "Commons.h"
#include "Item.h"
/**
 * This class represents a single-linked-list.
 */
class SLL_Container : Item{
    private:
        SLL_Container *next;
    public:
        SLL_Container (void *content);
        SLL_Container *getNext();
        void setNext(SLL_Container *newNext);
        virtual int compare(const void* item1, const void* item2);
        virtual void freeContainer();
};

class SLL {
    private:
        SLL_Container *head;
        unsigned int itemNum;
        void (*printFunction)(void*);
    public:
        SLL();
        SLL(Item *head);
        ~SLL();

        SLL_Container *castItem(Item *item);
        void push(Item *item);
        void append(Item *item);
        void insert(Item *item, unsigned int index);
        void print();
        void registerPrintFunction(void (*printFunction)(void *));
        Item *itemAt(unsigned int index);
};


#endif
