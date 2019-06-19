#include <iostream>
#include "Stack1.h"
#include "Stack2.h"

using namespace std;

class Calculator{
  private:
    Stack1 stackNum; // 숫자, float형
    Stack2 stackChar; // 기호, char형
    string infix_exp, postfix_exp;
  public:
    
    Calculator(){
      
      
    }//생성자
    void Read();
    void Convert2post();
    float Evaluate();
    void print_post();
    int get_pre(char a);
};