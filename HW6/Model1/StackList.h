#ifndef __STACKLIST_H__
#define __STACKLIST_H__

#include <iostream>
using namespace std;

typedef struct person {
  string id;
  string name;
  string email;
}Person;

typedef struct t_list_node {
  Person person;
  struct t_list_node * link;
} stack_node;


class StackList
{
  private:
    stack_node * top;

  public:
    StackList();
    ~StackList();
    void Push (Person data);
    Person Pop();
    Person Assemble(string data);
    void Print(Person data);
    bool IsEmpty();
};
#endif