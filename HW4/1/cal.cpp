#include <iostream>
#include <fstream>
#include <string>
#include "cal.h"

using namespace std;

void cal::Read1(char* Naming)
{
    fp1 = fopen(Naming, "r");
    fscanf(fp1,"%d %d", row1,col1);

    array1 = (float**) malloc (sizeof(float*) * row1[0]);
  
    for (int i=0 ; i < row1[0] ; i++)
    {
      *(array1 + i) = (float*)malloc(sizeof(float*)*col1[0]);
    }
  
    for (int i=0; i <row1[0] ; i++)
    {
      for (int j=0; j <col1[0] ; j++)
      {
        fscanf(fp1,"%f",&array1[i][j]);
      }
    } // array1 complete.
}// Read1 func End Part.

void cal::Read2(char* Naming)
{
  fp2 = fopen(Naming, "r");
  fscanf(fp2,"%d %d", row2,col2);

  array2 = (float**) malloc (sizeof(float*) * row2[0]);
  
  for (int i=0 ; i < row2[0] ; i++)
  { 
    *(array2 + i) = (float*)malloc(sizeof(float*)*col2[0]);
  }
  
  for (int i=0; i <row2[0] ; i++)
  {
    for (int j=0; j <col2[0] ; j++)
    {
      fscanf(fp2,"%f",&array2[i][j]);
    }
  } // array1 complete.
}// Read2 func End Part.


void cal::trans(char* Naming)
{
  cout << fixed;
  cout.precision(1);
  
  int row=col1[0] , col=row1[0];
  int temp=0;
  float ** charr = NULL;
  
  charr = (float**) malloc (sizeof(float*) * row);
  for (int i=0 ; i < row ; i++)
  {
    *(charr + i) = (float*)malloc(sizeof(float*)*col);
  }
  
  cout << "The output is:" << endl;
  cout << row << " " << col << endl;

  for (int i=0; i<row; i++)
  {
    for (int j=0; j<col; j++)
    {
      temp=array1[j][i];
      charr[i][j]=array1[j][i];
      array1[j][i] = temp;
      cout << charr[i][j] << " ";
    }
    cout << endl;
  }
}//trans func End Part.

float** cal::add_matrix(char* Naming, char* Naming2)
{
  cout << fixed;
  cout.precision(1);
  
  if (row1[0] == row2[0] && col1[0] == col2[0])
  {
    cout << "The output is:" << endl;
    cout << row1[0] << " " << col1[0] << endl;
    
    for (int i=0; i<row1[0]; i++)
    {
      for (int j=0; j<col1[0]; j++)
      {
        array1[i][j]+=array2[i][j];
        cout << array1[i][j] << " ";
      }
      cout << endl;
    }
  }
  else
   cout << "Matrix dimension mismatch" << endl;
   
   return array1;
}// add func End Part.


float ** cal::multi_matrix(char* Naming, char* Naming2)
{
  cout << fixed;
  cout.precision(1);
  
  float ** mularr = {0};
  
  mularr = (float**) malloc (sizeof(float*) * row1[0]);
  for (int i=0 ; i < row1[0] ; i++)
  {
    *(mularr + i) = (float*)malloc(sizeof(float*)*col2[0]);
  }
  
  if (col1[0] == row2[0])
  {
    cout << "The output is:" << endl;
    cout << row1[0] << " " << col2[0] << endl;
  
    for (int a=0; a<row1[0]; a++)
    {
      for (int b=0; b<col2[0]; b++)
      {
        for (int c=0;c <row2[0]; c++)
        {
          mularr[a][b] += (array1[a][c] * array2[c][b]);
        }
        cout << mularr[a][b];
        
        if (b != col2[0]-1)
         cout << " ";
      }
      cout << endl;
    }
  }
  
  if (col1[0] != row2[0])
   cout << "Matrix dimension mismatch" << endl;
   
  return mularr;
}// multi func End Part.


