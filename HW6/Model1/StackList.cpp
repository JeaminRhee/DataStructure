#include <iostream>
#include "StackList.h"

using namespace std;

StackList::StackList()
{
  stack_node * top = NULL;
}

StackList::~StackList()
{
   delete top;
}

void StackList::Push(person data)
{
  stack_node * new_node = new stack_node;
  if (new_node == NULL)
    return;
  
  new_node->person.id = data.id;
  new_node->person.name = data.name;
  new_node->person.email = data.email;

  new_node->link = top;
  top = new_node;
}

Person StackList::Pop()
{
  Person data;
  stack_node * del;

  if (top == NULL)
    return data;
  
  data.id = top->person.id;
  data.name = top->person.name;
  data.email = top->person.email;

  del = top;
  top = top->link;
  delete del;
  return data;
}

Person StackList::Assemble(string data)
{ 
  Person swap;
  int index = 0;
  int check = 0;
  string token;
  while (data[index] != '\0') {
    index++;
    if (data[index] == ',') {
      token = data.substr(0, index);
      if (check == 0) {
        swap.name = token;
        check++;
      }
      else if (check == 1) {
        swap.id = token;
        check++;
      }
      if (data[index + 1] == ' ')
        data.erase(0, token.length()+2);
      else
        data.erase(0, token.length()+1);
      index = 0;
    }
    else if (check == 2) {
      swap.email = data;
    }
  }
  return swap;
}

void StackList::Print(Person data) 
{
  cout << data.id << ", " << data.name << ", " << data.email << endl;
}

bool StackList::IsEmpty()
{
  return (top == NULL);
}