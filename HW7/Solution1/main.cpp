#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

using namespace std;



int main() {
  
  char yes[30];
  char* read=yes;
  char op;
  int key;
  char* value;
  
  cin>>read;
  FILE *fp = fopen(read, "r");
  //FILE *fp = fopen("example3.txt", "r");
  
  BST* tree= new BST;
  

  while(fgets(read,29,fp)!=NULL){
  
  op=*read;
  read+=2;
  
  switch (op){
    case 'a':
      key = atoi(strtok(read," "));
      value = strtok(NULL," ");
   
      tree->Add(key,value);
    
      
      break;
      
    case 'd':
      key = atoi(strtok(read," "));
      //cout<<(tree->DSearch(key)->key);
      tree->Delete(key);
      
      break;
      
    case 'p' :
      tree->Print();
      break;
  }
  
  if(op=='q')
  break;
  
  
    
  
    
    
    
    
  read=yes;
  key=0;
  while(key<=30){
  yes[key]='\0';
  key++;
  
  }
  }
  
  
  
  
}