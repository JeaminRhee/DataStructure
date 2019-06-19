#include <iostream>
#include "Matrix.h"
using namespace std;

/*void MatrixOps::print(){
	for(int i=0;i<row;i++){
		printf("%d\n",i);
		for(int j=0;j<col;j++){
			printf("%d ",j);
		
		}
		printf("\n");
	}
}*/

void MatrixOps::make_matrix(FILE *fp){
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			fscanf(fp,"%f",&matrix_own[i][j]);
}
void MatrixOps::add_matrix(MatrixOps *c){
	//새로운 matrix만들기 
	float **new_mtx=NULL;
	new_mtx=(float**)malloc(sizeof(*new_mtx)*row);
	for(int i=0;i<row;i++)
		new_mtx[i]=(float*)malloc(col*sizeof(new_mtx));
	//새로운 matrix에 add한 값 넣어주기 
	cout<<"The output is:"<<endl<<row<<" "<<col<<endl;
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			new_mtx[i][j]=matrix_own[i][j]+c->matrix_own[i][j];
			printf("%.1f",new_mtx[i][j]);
			
			if(j+1!=col)
					printf(" ");
		}
		printf("\n");
	}
	//free시켜주기
	for(int i=0;i<row;i++)
		free(new_mtx[i]);
	free(new_mtx);
}
void MatrixOps::mul_matrix(MatrixOps *c){
	//새로운 matrix만들기
	float **new_mtx=NULL;
	new_mtx=(float**)malloc(sizeof(*new_mtx)*row);
	for(int i=0;i<row;i++)
		new_mtx[i]=(float*)malloc(c->col*sizeof(new_mtx));
	
	//새로운 matrix에 Multiply한 값 넣어주기 
	cout<<"The output is:"<<endl<<row<<" "<<c->col<<endl;
	
	for(int i=0;i<row;i++){
		for(int j=0;j<c->col;j++){
			float sum=0;
			for(int k=0;k<col;k++)
				sum+=matrix_own[i][k]*(c->matrix_own[k][j]);
		
			new_mtx[i][j]=sum;
			printf("%.1f",new_mtx[i][j]);
			
			if(j+1!=c->col)
					printf(" ");
		}
		printf("\n");
	}
	
	//free시켜주기
	for(int i=0;i<row;i++)
		free(new_mtx[i]);
	free(new_mtx);
}
void MatrixOps::transpose_matrix(){
	float **new_mtx=NULL;
	new_mtx=(float**)malloc(sizeof(*new_mtx)*col);
	for(int i=0;i<col;i++)
		new_mtx[i]=(float*)malloc(row*sizeof(new_mtx));
	
	//새로운 matrix에 transpose해주기 
	cout<<"The output is:"<<endl<<col<<" "<<row<<endl;
	
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			new_mtx[i][j]=matrix_own[j][i];
			printf("%.1f",new_mtx[i][j]);
			
			if(j+1!=row)
					printf(" ");
		}
		printf("\n");
	}
	
	//free시켜주기 
	for(int i=0;i<col;i++)
		free(new_mtx[i]);
	free(new_mtx);
}