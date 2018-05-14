#include <iostream>
#include "serever.h"
using namespace std;
int main() {

    ip_info info;
    info.port=8000;
    Cserever cserever;
    cout<<cserever.run(info)<<endl;
    return 0;

}