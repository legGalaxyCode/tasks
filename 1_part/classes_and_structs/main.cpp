#include "classes.hpp"

void check_memory_leak_from_destructor() {
    LinkedList list;
    return;
}

int main() {
    std::cout << "Classes and structs\n";
    check_memory_leak_from_destructor();
}