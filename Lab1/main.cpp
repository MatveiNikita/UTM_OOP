#include "collection/LinkedList.h"

int main() {

    LinkedList list;
    list.push_front(1); 
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.push_front(6);
    list.pop_back();
    list.print();
    std::cout << list.size() << std::endl;
    std::cout << list.isEmpty();
    return 0;
}
