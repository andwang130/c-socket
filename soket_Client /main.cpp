#include <iostream>
#include "Client.h"
#include <string.h>
using namespace std;

int main() {
    char *ip="127.0.0.1";
    int port=8888;
    cout<<ip<<endl;
    char meg[1024];
    memset(meg,0,1024);
    cin>>meg;
    cout<<meg<<endl;
    CClient client(ip,port);
    client.client_init();
    client.client_send(meg);
    client.client_recv();
    cin>>meg;
    return 0;
}