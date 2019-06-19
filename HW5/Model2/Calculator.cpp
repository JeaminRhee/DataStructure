#include <string.h>
#include <iostream>
#include "Calculator.h"
#include <fstream>
#include <stdio.h>
#include <cmath>

//#include "Stack1.h"
//#include "Stack2.h"

using namespace std;




void Calculator::Read(){
      
      char name[1024];
      char* fileName=name;
      scanf("%s",fileName);
      FILE* fp= fopen(fileName, "r");
      if(fp == NULL)
        cerr << "Exception occurred while opening the file." << endl;
      fgets(fileName,1023,fp);
      infix_exp=fileName;
      
      
}
  



void Calculator::Convert2post(){
      
      for(int i=0; infix_exp[i]!='\0'; i++){ //infix를 postfix로 바꾸기
        
        
        char x = infix_exp[i];
        
        if (x==' ') continue;//공백일 경우 건너뛴다
        
        if(isdigit(x)||x=='.'){//x가 숫자거나 . 일 경우
          postfix_exp+=x;//string 에 char 더하는 거라서 오류 뜰 확률 있음
          if(!isdigit(infix_exp[i+1])&&infix_exp[i+1]!=46)//다음 캐릭터가 숫자가 아니라면
            postfix_exp+=" ";//공백으로 숫자 끊어주기
          continue;
        }
        
        if(stackChar.IsEmptyS()){//스택이 비었을 경우
          stackChar.Push(x);
          continue;
        }
        
        if(x=='('){
          stackChar.Push(x);
          continue;
        }
          
        if(x==')'){
          
          while(stackChar.getTop()!='(')
            postfix_exp+=stackChar.Pop();
          stackChar.Pop();
          continue;
        }
        //괄호 처리
        
        
        if(get_pre(stackChar.getTop())<get_pre(x)){
          stackChar.Push(x);
          continue;
        }
        
        while(1){
          
          if(get_pre(stackChar.getTop())>=get_pre(x))
            postfix_exp+=stackChar.Pop();
          else if(stackChar.IsEmptyS()){//스택이 비었을 경우
          stackChar.Push(x);
          break;
          }
          else if(get_pre(stackChar.getTop())<get_pre(x)){
            stackChar.Push(x);
          break;
          }
          
        }//우선순위에 따라 Pop/Push
        
      }
      
      while(!stackChar.IsEmptyS())
        postfix_exp+=stackChar.Pop();
        
       
     //stack끝까지 POP
}
    
int Calculator::get_pre(char a){
  switch (a){
    case '(': return 0;
    case '*': return 2;
    case '/': return 2;
    case '%': return 2;
    case '+': return 1;
    case '-': return 1;
    case ')': return 0;
  }
  return 0;
}
   
   
float Calculator::Evaluate(){ 
  float op1,op2;
  char ops;
  //char* a[20];
  //string numstr=a;
  string numstr;
  
  
  for(int i=0; postfix_exp[i]!='\0'; i++){
    char x = postfix_exp[i];
    
    
    if(isdigit(x)||x=='.'){//x가 숫자거나 . 일 경우
      numstr+=x;
      if(!isdigit(postfix_exp[i+1])&&postfix_exp[i+1]!=46){//다음 캐릭터가 숫자가 아니라면
        stackNum.Push(stof(numstr));
       
        numstr="\0";
      
      }
      continue;
    }
    
    if (x==' ') continue;//공백일 경우 건너뛴다
    
    
    op2=stackNum.Pop();
    op1=stackNum.Pop();
    
    switch (x){
      case '+': stackNum.Push(op1+op2); break;
      case '-': stackNum.Push(op1-op2); break;
      case '/': stackNum.Push(op1/op2); break;
      case '*': stackNum.Push(op1*op2); break;
     
    }
    
  }
 
  float n= stackNum.Pop()*10;
  n=ceil(n);
  
  return n/10;//stackNum.Pop();  

  
}
      
void Calculator::print_post(){
  cout<<postfix_exp<<endl;
}