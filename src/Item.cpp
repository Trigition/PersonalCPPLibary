#include "Commons.h"
#include "Item.h"

Item::Item(void *container) {
    this->setContainer(container);
}

void* Item::getContainer() {
    return this->container;
}

void Item::setContainer(void *container) {
    this->container = container;
}
