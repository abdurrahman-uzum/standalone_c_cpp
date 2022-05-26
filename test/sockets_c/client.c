#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

#include<netinet/in.h>


int main( int argc, char** argv )
{
	// Create a socket
    int mysocket = socket( AF_INET, SOCK_STREAM, 0 );

	// Set address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port   = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	if ( connect( mysocket, (struct sockaddr*) &server_address, sizeof(server_address) ) != 0 )
	{
		fprintf( stderr, "Failed to connect\n" );
		return -1;
	}

	char recv_buffer[256] = { 0 };
	char send_buffer[256] = { 0 };
	int count = 0;


	for(count=0; count < INT_MAX; count++ )
	{
		memset( recv_buffer, 0, sizeof(recv_buffer) );
		memset( send_buffer, 0, sizeof(send_buffer) );


		recv( mysocket, recv_buffer, sizeof(recv_buffer), 0 );

		sprintf( send_buffer, "Client count:%d", count );
		send( mysocket, send_buffer, sizeof(send_buffer), 0 );

		printf( ">>Received: <%s> | Sending: <%s>\n", recv_buffer, send_buffer );

	}


	close( mysocket );







    return 0;
}