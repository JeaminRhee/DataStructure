#ifndef __CAL_H__
#define __CAL_H__
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class cal
{
    
  private:

    FILE * fp1 = NULL;
    FILE * fp2 = NULL;

    char Naming[2][20];
    char Naming2[2][20];

    float ** array1 = NULL;
    float ** array2 = NULL;
    int col1[10]={0}, col2[10]={0};
    int row1[10]={0}, row2[10]={0};

  public:
  
    void Read1(char* Naming);
    void Read2(char* Naming);
    void trans(char* Naming);
    float ** add_matrix(char* Naming, char* Naming2);
    float ** multi_matrix(char* Naming, char* Naming2);
};

#endif