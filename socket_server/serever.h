//
// Created by meidai on 18-5-14.
//

#ifndef MY_SOCKET_SEREVER_H
#define MY_SOCKET_SEREVER_H

#endif //MY_SOCKET_SEREVER_H

#include<sys/socket.h>
#include <netinet/in.h>
struct ip_info
{
    int port;


};
class Cserever
{
private:
    struct sockaddr_in server_in;//绑定地址结构体
    int serevr_skcoket;
    struct  sockaddr_in client_in;
public:
    char * run(ip_info &info);

};

