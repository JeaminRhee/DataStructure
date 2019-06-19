#include <iostream>
#define MAX_SIZE 100
using namespace std;



typedef float Element;  // Type of each component is

class  Stack1  // Declares a class data type
{                       
  private:           // Private data members
    int top; 
    int max_size; 
    Element * stack;

  public:               // Public member functions
    Stack1(){
      top = -1;
      max_size = MAX_SIZE;
      stack = (Element*)malloc(max_size*sizeof(Element));   
    }// constructor
    
    Stack1(int max_num){
      top = -1;
      max_size = max_num;
      stack = (Element*)malloc(max_size*sizeof(Element));   
    }// constructor
    
    
    ~Stack1(){
      free(stack);
    }          // destructor 
    
    
    
    bool IsFullS () const{
      return (top == max_size-1);
    }
    
    bool IsEmptyS() const{
      return (top == -1);
    } 
    
    void Push (Element  item){
      if(IsFullS()) 
        cout << "The stack is full" << endl;
      else
        stack[++top] = item;
    } 
    
    Element Pop (){
      if(IsEmptyS()){
        cout << "The stack is empty" << endl;
        return (Element)0;
     }
      else
        return stack[top--];
    }   
    
    void Print () const{
      cout << "print" << endl;
      for(int i=0;i<=top;i++)
        cout<<stack[i]<<" ";
    }
    
    Element getTop(){
      return stack[top];
    }
};