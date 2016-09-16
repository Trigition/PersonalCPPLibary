#include "SLL.h"

//======================================
//Define Methods for SLL_Container class
//======================================

/**
 * This method is the main constructor for the SLL_Class
 */
SLL_Container::SLL_Container(void *content) {
    this->setContainer(content);
    this->next = NULL;
};

/**
 * This method gets the next SLL Container in the list
 */
SLL_Container * SLL_Container::getNext() {
    return this->next;
};

/**
 * This method sets the next item in the list.
 */
void SLL_Container::setNext(SLL_Container *newNext) {
    this->next = newNext;
};

int SLL_Container::compare(const void* item1, const void* item2) {
    SLL_Container *SLL_C1 = (SLL_Container *) item1;
    SLL_Container *SLL_C2 = (SLL_Container *) item2;
    return SLL_C1 - SLL_C2;
}

void SLL_Container::freeContainer() {
    this->freeContainer();
}

//============================
//Define methods for SLL Class
//============================

SLL::SLL() {
    this->head = NULL;
    this->itemNum = 0;
};

SLL::SLL(Item *head) {
    this->head = (SLL_Container *)head;
};

SLL_Container* SLL::castItem(Item *item) {
    SLL_Container *newItem = (SLL_Container *) item;
    if (newItem == NULL) {
        return NULL;
    }
    newItem->setPrintFunction(this->printFunction);
    return newItem;
};

void SLL::push(Item *item) {
    SLL_Container *newItem = this->castItem(item);
    newItem->next = this->base;
    this->base = newItem;
    this->itemNum++;
};

void SLL:append(Item *item) {
    SLL_Container *newItem = this->castItem(item);
    SLL_Container *curItem = this->head;
    if (curItem == NULL) {
        this->head = newItem;
        return;
    }
    while(curItem->next != NULL) {
        curItem = curItem->next;
    }
    curItem->next = newItem;
    this->itemNum++;
};

void SLL::insert(Item *item, unsigned int index) {
    SLL_Container *newItem = this->castItem(item);
    SLL_Container *tmpItem;

    //Check if index specified is even possible in this linked list
    if (index > this->itemNum) {
        return;
    } else if (index == 0) {
        //Check if we are just pushing to head;
        this->head = newItem;
        return;
    }

    unsigned int i = 0;
    SLL_Container *curItem = this->head;
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

void SLL::print() {
    SLL_Container *curContainer = this->head;
    while(curContainer != NULL) {
        curContainer.printItem();
        curContainer = curContainer->next;
    }
};

void SLL::registerPrintFunction(void (*printFunction)(void *)) {
    this->printFunction = printFunction;
};

Item* SLL::itemAt(unsigned int index) {
    if (index > this->itemNum) {
        return NULL;
    } else if (index == 0) {
        return this->head;
    }
    unsigned int i = 0;
    SLL_Container *curItem = this->head;
    while(i < index) {
        curItem = curItem->next;
    }
    return curItem;
};
