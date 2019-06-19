#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "BST.h"
using namespace std;

BST::BST(){
	root=NULL;
}

BST::~BST(){
	delete_all(root);
	root=NULL;
}

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
		Print(root);
	}
	else if(*token=='q') exit(0);
}

void BST::insert_node(int key, string value){
	tree_node *ptr=NULL, *parent=NULL;
	parent=insert_search(key); //같은 key를 가진 node가 있는지 check
	//key가 tree에 없는 경우
	if((parent!=NULL)|| IsEmpty()){
		ptr=new tree_node;

		if(ptr==NULL){
			cout<<"The memory is full\n";
			exit(1);
		}
		ptr->data.key=key;
		ptr->data.value=value;
		ptr->left_child=ptr->right_child=NULL;

		if(IsEmpty())
			root=ptr;
		else{
			if(key<parent->data.key) parent->left_child=ptr;
			else parent->right_child=ptr;
		}
	}
	else cout<<key<<" is already in the tree."<<endl;
}

void BST::delete_node(int key){
	tree_node *parent=NULL;
	tree_node *cur=NULL;
	bool verify; //1이면 left, 0이면 right
	parent=delete_search(key);//찾고자 하는 노드의 부모
	if(parent==NULL) cout<<key<<" is not in the tree."<<endl;
	//찾고자 하는 key존재->node 삭제
	//delete 대상이 root인 경우
	else if(parent->data.key==key){
		tree_node *link=NULL;
		cur=parent->left_child;
		if(cur->right_child!=NULL){ //부모의 왼쪽 노드의 오른쪽 자식이 있다면
			while(cur->right_child!=NULL)	{
				link=cur;
				cur=cur->right_child;
			}
			parent->data.key=cur->data.key;
			parent->data.value=cur->data.value;
			delete cur;
			link->right_child=NULL;
		}
		else{ //부모의 왼쪽 노드의 오른쪽 자식이 없으면 왼쪽 노드 당첨(left subtree에서 가장 큰 값)
			parent->data.key=cur->data.key;
			parent->data.value=cur->data.value;
			//linked list delete와 유사
			link=cur->left_child;
			delete cur;
			parent->left_child=link;
		}
	}
	else if(parent!=NULL){
		//찾고자 하는 node가 부모로부터 왼쪽or오른쪽 중 어디있는지 판별
		if(parent->left_child && parent->left_child->data.key==key){cur=parent->left_child; verify=1;}
		else if(parent->right_child &&parent->right_child->data.key==key){cur=parent->right_child; verify=0;}
		//leaf node인 경우
		if(cur->left_child==NULL && cur->right_child==NULL){
			if(verify==1){//찾고자 하는 node가 부모의 왼쪽 자식인 경우
				delete cur;
				parent->left_child=NULL;
			}
			else if(verify==0){//찾고자 하는 node가 부모의 오른쪽 자식인 경우
				delete cur;
				parent->right_child=NULL;
			}
		}
		//non-leaf with two children인 경우
		else if(cur->left_child!=NULL && cur->right_child!=NULL){
			tree_node *del_ptr=cur->left_child, *prev=cur;
			//왼쪽 subtree에서 가장 큰 값을 찾아주기(delete와 값을 바꾸기 위함)
			while(del_ptr->right_child!=NULL){
				prev=del_ptr;
				del_ptr=del_ptr->right_child;
			}
			cur->data.key=del_ptr->data.key;
			cur->data.value=del_ptr->data.value;
			//node 삭제 +삭제당한 노드의 부모의 left or right pointer NULL해주기
			if(prev->left_child->data.key==del_ptr->data.key) prev->left_child=NULL;
			else prev->right_child=NULL;
			delete del_ptr;
		}
		//non-leaf with one child인 경우
		else if(cur->left_child!=NULL || cur->right_child!=NULL){
			if(verify==1){//찾는 노드가 parent의 왼쪽 자식일 때
				if(cur->left_child!=NULL) parent->left_child=cur->left_child;
				else if(cur->right_child!=NULL) parent->left_child=cur->right_child;
				delete cur;
			}
			else if(verify==0){//찾는 노드가 parent의 오른쪽 자식일 때
				if(cur->left_child!=NULL) parent->right_child=cur->left_child;
				else if(cur->right_child!=NULL) parent->right_child=cur->right_child;
				delete cur;
			}
		}
	}
}

tree_node *BST::insert_search(int key){
	tree_node *tree=root;
	while(tree!=NULL){
		if(tree->data.key==key) return NULL;
		else if(key<tree->data.key){
			if(tree->left_child==NULL) return tree;
			else tree=tree->left_child;
		}
		else{
			if(tree->right_child==NULL) return tree;
			else tree=tree->right_child;
		}
	}
	return NULL;
}

tree_node *BST::delete_search(int key){
	tree_node *tree=root, *parent=NULL;
	if(root->data.key==key) return root;

	while(tree){
		if(key==tree->data.key)	return parent;

		else if(key<tree->data.key){
			parent=tree;
			tree=tree->left_child;
		}
		else if(key>tree->data.key){
			parent=tree;
			tree=tree->right_child;
		}
	}
	return NULL;
}

void BST::delete_all(tree_node *ptr){
	if(ptr){
		delete_all(ptr->left_child);
		delete_all(ptr->right_child);
		delete ptr;
	}
}

bool BST::IsEmpty(){
	if(root==NULL) return 1;
	else return 0;
}

void BST::Print(tree_node *ptr){
	if(ptr){
		Print(ptr->left_child);
		cout<<"("<<ptr->data.key<<","<<ptr->data.value<<")"<<endl;
		Print(ptr->right_child);
	}
}