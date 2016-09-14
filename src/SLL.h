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
        ~SLL_Container();
        SLL_Container *getNext();
        void setNext(SLL_Container *newNext);
};

class SLL {
    private:
        SLL_Container *head;
        unsigned int itemNum;
    public:
        SLL();
        SLL(Item *head);
        ~SLL();

        void push(Item *item);
        void append(Item *item);
        void insert(Item *item, unsigned int index);
        Item *itemAt(unsigned int index);
};


#endif
