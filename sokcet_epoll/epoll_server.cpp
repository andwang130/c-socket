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
void server::server_ctl(void)
{
    listen(server_sokcet,8);

    struct epoll_event event;
    event.data.fd=server_sokcet; //监听的socket
    event.events=EPOLLIN;  //监听的事件，监听读事件
    epoll_ctl(epoll_fd,EPOLLIN,server_sokcet,&event); //监听serevr的sokcet的读事件,如果可读，表示有新的链接
    std::cout << strerror(errno) << std::endl; //打印一下错误信息

}
void server::epoll_while(void)
{
    while(true)
    {   struct epoll_event event;
        epoll_wait(epoll_fd,&event,1,0);
        if(event.data.fd==server_sokcet) //发生改变的是serev
        {
            if(event.events==EPOLLIN)
            {
                server_accept();       //srever的可读事件，有新的连接，调用建立链接的函数
            }
        }
        else
        {
            if(event.events==EPOLLIN)
            {
                clien_recv(event.data.fd);  //客户端的SOCKET可读了，转到读取函数
            }

        }
    }
}
void server::server_accept(void)
{
    cout<<"和客户端建立链接"<<endl;
    struct sockaddr_in cilen_in;
    socklen_t lent= sizeof(cilen_in);
    int coon=accept(server_sokcet,(struct sockaddr *)&cilen_in,&lent);
    struct epoll_event event;
    event.data.fd=coon;
    event.events=EPOLLIN;
    epoll_ctl(epoll_fd,EPOLLIN,coon,&event);
}
void server::clien_recv(int coon)
{
    cout<<"客户端发来消息"<<endl;
    char req[1024];
    memset(req,0,1024);
    recv(coon,req, sizeof(req),0);
    cout<<coon<<"说"<<req<<endl;
    char *retu="服务器回复";
    send(coon,retu,strlen(retu),0);
}

void server::run()
{
    socket_init();
    socket_bin();
    server_ctl();
    epoll_while();

}