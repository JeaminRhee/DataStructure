#include "BST.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



using namespace std;

void BST::Add(int num, char* data){
  
  
  node *ptr = NULL, *parent = NULL; 
  parent = Search(num); 
  if(parent==NULL&&root!=NULL)
    cout<<num<<" is already in the tree."<<endl;//값이 이미 있을 때 출력 문구
  
  if((parent!=NULL) || IsEmpty()) { // if num is not in the tree 
    ptr = new node; 
    
    if(ptr == NULL) { 
      fprintf(stderr,"The memory is full\n"); 
      exit(1); 
    } 
    
    ptr->key = num; 
   // ptr->data = data
    strncpy(ptr->data,data,strlen(data)-1);
    ptr->left_child = ptr->right_child = NULL; 
    if(IsEmpty()) 
      root = ptr; 
    else { // The tree is not empty 
      if(num < parent->key) 
      parent->left_child = ptr; 
      else parent->right_child = ptr; 
    }
  }
  
  
  
}

void BST::Delete(int key){
  
  
  node* parent=DSearch(key);
  
  node* ptr=NULL;
  int lr;
  node* t;
  
  if(parent!=NULL){
  if(parent->left_child!=NULL&&parent->left_child->key==key){
    ptr=parent->left_child;
    lr=0;
  }
  else if(parent->right_child!=NULL&&parent->right_child->key==key){
    ptr=parent->right_child;
    lr=1;
  }
  }
  
  
  if(DSearch(key)==NULL){//case when does not exist
    cout<<key<<" is not in the tree."<<endl;
    
  }
  else if(root->key==key){// case when key is in the root
    
    if(root->left_child==NULL&&root->right_child==NULL){//case of only one node
      delete root;
    }
    else if(root->left_child!=NULL&&root->right_child!=NULL){//case of two child node
      node* ptarget = root; 
      node* target=root->left_child;
      while(target->right_child!=NULL){
      ptarget=target;
      target=target->right_child;
      }
      if(target->left_child!=NULL){//case of target having a child, which is always left child
       if(target->key<ptarget->key)
          ptarget->left_child=target->left_child;
        else
          ptarget->right_child=target->left_child;
      } 
      
      t=root;
      target->left_child=root->left_child;
      target->right_child=root->right_child;
      root=target;
      delete t;
    }
  
    else if(root->left_child==NULL||root->right_child==NULL){//case of one child
      if(root->right_child==NULL){
        t=root->left_child;
        delete root;
        root=t;
      }      
      else{
        t=root->right_child;
        delete root;
        root=t;
      }
    }
  }//root case end
  else if(ptr->left_child!=NULL&&ptr->right_child!=NULL){//case of two child
    
    node* ptarget = ptr;
    node* target=ptr->left_child;
    while(target->right_child!=NULL){
      ptarget=target;
      target=target->right_child;
    }
    
    if(target->left_child!=NULL){//case of target having a child, which is always left child
      if(target->key<ptarget->key)
        ptarget->left_child=target->left_child;
      else
        ptarget->right_child=target->left_child;
    }
      
    if(lr){
      
      target->left_child=ptr->left_child;
      target->right_child=ptr->right_child;
      parent->right_child=target;
    }
    else{
      
      if(ptr->left_child!=target)target->left_child=ptr->left_child;
      target->right_child=ptr->right_child;
      parent->left_child=target;
    }
    
    delete ptr;
  } 
  else if(ptr->left_child==NULL&&ptr->right_child==NULL){//case of leaf node
    delete ptr;
    if(lr)
      parent->right_child=NULL;
    else
      parent->left_child=NULL;
    
  }  
  else if(ptr->left_child==NULL||ptr->right_child==NULL){//case of one child
    if(ptr->right_child==NULL){
      if(lr)
        parent->right_child=ptr->left_child;
      else
        parent->left_child=ptr->left_child;
      
    }
    else{
      if(lr)
        parent->right_child=ptr->right_child;
      else
        parent->left_child=ptr->right_child;
      
    }
    delete ptr;
    
    
  }//one child case end
  
  

  
}

node* BST::Search(int key){
  
  node *tree = root; 
  while (tree != NULL){ 
    if (tree->key == key) return NULL; // key is present 
    else if (key < tree->key) 
      if (tree->left_child == NULL) return tree; 
      else tree = tree->left_child; 
    else                               // key > tree->data 
    if (tree->right_child == NULL) return tree; 
    else tree = tree->right_child; 
    
  } return NULL;

  
}//해당하는 값이 있으면 NULL리턴, 아니면 그 밑에 가야할 자리 리턴, 리턴값의 데이터 비교후 좌우 결정

node* BST::DSearch(int key){
  
  node *tree = root; 
  while (tree != NULL){ 
    if (tree->key == key) 
      return tree; // key is present
    
    else if (key < tree->key&&tree->left_child!=NULL) 
      if (tree->left_child->key == key) return tree; 
      else tree = tree->left_child; 
    else if (key > tree->key&&tree->right_child!=NULL)
      if (tree->right_child->key == key) return tree; 
      else tree=tree->right_child;
    else break;
  } return NULL;
  
}



node* BST::SSearch(int key){
  
  node *tree = root;
    while(tree){ 
      if (key == tree->key) 
        return tree; 
      if (key < tree->key) 
        tree = tree->left_child; 
      else tree = tree->right_child; 
      
    } return NULL;

}
  
  
  
  



void BST::Print(node* pos){
  
  if(pos->left_child!=NULL)
    Print(pos->left_child);
    
  cout<<"("<<pos->key<<","<<pos->data<<")"<<endl;
  
  if(pos->right_child!=NULL)
    Print(pos->right_child);
}

void BST::Print(){
  Print(root);
}

bool BST::IsEmpty(){
  return(root==NULL);
}
