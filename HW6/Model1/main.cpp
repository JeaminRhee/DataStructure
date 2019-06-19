#include "StackList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main () {
  string exp;
  string data;
  ifstream fp;
  Person item;
  
  cin >> exp;
  try {
    fp.open(exp);
  }catch(const ifstream::failure& e) {
    cerr << "Exception occured." << endl;
  }

  StackList * stl = new StackList();

  while (!fp.eof()) {
    getline(fp, data);
    item = stl->Assemble(data);
    stl->Push(item);
  }

  while(!stl->IsEmpty()) {
    item = stl->Pop();
    stl->Print(item);
  }
}