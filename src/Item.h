#ifndef _ITEM_H_
#define _ITEM_H_

#include <cstddef>
/*
 * This class is for containing any kind of data within itself.
 * This class is then used for basic units in a lot of data structures.
 */
class Item {
    private:
        void *container;
    public:
        Item ();
        Item (void *container);
        void *getContainer();
        void setContainer(void *Container);
        virtual int compare(const void* item1, const void *item2) = 0;
        virtual void freeContainer() = 0;
};

#endif
