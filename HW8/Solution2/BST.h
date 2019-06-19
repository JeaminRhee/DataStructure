#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;




typedef struct x{
  

  char mark;
  char a[30]; 
  char* key = a;
  char b[30];
  char* value = b;
  
  x* left_child;
  x* right_child;
  
  
}node;




class BST{
  
  private:
  
    node* root;
  
  public:
  
    BST(){
      
    };
    ~BST();
    
    void Add(char* key, char* value);
    node* Search(char* key);
    void Print();
    void Print(node* pos);
    void Quit();
    bool IsEmpty();
    node* DSearch(char* key);
    bool LessThan(char* a, char* b);
    bool GreaterThan(char* a, char* b);
  
  
  
  
  
  
  
  
  
  
  
  
};