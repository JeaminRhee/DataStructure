#include "BST.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;



void BST::Add(char* key, char* value){
  
  
  node *ptr = NULL, *parent = NULL; 
  parent = Search(key); 
  if(parent==NULL&&root!=NULL)
    cout<<key<<" is already in the tree."<<endl;//값이 이미 있을 때 출력 문구
  
  if((parent!=NULL) || IsEmpty()) { // if num is not in the tree 
    ptr = new node; 
    
    if(ptr == NULL) { 
      fprintf(stderr,"The memory is full\n"); 
      exit(1); 
    } 
    
    strcpy(ptr->key,key); 
   // ptr->data = data
    strncpy(ptr->value,value,strlen(value));
    ptr->left_child = ptr->right_child = NULL; 
    if(IsEmpty()) 
      root = ptr; 
    else { // The tree is not empty 
      if(LessThan(key, parent->key)) 
      parent->left_child = ptr; 
      else parent->right_child = ptr; 
    }
  }
  
  
  
}



node* BST::Search(char* key){
  
  node *tree = root; 
  while (tree != NULL){ 
    if (!strcmp(tree->key, key)) return NULL; // key is present 
    else if (LessThan(key , tree->key)) 
      if (tree->left_child == NULL) return tree; 
      else tree = tree->left_child; 
    else                               // key > tree->data 
    if (tree->right_child == NULL) return tree; 
    else tree = tree->right_child; 
    
  } return NULL;

  
}//해당하는 값이 있으면 NULL리턴, 아니면 그 밑에 가야할 자리 리턴, 리턴값의 데이터 비교후 좌우 결정

node* BST::DSearch(char* key){
  
  node *tree = root; 
  int a = strlen(tree->key);
  while (tree != NULL){ 
    if (!strcmp(tree->key, key)) 
      return tree; // key is present
    else if(*(key+a)=='\n'){
      if (!strncmp(tree->key, key,a))
       return tree; 
        }
    else if (LessThan(key , tree->key)&&tree->left_child!=NULL) 
      tree = tree->left_child; 
    else if (GreaterThan(key, tree->key)&&tree->right_child!=NULL)
      tree=tree->right_child;
    else break;
  } return NULL;
  
}



void BST::Print(node* pos){
  
  if(pos->left_child!=NULL)
    Print(pos->left_child);
    
  cout<<pos->key<<": "<<pos->value<<endl;
  
  if(pos->right_child!=NULL)
    Print(pos->right_child);
}

void BST::Print(){
  Print(root);
}

bool BST::IsEmpty(){
  return(root==NULL);
}



bool BST::LessThan(char* a, char*b){
  
  while(a!=NULL&&b!=NULL){
    if(*a<*b)
      return true;
    else if(*a>*b)
      return false;
      
    a++; b++;
  }
  
  return false;
  }
  
bool BST::GreaterThan(char* a, char*b){
  
  while(a!=NULL&&b!=NULL){
    if(*a>*b)
      return true;
    else if(*a<*b)
      return false;
      
    a++; b++;
  }
  
  return false;
  }
  
