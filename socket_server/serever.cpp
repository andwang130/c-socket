//
// Created by wj on 18-5-14.
//
#include "serever.h"
#include <iostream>
#include <arpa/inet.h>
#include <thread>
#include <string.h>
using namespace std;

void sereve_recv(int *sockt)
{
    cout<<*sockt<<endl;

    char req[1024];
    while (true) {

        int ret=recv(*sockt,req,1024,0);
        std::cout<<req<<std::endl;
        if(ret<=0)
        {
            break;
        }
    }
}
void Cserever::run() {
    //scoket整个流程
    socket_init();
    socket_bin();
    socket_listen(20);
    socket_acceap(sereve_recv);
}

void Cserever::socket_init()
{
    serevr_skcoket=socket(AF_INET,SOCK_STREAM,0);//初始化socket

}

void Cserever::socket_bin()
{
    //绑定socket的地址，返回-1表示失败
   if(bind(serevr_skcoket,(struct sockaddr * )&server_in, sizeof(server_in))==-1)
   {
       throw "bind fail";
   }
}
void Cserever::socket_listen(int num)
{
    //设置最大链接数
    listen(serevr_skcoket,num);
}
void Cserever::socket_acceap(void(*Callback)(int *clicen))//需要传入一个函数指针来做回调函数，
{

    //监听函数，返回和客户端建立链接的cocket,需要传入一个服务器的socket,还有一个地址结构体，来结束客户端的地址结构，第3
    //个参数是结构体的长度，必须的soklen_t类型的
    socklen_t lent= sizeof(client_in);
    int coon=accept(serevr_skcoket,(struct sockaddr*) &client_in,&lent);
    while (true) {
        int coon = accept(serevr_skcoket, (struct sockaddr *) &client_in, &lent);//开始监听，返回连接的socket,链接方的信息保存在client_in当中
        std::cout << strerror(errno) << std::endl; //打印一下错误信息
        thread t(Callback,&coon);
        t.detach();
    }
}
Cserever::Cserever(char *ip,int port)  //构造函数，里面初始化地址结构体
{
    server_in.sin_family=AF_INET;
    server_in.sin_addr.s_addr=inet_addr(ip);
    server_in.sin_port=htons(port);

}

