#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "BST.h"
using namespace std;

void BST::ReadFile(string filename){
	ifstream ifp;
	ifp.open(filename,ios::in);
	while(1){
		getline(ifp,line);
		char *token=strtok(&line[0]," ");
		Implement(token);
	}
	ifp.close();
}

void BST::Implement(char *token){
	if(*token=='a'){
		int key,cnt=0;
		string value;
		while(token){
			if(cnt==1) key=atoi(token);
			else if(cnt==2) value=token;
			cnt++;
			token=strtok(NULL," ");
		}
		insert_node(key,value);
	}
	else if(*token=='d'){
		int key,cnt=0;
		while(token){
			if(cnt==1) key=atoi(token);
			cnt++;
			token=strtok(NULL," ");
		}
		delete_node(key);
	}
	else if(*token=='p'){
		Print();
	}
	else if(*token=='q') exit(0);
}

void BST::insert_node(int key, string value){
	if(my_map.find(key) != my_map.end()) cout<<key<<" is already in the tree."<<endl;
	else my_map.insert(make_pair(key,value));
}

void BST::delete_node(int key){
	if(my_map.find(key) == my_map.end()) cout<<key<<" is not in the tree."<<endl;
	else my_map.erase(key);
}

void BST::Print(){
	map<int,string>::iterator it;
	for(it=my_map.begin();it!=my_map.end();it++)
		cout<<"("<<it->first<<", "<<it->second<<")"<<endl;
}