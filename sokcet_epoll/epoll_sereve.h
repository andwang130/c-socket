//
// Created by meidai on 18-5-21.
//

#ifndef SOKCET_EPOLL_EPOOL_SEREVER_H
#define SOKCET_EPOLL_EPOOL_SEREVER_H

#endif //SOKCET_EPOLL_EPOOL_SEREVER_H

#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
class server
{
private:
    int server_sokcet;
    int epoll_fd;
    struct sockaddr_in server_in;
   void socket_init(void);
   void socket_bin(void);
   void socket_acpet(void);
public:
    server(char * ip,int port);
    void run();
};