#ifndef _SLL_H_
#define _SLL_H_

#include <iostream>
#include <cstddef>
#include <type_traits>
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
        SLL_Container<Item>(Item *newItem) {this->item = newItem;
                                            this->next = NULL;};
        SLL_Container<Item> *getNext() {return this->next;};
        Item *getItem() {return this->item;};
        void setNext(SLL_Container *newNext) {this->next = newNext;};
        int compare(Item *item) {return this->item = item;};
        void freeContainer() {delete this->item;};
};

template<class Item>
class SLL {
    private:
        SLL_Container<Item> *head;
        unsigned int itemNum;
        void (*printFunction)(void*);
    public:
        SLL<Item>() {
            this->head = NULL;
            this->itemNum = 0;
        };
        SLL<Item>(Item *item) {
            this->head = new SLL_Container<Item>(head);
            this->itemNum = 0;
        };
        ~SLL<Item>() {
            if(this->head == NULL) {
                return;
            }
            Item *curItem;
            unsigned int i;
            while(!(this->isEmpty())) {
                curItem = this->pop();
                delete curItem;
            };
        };
        
        Item *pop() {
            if (this->head == NULL) {
                return NULL;
            }
            // Grab "Top" element and separate it from its item so the SLL_Container
            // can be freed without the programmer needing to worry about the wrapper.
            SLL_Container<Item> *rtrnSLL = this->head;
            Item *rtrnItem;
            rtrnItem = this->head->getItem();
            this->head = this->head->getNext();
            
            delete rtrnSLL;
            this->itemNum--;
            return rtrnItem;
        };

        void insert(Item *item, unsigned int index) {
            //Check if index specified is even possible in this linked list
            if (index > this->itemNum) {
                return;
            } else if (index == 0) {
                //Check if we are just pushing to head;
                this->push(item);
                return;
            }

            SLL_Container<Item> *newItem = new SLL_Container<Item>(item);
            SLL_Container<Item> *tmpItem;

            unsigned int i = 0;
            SLL_Container<Item> *curItem = this->head;
            while(i < (index - 1)) {
                curItem = curItem->getNext();
                i++;
            }
            // Check if we are inserting between two elements
            if (curItem->getNext() == NULL) {
                // We are inserting at the end of list
                curItem->setNext(newItem);
            } else {
            // We are inserting somewhere 0 < i < n
                tmpItem = curItem->getNext();
                curItem->setNext(newItem);
                newItem->setNext(tmpItem);
            }
            this->itemNum++;
        };
        
        void append(Item *item) {
            SLL_Container<Item> *curItem = this->head;
            SLL_Container<Item> *newItem = new SLL_Container<Item>(item);
            if (this->itemNum == 0) {
                curItem = newItem;
                return;
            }
            while(curItem->getNext() != NULL) {
                curItem = curItem->getNext();
            }
            curItem->setNext(newItem);
            this->itemNum++;
        };
        
        void push(Item *item) {
            SLL_Container<Item> *newItem = new SLL_Container<Item>(item);
            newItem->setNext(this->head);
            this->head = newItem;
            this->itemNum++;
        };

        Item *itemAt(unsigned int index) {
            if (index > this->itemNum || this->head == NULL) {
                return NULL;
            } else if (index == 0) {
                return this->head->getItem();
            }
            unsigned int i;
            SLL_Container<Item> *curItem = this->head;
            for (i = 0; i < index; i++) {
                curItem = curItem->getNext();
            }
            return curItem->getItem();
        };
        unsigned int length() {return this->itemNum;};
        bool isEmpty() {return this->itemNum == 0;};
        void print() {
            SLL_Container<Item> *curItem = this->head;
            while(curItem != NULL) {
                std::cout << *(curItem->getItem());
                std::cout << "\n";
                curItem = curItem->getNext();
            }
        };
};
#endif
