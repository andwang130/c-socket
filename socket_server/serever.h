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
    void socket_init();
    void socket_bin();
    void socket_listen(int num);//设置最大连接数
    void socket_acceap(void(*Callback)(int *clicen));//开启监听

public:
    void run();
    Cserever(char *ip,int port);

};

