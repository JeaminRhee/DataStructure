#include <iostream>
#include "Calculator.h"
#include <cmath>
//#include "Stack1.h"
//#include "Stack2.h"

using namespace std;



int main() {
  Calculator calc;
  calc.Read();
  calc.Convert2post();
  
  if(calc.Evaluate())
  cout<<calc.Evaluate();
  
  
}