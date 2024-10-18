#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_map<string, string> localdns;
	unordered_map<string, string>auth1,auth2,auth3;
	//vector<pair<string, string>> p;
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

	string ip, domain="";
	cin>>ip;
	int len=ip.size();
	for(int i=len-1;i>=0;i--){
		if(ip[i]=='.')
			break;
		domain= ip[i] + domain;
	}
	cout<<domain<<endl;
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
		cout<<"No domain fount!!"<<endl;
		return 0;
	}

	cout<<"TLD = "<<id<<endl;
	int flag=0;
	for(auto const p:root[id].second){
		if(p.first==ip){
			cout<<p.second<<endl;
			flag=1;
		}
	}
	if(flag==0){
		cout<<"No IP found!"<<endl;
	}

	return 0;
}
