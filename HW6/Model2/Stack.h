#include "Node.h"

class Stack // Declares a class data type
{
  Node* top;
  public:
  Stack()
  {
    top = NULL;   
  } 

  ~Stack()
  {
    while(!isEmpty()) delete Pop();
  }

  void Push(Node * p)
  {
    if(isEmpty()) top = p;
    else {
      p->setLink(top);
      top = p;
    } 
  }

  Node* Pop()
  {
    if(isEmpty()){
        return NULL;
    }
    Node * p = top;
    top = top->getLink();
    return p;
  }

  bool isEmpty() const
  { return (top == NULL); }

  void Print()
  {
    for(Node * p = top; p != NULL; p = p->getLink())
      p->display();
  }
};