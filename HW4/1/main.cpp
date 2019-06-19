#include <iostream>
#include <fstream>
#include <string>
#include "cal.h"
/*
Read1- Read & make a matrix
Read2- same.
trans - transspace the matrix
add_matrix - add the matrix
multi_matrix - multiply the matrix
*/

using namespace std;

int main()
{
  string ops;
  char fileName[2][20];

  cal c;
  
  cin >> ops;
  
  if(ops.compare("a") != 0 && ops.compare("m") != 0 && ops.compare("t") != 0) // ops exception
  {
    cerr << "Invalid operation." << endl;
    return -1;
  }
  
  if (ops.compare("t") != 0) // ops != 't'
  {
    for(int i = 0; i < 2; i++)
    {
      cin >> fileName[i];
    }
    c.Read1(fileName[0]);
    c.Read2(fileName[1]);
  }

  if (ops.compare("t") == 0) // ops == 't'
  {
    cin >> fileName[0];
    c.Read1(fileName[0]);
    c.trans(fileName[0]);
  }
  
  if (ops.compare("a") == 0) // ops == 'a'
  {
    c.add_matrix(fileName[0],fileName[1]);
  }
  
  if (ops.compare("m") == 0) // ops == 'm'
  {
    c.multi_matrix(fileName[0],fileName[1]);
  }

  return 0;
}