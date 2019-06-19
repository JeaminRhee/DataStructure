#include <iostream>
#include <fstream>
#include "stack.h"

int main()
{
  // Read from the input files
  // Implement your own stack class using linked list
  char fileName[20];
  char name[MAX_STRING];
  int id = 0;
  char email[MAX_STRING];
  char tmp;
  scanf("%s", fileName);
  FILE* fp=fopen(fileName, "r");
  
  Stack stack;
  
  while(1) {
    if(feof(fp))
      break;
    fscanf(fp, "%s %d%c %s ", name, &id, &tmp, email);
    int len = strlen(name);
    name[len-1] = '\0';
    stack.Push(new Node(name, id, email) );
  }
  
  stack.Print();  
  return 0;
}