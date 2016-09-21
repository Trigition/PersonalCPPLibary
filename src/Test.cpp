#include "Test.h"

int main() {
    SLL<int> *test_list = new SLL<int>();
    unsigned int i;
    for (i = 0; i < 200000; i++) {
        test_list->push(new int(i));
    }
    //test_list->push(new int(10));
    //test_list->push(new int(20));
    //test_list->append(new int(1000));
    //test_list->print();
    delete test_list;
    return 0;
};
