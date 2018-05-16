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
char * Cserever::run(ip_info &info) {
    server_in.sin_family = AF_INET;//选择IPV4，如果选择IPV6  填AF_INET6
   // server_in.sin_addr.s_addr = htonl(INADDR_ANY); //绑定IP地址,INADDR_ANY是0.0.0.0标识监听本地所有IP段

    // htonl() 将无符号类型转换成网络字节顺序
    server_in.sin_addr.s_addr=inet_addr("127.0.0.1");//将字符串类型的IP转换成长整型;

    server_in.sin_port = htons(8000);//绑定端口号; htons和htonl是一样的
    serevr_skcoket = socket(AF_INET, SOCK_STREAM, 0);//获取一个一个tcp链接的socket
    if (bind(serevr_skcoket, (struct sockaddr *) &server_in, sizeof(server_in))==-1)
    {   std::cout<<strerror(errno)  <<std::endl;  //打印一下错误信息
        return "socket绑定失败";

    }
    int req=listen(serevr_skcoket,20);//绑定socket,如果返回的是-1表示失败了
   if(req==-1) //失败返回-1
    {
        std::cout<<req<<std::endl;
        return "listen失败le";

    }
    socklen_t lent= sizeof(client_in);//获取到client_in的长度，保存到socklen_t中，accept的第3个参数需要soklen_t类型
    while (true) {
        int coon = accept(serevr_skcoket, (struct sockaddr *) &client_in, &lent);//开始监听，返回连接的socket,链接方的信息保存在client_in当中
        std::cout << strerror(errno) << std::endl; //打印一下错误信息
        thread t(sereve_recv,&coon);
        t.detach();
    }

    return "结束";
}

