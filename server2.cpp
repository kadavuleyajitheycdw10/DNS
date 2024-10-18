#include<iostream>
#include<bits/stdc++.h>
#include <arpa/inet.h> // inet_addr()                                                                                                                                   
#include <netdb.h>                                                                                                                                                      
#include <stdio.h>                                                                                                                                                      
#include <stdlib.h>                                                                                                                                                     
#include <string.h>                                                                                                                                                     
#include <strings.h> // bzero()                                                                                                                                         
#include <sys/socket.h>                                                                                                                                                 
#include <unistd.h>                                                                                                                   
#define MAX 10000                 
#define PORT 53542                                                                                                                                                  
#define SA struct sockaddr                                                                                                                                              
using namespace std;
void func(int sockfd)                                                                                                                                                   
{                                                                                                                                                                       
        char buff[MAX];                                                                                                                                                 
        int n;                                                                                                                                                          
        for (;;) {                                                                                                                                                      
                bzero(buff, sizeof(buff));                                                                                                                              
                read(sockfd, buff, sizeof(buff));                                                                                                                       
                cout<<"From Server : "<< buff;       
		
	unordered_map<string, string>auth1,auth2,auth3;                                                                                                                 
        vector<pair<string,unordered_map<string,string> >> root;                                                                                                        
        auth1["www.google.com"]="192.168.1.200";
        auth1["www.wikipedia.com"]="192.168.1.201";
        auth1["www.github.com"]="192.168.1.202";
        root.push_back({"com",auth1});
        auth2["www.google.in"]="192.168.1.300";
        auth2["www.wikipedia.in"]="192.168.1.301";
        auth2["www.github.in"]="192.168.1.302";
        root.push_back({"in",auth2});
        auth3["www.annauniv.edu"]="192.168.1.400";
        auth3["www.wikipedia.edu"]="192.168.1.401";
        auth3["www.github.edu"]="192.168.1.402";
        root.push_back({"edu",auth3});
                
	char IP[MAX];
	string idstr="",ip="";
	int flag=0,j;
	for(int i=0;buff[i]!='\0';i++){
		if(buff[i]==','){j=i;break;}
		idstr+=buff[i];
	}
	for(int i=j+1;buff[i]!='\0';j++){
		ip+=buff[i];
	}
	int id=stoi(idstr);
        for(auto const p:root[id].second){
                if(p.first==ip){
                        cout<<p.second<<endl;                                                                                                                           
                        int k=0;
                        for(char c:p.second){
                                IP[k]=c;                                                                                                                                
                                k++;                                                                                                                                    
                        }
                        flag=1;
                }
        }
        if(flag==0){
                cout<<"No IP found!"<<endl;
        
	}
	break;
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
                                                                                                                                                                        
        
	close(sockfd);
}
