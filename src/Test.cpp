#include "Test.h"
#include <iostream>

int main() {
    SLL<int> *test_list = new SLL<int>();
    unsigned int i;
    for (i = 0; i < 20; i++) {
        test_list->push(new int(i));
        test_list->append(new int(1));
        test_list->insert(new int(-1), i);
        test_list->print();
        std::cout << "================\n";
    }
    delete test_list;
    return 0;
};
