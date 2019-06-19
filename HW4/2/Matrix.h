#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>
using namespace std;

class MatrixOps{
	private:
		float **matrix_own=NULL;
		int row;
		int col;
		
	public:
		MatrixOps(int r, int c){
			row=r;
			col=c;
			matrix_own=(float**)malloc(sizeof(float*)*row);
			for(int i=0;i<row;i++)
				matrix_own[i]=(float*)malloc(sizeof(float)*col);
		}
		void make_matrix(FILE *);
		void add_matrix(MatrixOps *c);
		void mul_matrix(MatrixOps *c);
		void transpose_matrix();
};

#endif