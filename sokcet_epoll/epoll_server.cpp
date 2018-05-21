//
// Created by meidai on 18-5-21.
//

#include "epoll_sereve.h"
#include <string.h>


server::server(char * ip,int port)
{
    server_in.sin_port=htons(port);
    server_in.sin_family=AF_INET;
    server_in.sin_addr.s_addr=inet_addr(ip);
}
void server::socket_init(void)
{
    epoll_fd=epoll_create(1);//创建一个epoll描述符
    server_sokcet=socket(AF_INET,SOCK_STREAM,0);
}
void server::socket_bin(void)
{
    bind(server_sokcet,(struct sockaddr *)&server_in, sizeof(server_in));
}
void server::socket_acpet(void)
{
    listen(server_sokcet,8);
    struct sockaddr_in cilen_in;
    struct epoll_event event;
    event.data.fd=server_sokcet; //监听的socket
    event.events=EPOLLIN;  //监听的事件，监听读事件
    epoll_ctl(epoll_fd,EPOLLET,server_sokcet,&event);
    while (1)
    {

    }
    std::cout << strerror(errno) << std::endl; //打印一下错误信息

}
void server::run()
{
    socket_init();
    socket_bin();
    socket_acpet();

}