#include<bits/stdc++.h>
#include <arpa/inet.h> // inet_addr()                                                                                                                                   
#include <netdb.h>                                                                                                                                                      
#include <stdio.h>                                                                                                                                                      
#include <stdlib.h>                                                                                                                                                     
#include <string.h>                                                                                                                                                     
#include <strings.h> // bzero()                                                                                                                                         
#include <sys/socket.h>                                                                                                                                                 
#include <unistd.h> // read(), write(), close()                                                                                                                         
using namespace std;
#define MAX 10000                                                                                                                                                       
#define PORT 53541                                                                                                                                   
#define SA struct sockaddr                                                                                                                                              
void func(int sockfd)                                                                                                                                                   
{                                                                                                                                                                       
        char buff[MAX];                                                                                                                                                 
        int n;                                                                                                                                                          
        for (;;) {                                                                                                                                                      
                bzero(buff, sizeof(buff));                                                                                                                              
                printf("Enter the string : ");                                                                                                                          
                n = 0;                                                                                                                                                  
                while ((buff[n++] = getchar()) != '\n')                                                                                                                 
                        ;                                                                                                                                               
                write(sockfd, buff, sizeof(buff));                                                                                                                      
                bzero(buff, sizeof(buff));                                                                                                                              
                read(sockfd, buff, sizeof(buff));                                                                                                                       
                cout<<"From Server : "<< buff;                                                                                                                       
        }                                                                                                                                                               
}                                                                                                                                                                       
                                                                                                                                                                        
int main()                                                                                                                                                              
{                                                                                                                                                                       
        int sockfd, connfd;                                                                                                                                             
        struct sockaddr_in servaddr, cli;                                                                                                                               
                                                                                                                                                                        
        // socket create and verification                                                                                                                               
        sockfd = socket(AF_INET, SOCK_STREAM, 0);                                                                                                                       
        if (sockfd == -1) {                                                                                                                                             
                cout<<"socket creation failed...\n";                                                                                                                  
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        else                                                                                                                                                            
                cout<<"Socket successfully created..\n";                                                                                                              
        bzero(&servaddr, sizeof(servaddr));                                                                                                                             
                                                                                                                                                                        
        // assign IP, PORT                                                                                                                                              
        servaddr.sin_family = AF_INET;                                                                                                                                  
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");                                                                                                              
        servaddr.sin_port = htons(PORT);                                                                                                                                
                                                                                                                                                                        
        // connect the client socket to server socket                                                                                                                   
        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))                                                                                                           
                != 0) {                                                                                                                                                 
                cout<<"connection with the server failed...\n";                                                                                                       
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        else                                                                                                                                                            
                cout<<"connected to the server..\n";      
	func(sockfd);                                                                                                                                                   

                                                                                                                                                                        

        
	close(sockfd);                                                                                                                                       }
