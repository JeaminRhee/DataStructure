#include <iostream>
#define MAX_SIZE 100
using namespace std;

typedef char element;  // Type of each component is

class  Stack2  // Declares a class data type
{                       
  private:           // Private data members
    int top; 
    int max_size; 
    element * stack;

  public:               // Public member functions
    Stack2(){
      top = -1;
      max_size = MAX_SIZE;
      stack = (element*)malloc(max_size*sizeof(element));   
    }// constructor
    
    Stack2(int max_num){
      top = -1;
      max_size = max_num;
      stack = (element*)malloc(max_size*sizeof(element));   
    }// constructor
    
    
    ~Stack2(){
      free(stack);
    }          // destructor 
    
    
    
    bool IsFullS () const{
      return (top == max_size-1);
    }
    
    bool IsEmptyS() const{
      return (top == -1);
    } 
    
    void Push (element  item){
      if(IsFullS()) 
        cout << "The stack is full" << endl;
      else
        stack[++top] = item;
    } 
    
    element Pop (){
      if(IsEmptyS()){
        cout << "The stack is empty" << endl;
        return (element)0;
     }
      else
        return stack[top--];
    }   
    
    void Print () const{
      cout << "print" << endl;
      for(int i=0;i<=top;i++)
        cout<<stack[i]<<" ";
    }
    
  element getTop(){
      return stack[top];
    }
};