#ifndef _SLL_H_
#define _SLL_H_

#include <cstddef>

#include "Commons.h"
/**
 * This class represents a single-linked-list.
 */
template<class Item>
class SLL_Container{
    private:
        Item *item;
        SLL_Container *next;
    public:
        SLL_Container<Item>(Item *newItem);
        SLL_Container<Item> *getNext();
        Item *getItem();
        void setNext(SLL_Container *newNext);
        int compare(Item *item);
        void freeContainer();
};

template<class Item>
class SLL {
    private:
        SLL_Container<Item> *head;
        unsigned int itemNum;
        void (*printFunction)(void*);
    public:
        SLL<Item>();
        SLL<Item>(Item *item);
        ~SLL<Item>();
        
        Item *pop();
        void push(Item *item);
        void append(Item *item);
        void insert(Item *item, unsigned int index);
        Item *itemAt(unsigned int index);
        unsigned int length();
};


#endif
