#include "SLL.h"

//Define Methods for SLL_Container class

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

//Define methods for SLL Class

SLL::SLL() {
    this->head = NULL;
    this->itemNum = 0;
};

SLL::SLL(Item *head) {
    this->head = (SLL_Container *)head;
};

void SLL::push(Item *item) {
    
}
