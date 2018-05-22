#include <iostream>
#include "serever.h"
using namespace std;

int main() {

    ip_info info;
    info.port=8000;
    Cserever cserever("0.0.0.0",8080);
    cserever.run();
    return 0;

}