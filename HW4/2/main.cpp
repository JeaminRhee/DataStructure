#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "Matrix.h"

using namespace std;

int main(){
  FILE *fp1=NULL,*fp2=NULL;
  string ops;
  char fileName[2][20];
  
  cin >> ops;
  
  if(ops.compare("a") && ops.compare("m") && ops.compare("t")){
    cerr << "Invalid operation." << endl;
    return -1;
  }
  
  if(!ops.compare("t")){
		cin>>fileName[0];
		fp1=fopen(fileName[0], "r");
		
		if(fp1 == NULL){
    fprintf(stderr, "Invalid file name. File open Error!\n");
    return -1;
  	}
  	
	}
	else{
	  for(int i=0; i< 2; i++)
	    cin>>fileName[i];

	  fp1 = fopen(fileName[0], "r");
	  fp2 = fopen(fileName[1], "r");

	  if(fp1 == NULL || fp2 == NULL){
	    fprintf(stderr, "Invalid file name. File open Error!\n");
	    return -1;
	  }
	}
  
  //file로부터 size읽어들이기& matrix2개 생성
  if(!ops.compare("t")){
  	int row[1], col[1];
	  fscanf(fp1,"%d %d",&row[0],&col[0]);
	  
	  MatrixOps *c1;
	  c1=new MatrixOps(row[0],col[0]);
    if(!ops.compare("t")){
  		c1->make_matrix(fp1);
  		c1->transpose_matrix();
  		free(c1);
  		fclose(fp1);
  	}
    else
      cout<<"Matrix dimension mismatch"<<endl;
  }
  else{
  	int row[2], col[2];
	  fscanf(fp1,"%d %d",&row[0],&col[0]);
	  fscanf(fp2,"%d %d",&row[1],&col[1]);
	  
	  MatrixOps *c1;
	  c1=new MatrixOps(row[0],col[0]);
	  MatrixOps *c2;
	  c2=new MatrixOps(row[1],col[1]);
	  if(!ops.compare("a")){
    	if( (row[0]==row[1]) && (col[0]==col[1]) ){
        c1->make_matrix(fp1);
        c2->make_matrix(fp2);
        c1->add_matrix(c2);
        free(c1);
        free(c2);
        fclose(fp1);
        fclose(fp2);
       }
       else
      	cout<<"Matrix dimension mismatch"<<endl;
    }
      else if(!ops.compare("m")){
      	if(col[0]==row[1]){
          c1->make_matrix(fp1);
          c2->make_matrix(fp2);
          c1->mul_matrix(c2);
          free(c1);
          free(c2);
          fclose(fp1);
          fclose(fp2);
        }
         else
        	cout<<"Matrix dimension mismatch"<<endl;
      }
 }

  
	return 0;
}