#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"

using namespace std;



int main() {
  
  string input;//string for filename
  char a[40];
  char* read = a;//string to read lines from file
  char r[1024];
  char* line = r;
  FILE* fp1;
  FILE* fp2;//file pointers
  
  char b[30];
  char* key = b;// string for words to be changed
  char c[30];
  char* value = c;//string for words to change into
  
  cin>>read;
  fp1 = fopen(read,"r");
  cin>>read;
  fp2 = fopen(read,"r");
  
  BST* tree= new BST;//allocating new BST;
  
 
 
  while(fgets(read,39,fp2)!=NULL){// reading map file to form a BST
  
    key = strtok(read,": ");
    value = strtok(NULL,": \n");
    
    tree->Add(key,value);
    
  }
 
 
  
 //so far so good
 
 
 node* nt;
 char z[30];
 char * target=z;
 char*x;
 int flag;
 
 while(fgets(line,1023,fp1)!=NULL){// reading example file to make an array of word tokens
    
    
    flag=1;//indicating if this line has the change line symbol at the end
    if(*(line+strlen(line)-1)=='\n')
      *(line+strlen(line)-1)='\0';//removing the change line symbol
    else
      flag=0;
      
    
    x=strtok(line," ");
    strcpy(target,x);//tokenixing the line with white space
    nt = tree->DSearch(target);//search in BST
    if(nt){//if there is a match
      strcpy(target,nt->value);//apply changes
    }
    cout<<target;//print
    
    while ((x=strtok(NULL," "))){//previous lines were for the first word. now repeat
      strcpy(target,x);
      
      nt = tree->DSearch(target);
      if(nt){
        strcpy(target,nt->value);
      }
      cout<<" "<<target;
     
    }
    if(flag)//if it is not the last line
      cout<<endl;
  }
  
  return 0;
  
}