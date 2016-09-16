#include "Commons.h"
#include "Item.h"

Item::Item() {
    this->setContainer(NULL);
}

Item::Item(void *container) {
    this->setContainer(container);
}

void Item::setPrintFunction(void (*print)(void *)) {
    this->print = print;
}

void Item::printItem() {
    if (print == NULL) {
        return;
    }
    this->print(this->getContainer());
}

void* Item::getContainer() {
    return this->container;
}

void Item::setContainer(void *container) {
    this->container = container;
}
