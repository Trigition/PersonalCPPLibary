#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <cstddef>
#include "Commons.h"
#include "Linked.h"

template<class Item>
class DLL_Container : public ForwardLink, public BackwardLink {
    private:
        Item *item;
    public:
        DLL_Container<Item>(Item *newItem) {
            this->item = newItem;
            this->setNext(NULL);
            this->setPrev(NULL);
        };
        DLL_Container<Item>(Item *newItem, DLL_Container *previous, DLL_Container *next) {
            this->item = newItem;
            this->setPrev(previous);
            this->setNext(next);
        };
        Item *getItem() {return this->item;};
        void *setItem(Item *newItem) {
            Item *tmpItem = this->item;
            this->item = newItem;
            delete tmpItem;
        };
};

#endif
