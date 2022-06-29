//John-Luke Speight
//COMPUTER NETWORKS - CS 4310 - 251
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
 
int main(int argc , char *argv[])
{
    int sock , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
     
    sock = socket(AF_INET , SOCK_STREAM , 0);

    puts("Socket created");
     
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8000 );
     
    if( bind(sock,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    listen(sock , 3);
     
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
     memset(client_message,'\0',sizeof(client_message));
    //Receive a message from client
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    {
        printf("Client message is \n\t%s\n",client_message);
        //Send the message back to client
        char send_msg[100]="is this";

        write(client_sock , client_message , strlen(client_message));
        memset(client_message,'\0',sizeof(client_message));


    }
     
    return 0;
}
