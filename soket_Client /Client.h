//
// Created by meidai on 18-5-16.
//

#ifndef SOKET_CLIENT_CLIENT_H
#define SOKET_CLIENT_CLIENT_H

#endif //SOKET_CLIENT_CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
using namespace std;
class CClient
{
private:
    int client;//在linux下，socket是一个整型，在windes下是一个socket类型的
    struct sockaddr_in server; //要链接的server的地址结构体
public:
    CClient(char *ip,int port);
    void client_init();//socket初始化函数
    void client_Connect();//和服务端建立链接函数
    char * client_recv(); //接受函数
    void client_send(char * data);//发送函数


};