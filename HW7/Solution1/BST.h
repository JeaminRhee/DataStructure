#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;




typedef struct a{
  
  int key;
  char c[30];
  char* data=c;
  a* left_child;
  a* right_child;
  
  
}node;




class BST{
  
  private:
  
    node* root;
  
  public:
  
    BST(){
      
    };
    ~BST();
    
    void Add(int num, char* data);
    void Delete(int key);
    node* Search(int key);
    void Print();
    void Print(node* pos);
    void Quit();
    bool IsEmpty();
    node* SSearch(int key);
    node* DSearch(int key);
  
  
  
  
  
  
  
  
  
  
  
  
};