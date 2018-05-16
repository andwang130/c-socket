//
// Created by meidai on 18-5-16.
//
#include "Client.h"
#include <arpa/inet.h>
#include <string.h>
void CClient::client_init()
{
    client=socket(AF_INET,SOCK_STREAM,0);//TC链接
    cout<<connect(client,(struct sockaddr *)&server, sizeof(server))<<endl;

}
CClient::CClient(char *ip,int port)
{
    //初始化sereve地址结构体
    //
    server.sin_port=htons(port); //端口
    server.sin_addr.s_addr=inet_addr(ip);//ip
    server.sin_family=AF_INET;

}
void CClient::client_send(char * data)
{
    send(client,&data,strlen(data),0);//send函数需要4个参数，第一个socket,第二个发送的数据，是char *类型的，第3个数据长度，第4个一般为0
    std::cout<<strerror(errno)<<std::endl;  //打印一下错误信息
}