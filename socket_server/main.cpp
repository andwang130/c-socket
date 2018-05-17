#include <iostream>
#include "serever.h"
using namespace std;

int main() {

    ip_info info;
    info.port=8000;
    Cserever cserever("127.0.0.1",8000);
    cserever.run();
    return 0;

}