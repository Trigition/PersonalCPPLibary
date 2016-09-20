#include "SLL.h"

//======================================
//Define Methods for SLL_Container class
//======================================

/**
 * This method is the main constructor for the SLL_Class
 */
template<class Item>
SLL_Container<Item>::SLL_Container(Item *newItem) {
    this->item = item;
    this->next = NULL;
};

/**
 * This method gets the next SLL Container in the list
 */
template<class Item>
SLL_Container<Item> *SLL_Container<Item>::getNext() {
    return this->next;
};

template<class Item>
Item* SLL_Container<Item>::getItem() {
    return this->item;
};

/**
 * This method sets the next item in the list.
 */
template<class Item>
void SLL_Container<Item>::setNext(SLL_Container *newNext) {
    this->next = newNext;
};

template<class Item>
int SLL_Container<Item>::compare(Item *item) {
    return this->item = item;
}

template<class Item>
void SLL_Container<Item>::freeContainer() {
    this->freeContainer();
}

//============================
//Define methods for SLL Class
//============================

template<class Item>
SLL<Item>::SLL() {
    this->head = NULL;
    this->itemNum = 0;
};

template<class Item>
SLL<Item>::SLL(Item *head) {
    this->head = new SLL_Container<Item>(head);
};

template<class Item>
SLL<Item>::~SLL() {
    if(this->head == NULL) {
        return;
    }
    SLL_Container<Item> *curItem = this->head;
    SLL_Container<Item> *prevItem = this->head;
    unsigned int i;
    for(i = 0; i < this->itemNum; i++) {
        curItem = this->head->next;
        delete prevItem;
        prevItem = curItem;
    }
};

template<class Item>
Item* SLL<Item>::pop() {
    if (this->head == NULL) {
        return NULL;
    }
    SLL_Container<Item> *rtrn = this->head;
    this->head = this->head->next;
    this->itemNum--;
    return rtrn;
};

template<class Item>
void SLL<Item>::push(Item *item) {
  return;
};

template<class Item>
void SLL<Item>::append(Item *item) {
  return;
};

template<class Item>
void SLL<Item>::insert(Item *item, unsigned int index) {
    SLL_Container<Item> *newItem = new SLL_Container<Item>(item);
    SLL_Container<Item> *tmpItem;

    //Check if index specified is even possible in this linked list
    if (index > this->itemNum) {
        return;
    } else if (index == 0) {
        //Check if we are just pushing to head;
        this->head = newItem;
        return;
    }

    unsigned int i = 0;
    SLL_Container<Item> *curItem = this->head;
    while(i < index) {
        curItem = curItem->next;
        i++;
    }
    // Check if we are inserting between two elements
    if (curItem->next == NULL) {
        // We are inserting at the end of list
    } else {
        // We are inserting somewhere 0 < i < n
        tmpItem = curItem->next;
        curItem->next = newItem;
        newItem->next = tmpItem;
    }
    this->itemNum++;
};

template<class Item>
Item* SLL<Item>::itemAt(unsigned int index) {
    if (index > this->itemNum) {
        return NULL;
    } else if (index == 0) {
        return this->head->getItem();
    }
    unsigned int i = 0;
    SLL_Container<Item> *curItem = this->head;
    while(i < index) {
        curItem = curItem->next;
    }
    return curItem->getItem;
};

template<class Item>
unsigned int SLL<Item>::length() {
    return this->itemNum;
};
