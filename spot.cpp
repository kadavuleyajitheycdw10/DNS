#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#define MAX 80 
#define PORT 53541
#define SA struct sockaddr
char buff[MAX];
char IP[MAX];
void dns();
void tldParser(int connfd, int id);
void func(int connfd)                                                                                                                                                   
{                                                                                                                                                                       
        int n;                                                                                                                                                          
        for (;;) {                                                                                                                                                      
                bzero(buff, MAX);                                                                                                                                       
                                                                                                                                                                        
                read(connfd, buff, sizeof(buff));                                                                                                                       
                cout<<"From client: %s\t To client : "<< buff;                                                                                                         
                dns();
		write(connfd, IP, sizeof(IP));
		bzero(buff,MAX);
		                                                                                                                                                       
        }                                                                                                                                                               
}
int main(){
	int sockfd, connfd, len;                                                                                                                                        
        struct sockaddr_in servaddr, cli;                                                                                                                               
        sockfd = socket(AF_INET, SOCK_STREAM, 0);                                                                                                                       
        if (sockfd == -1) {                                                                                                                                             
                cout<<"socket creation failed...\n";                                                                                                                  
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        else                                                                                                                                                            
                cout<<"Socket successfully created..\n";                                                                                                              
        bzero(&servaddr, sizeof(servaddr));                                                                                                                             
        servaddr.sin_family = AF_INET;                                                                                                                                  
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);                                                                                                                   
        servaddr.sin_port = htons(PORT);                                                                                                                                
                                                                                                                                                                        
        if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {                                                                                                    
                cout<<"socket bind failed...\n";                                                                                                                      
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        else                                                                                                                                                            
                cout<<"Socket successfully binded..\n";                                                                                                               
                                                                                                                                                                        
        if ((listen(sockfd, 5)) != 0) {                                                                                                                                 
                cout<<"Listen failed...\n";                                                                                                                           
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        else                                                                                                                                                            
                cout<<"Server listening..\n";                                                                                                                         
        len = sizeof(cli);                                                                                                                                              
                                                                                                                                                                        
        connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);                                                                                                                   if (connfd < 0) {                                                                                                                                               
                cout<<"server accept failed...\n";                                                                                                                    
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        else                                                                                                                                                            
                cout<<"server accept the client...\n";                                                                                                                
                                                                                                                                                                       
        func(connfd);                                                                                                                                                           close(sockfd);	
}
void dns(){
	/*int sockfd, connfd, len;
        struct sockaddr_in servaddr, cli;
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
                cout<<"socket creation failed...\n";
                exit(0);
        }
        else
                cout<<"Socket successfully created..\n";
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;                                                                                                                                  
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);                                                                                                                   
        servaddr.sin_port = htons(54342);                                                                                                                                
                                                                                                                                                                        
        if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
                cout<<"socket bind failed...\n";
                exit(0);
        }                                                                                                                                                               
        else
                cout<<"Socket successfully binded..\n";
                                                                                                                                                                        
        if ((listen(sockfd, 5)) != 0) {
                cout<<"Listen failed...\n";
                exit(0);
        }                                                                                                                                                               
        else
                cout<<"Server listening..\n";
        len = sizeof(cli);
                                                                                                                                                                        
        connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);                                                                                                           
        if (connfd < 0) {
                cout<<"server accept failed...\n";
                exit(0);
        }                                                                                                                                                               
        else
                cout<<"server accept the client...\n";
          */                                                                                                                                                              
	unordered_map<string, string> localdns;
	if(localdns.size()>0){
		string ip="";
		for(int i=0;i<strlen(buff);i++){
			ip+=buff[i];
		}
		
		if(localdns.count(ip)){
			string a=localdns[ip];
			int i=0;
			for(char c:a){
				IP[i]=c;
				i++;
			}
		}
	}
	else if(localdns.size()<=0){
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
	for(auto const p: root){
		cout<<p.first<<"  ";
		for(auto const m:p.second){
			cout<<m.first<<"-"<<m.second<<" , ";
		}
		cout<<endl;
	}
	string ip="", domain="";
	for(int i=0;buff[i]!='\0';i++){
		if(buff[i]!=' ')
			ip += buff[i];
		cout<<buff[i]<<" ";
	}
	int l=ip.size();
	ip[l-1]='\0';
	string ip2="";
	for(int i=0;i<l-1;i++)
		ip2+=ip[i];
	for(int i=l-2;i>=0;i--){
		if(ip[i]=='.')
			break;
		domain= ip[i] + domain;
	}
	cout<<l<<" "<<ip<<" "<<domain<<endl;
	int id;	
	if(domain=="com"){
		id=0;
	}
	else if(domain=="in"){
		id=1;
	}
	else if(domain=="edu"){
		id=2;
	}
	else{
		cout<<"No domain found!!"<<endl;
		return ;
	}
	cout<<"TLD = "<<id<<endl;
	//tldParser(connfd, id);
	int flag=0;
	for(auto const p:root[id].second){
		if(p.first==ip2){
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
	localdns[ip2]=IP;
	}
}

void tldParser(int connfd, int id){
	string str=to_string(id);
	char str2[MAX];
	int i=0;
	for(char c:str){
		str2[i]+=c;
		i++;
	}
	str2[i]=',';
	i++;
	for(char c:buff){
		str2[i]+=c;
		i++;
	}
	write(connfd, str2, sizeof(str2));
}
