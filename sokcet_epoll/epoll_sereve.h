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
   void socket_bin(void); //server绑定
   void server_ctl(void); //将server添加到epoll的事件当中
    void epoll_while(void); //epoll事件循环
    void server_accept(void);//客户端建立链接
    void clien_recv(int coon);
public:
    server(char * ip,int port);
    void run();
};