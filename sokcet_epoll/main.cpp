#include <iostream>
#include "epoll_sereve.h"
int main() {
    std::cout << "启动" << std::endl;
    server ser("127.0.0.1",8888);
    ser.run();
    return 0;
}