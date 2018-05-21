#include <iostream>
#include "epoll_sereve.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    server ser("127.0.0.1",8080);
    ser.run();
    return 0;
}