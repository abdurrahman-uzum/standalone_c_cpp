#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

#include<netinet/in.h>


int main ( int argc, char** argv )
{
    char recv_buffer[256] = { 0 };
    char send_buffer[256] = { 0 };

    strcpy( recv_buffer, "This is a message." );

    int server_sock = socket( AF_INET, SOCK_STREAM, 0 );

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons( 9002 );
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind( server_sock, (struct sockaddr*) &server_address, sizeof(server_address) );

    listen( server_sock, 1 );

    int client_sock = accept( server_sock, NULL, NULL );

    for(;;)
    {
        memset( recv_buffer, 0, sizeof(recv_buffer) );
        //memset( send_buffer, 0, sizeof(send_buffer) );

        send( client_sock, send_buffer, sizeof(send_buffer), 0 );
        recv( client_sock, recv_buffer, sizeof(recv_buffer), 0 );

		printf( ">>Received: <%s> | Sending: <%s>\n", recv_buffer, send_buffer );
    }


    close( server_sock );






    return 0;
}