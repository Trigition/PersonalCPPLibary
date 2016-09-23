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

template<class Item>
class DLL {
    private:
        DLL_Container<Item> *head;
        DLL_Container<Item> *tail;
        unsigned int itemNum;
    public:
        DLL<Item>() {
            this->head = NULL;
            this->tail = NULL;
            this->itemNum = 0;
        };

        DLL<Item>(Item *item) {
            this->head = new DLL_Container<Item>(item);
            this->tail = this->head;
            this->itemNum = 1;
        };

        ~DLL<Item>() {
            if (this->isEmpty()) {
                return;
            }
            Item *curItem;
            while(!(this->isEmpty())) {
                curItem = this->pop();
                delete curItem;
            }
        };

        Item *pop() {
            if (this->isEmpty()) {
                return NULL;
            }
            SLL_Container<Item> *tmpContainer = this->head; 
            Item *rtrnItem;
            rtrnItem = tmpContainer->getItem();
            this->head = this->head->getNext();
            delete this->head->getPrev();
            this->head->setPrev(NULL);
            this->itemNum--;
            return rtrnItem;
        };
        
        void insert(Item *item, unsigned int index) {
            //Check if index specified is even possible in this linked list
            if (index > this->itemNum) {
                return;
            } else if (index == 0) {
                //If index is 0 we are just doing a push
                this->push(item);
                return;
            }            
            SLL_Container<Item> *newItem = new SLL_Container<Item>(item);
            unsigned int i;
            for (i = 0; i < index - 1; i++) {
                curItem = curItem->getNext();
            }
            // Check if we are inserting between two elements
            if (curItem->getNext() == NULL) {
                
            }
        };

        bool isEmpty() {
            return this->itemNum == 0;
        };
};
#endif
