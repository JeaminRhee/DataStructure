#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <cmath>  
#define MAX_STACK_SIZE 99
#define FALSE 0
using namespace std;


class Stack1  
{ private: 
 char stack[100];
 int top;
public: 
 Stack1() { top = -1; }
 void push(char val) { stack[++top] = val; }  
 char pop() { return stack[top--]; }   
 int isEmpty() { return top == -1; }   
 int isFull() { return top == MAX_STACK_SIZE; }
 char getTop() {return stack[top]; }    
 
};

class Stack2  // Declares a class data type 
{ private:           // Private data members 
 float stack[100];
 int top;
public:
 Stack2() { top = -1; }
 void push(float val) { stack[++top] = val; }
 float pop() { return stack[top--]; }
 int isEmpty() { return top == -1; }
 int isFull() { return top == MAX_STACK_SIZE; }
 float getTop() { return stack[top]; }  
};

class Calculator{
  private:
    Stack1 s1; // operator
    Stack2 s2; // operand
    string infix_exp, postfix_exp;
    
  char buffer[80];
 char postfix[80];
   
  public:
   
    Calculator();
    void Read(string exp);
    void tokenizer();
    void Convert_infix2postfix();
    float Evaluate();
    int priority(char);
};

int Calculator::priority(char ch) { 
 if (ch == ')')
  return 4;
    else if (ch == '*' || ch == '/')
  return 3;
 else if (ch == '+' || ch == '-')
  return 2;
 else
  return 1;
}


Calculator::Calculator() {
	
	
}



void Calculator::Convert_infix2postfix() { 

strcpy(buffer,postfix_exp.c_str());
int i = 0, j = 0;
 char ch;

while(buffer[i] != FALSE)
{
	
	if (isdigit(buffer[i]) || buffer[i]== '.') { 
	while (isdigit(buffer[i]) || buffer[i]== '.')
	
    postfix[j++] = buffer[i++];
    postfix[j++] = ' ';
    
  }

  else if (buffer[i] == '(') { 
   s1.push(buffer[i]);
   i++;
  }
  else if (buffer[i] == ')') {
   ch = s1.pop();
   while (ch != '(') {
    postfix[j++] = ch;
    postfix[j++] = ' ';
    ch = s1.pop();
   }
   i++;
  }


else {
   if (s1.isEmpty())
    s1.push(buffer[i++]);
   else { 
    while (!s1.isEmpty() && priority(s1.getTop()) >= priority(buffer[i])) {
     ch = s1.pop();
     postfix[j++] = ch;
     postfix[j++] = ' ';
     }
    s1.push(buffer[i]);
    i++;
   }
  }
 }
 while (!s1.isEmpty()) { 
  ch = s1.pop();
  postfix[j++] = ch;
  postfix[j++] = ' ';
 }
 postfix[j] = FALSE;

 
 //cout << "postfix : " << postfix << endl;


}


void Calculator::tokenizer(){
	

	string s=infix_exp;
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    
    postfix_exp=s;
Convert_infix2postfix();
Evaluate();
}
void Calculator:: Read(string exp){
     
  infix_exp=exp;
  tokenizer();
} 

float Calculator::Evaluate() {

int i = 0, k;
 char token[5];
 float num, number, num1, num2;
 char ch;

 while (postfix[i] != FALSE) {
  if (isdigit(postfix[i]) || postfix[i]== '.') {
   k = 0;
   while (isdigit(postfix[i])|| postfix[i]== '.') 
   token[k++] = postfix[i++];
   token[k] = FALSE; 
   num = atof(token); 
   
   s2.push(num);
   
   
  }
 

  
  
  else if (postfix[i] == ' ')
   i++;
  else { 
   ch = postfix[i++];
   num1 = s2.pop();
   num2 = s2.pop();
   if (ch == '+') number = num2 + num1;
   else if (ch == '-') number = num2 - num1;
   else if (ch == '*') number = num2 * num1;
   else if (ch == '/') number = num2 / num1;
   else if (ch == '/' && num1 == 0) number = 0;
   s2.push(number);
  }
  i++; 
 }
 
  return s2.pop();

}


int main() {
	FILE *fp =NULL;
	char str [1000];
	float result=0;
	char fileName[0][20];
		
	scanf("%s", fileName[0]);
	fp = fopen(fileName[0], "r");
  	if(fp == NULL){
    fprintf(stderr, "Invalid file name. File open Error!\n");
    return -1;
  }
  fgets(str, 1000, fp);
  