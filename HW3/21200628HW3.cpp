#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float **read_mat(char* filename, int *r, int *c);
float **make2Darray(int a, int b);
float **mul_matrix(float **a, int ah, int aw, float **b, int bh, int bw);
float **add_matrix(float **a, int ah, int aw, float **b, int bh, int bw);
float **transpose_matrix(float **a, int ah, int aw);
void print_matrix(float **a, int ah, int aw);



int main()
{
   FILE * fp1 = NULL;
   FILE * fp2 = NULL;

   char fileName[2][20];
   char ops = '\0';
   char buf1[6];
   char buf2[6];
   char *buffer1;
   char *buffer2;

   int i = 0;
   int ah = 0;
   int aw = 0;
   int bh = 0;
   int bw = 0;

   float **m1;
   float **m2;
   float **result;


   
   scanf("%c", &ops);

   if (ops != 'a' && ops != 'm' && ops != 't') {
      fprintf(stderr, "Invalid operation.\n");
      return -1;
   }

   

   if (ops == 't')
   {
      scanf("%s", fileName[0]);

      fp1 = fopen(fileName[0], "r");

      if (fp1 == NULL)
      {
         fprintf(stderr, "Invalid file name. File open Error!\n");
         return -1;
      }
      buffer1 = fgets(buf1, 5, fp1);
      ah = atoi(buffer1);
      aw = atoi(buffer1 + 2);
   }

   else
   {
      for (i = 0; i < 2; i++) {
         scanf("%s", fileName[i]);
      }


      fp1 = fopen(fileName[0], "r");
      fp2 = fopen(fileName[1], "r");




      if (fp1 == NULL || fp2 == NULL) {
         fprintf(stderr, "Invalid file name. File open Error!\n");
         return -1;
      }
      buffer1 = fgets(buf1, 5, fp1);
      ah = atoi(buffer1);
      aw = atoi(buffer1 + 2);

      buffer2 = fgets(buf2, 5, fp2);
      bh = atoi(buffer2);
      bw = atoi(buffer2 + 2);

   }





   if (ops == 'a') {
      if (ah != bh || aw != bw)
      {
         printf("Matrix dimension mismatch");

      }

      else
      {
         printf("The output is:\n");

         m1 = read_mat(fileName[0], &ah, &aw);
         m2 = read_mat(fileName[1], &bh, &bw);



         result = make2Darray(ah, aw);
         result = add_matrix(m1, ah, aw, m2, bh, bw);


      }
   }




   else if (ops == 'm')
   {

      if (aw == bh)
      {

         printf("The output is:\n");


         m1 = read_mat(fileName[0], &ah, &aw);
         m2 = read_mat(fileName[1], &bh, &bw);


         result = make2Darray(ah,bw);
         result = mul_matrix(m1,ah,aw,m2,bh,bw);


      }

      else
      {
         printf("Matrix dimension mismatch");
      }


   }

   else if (ops == 't')
   {
      printf("The output is:\n");

      m1 = read_mat(fileName[0], &ah, &aw);

      result = make2Darray(ah, aw);
      result = transpose_matrix(m1, ah, aw);

   }


}

float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw)
{
   float **res;
   res = make2Darray(ah, aw);

   printf("%d %d\n", ah, aw);

   for (int i = 0; i < ah; i++)
   {
      for (int j = 0; j < aw; j++)
      {
         res[i][j] = a[i][j] + b[i][j];
      }

   }

   print_matrix(res, ah, aw);
   return res;
}


float **mul_matrix(float **a, int ah, int aw, float **b, int bh, int bw)
{
   float **res1;
   res1 = make2Darray(ah, bw);

   printf("%d %d\n", ah, bw);
   for (int i = 0; i<ah; i++)
   {
      for (int j = 0; j<bw; j++)
      {

         res1[i][j] = 0;
         for (int k = 0; k<aw; k++)
         {
            res1[i][j] += a[i][k] * b[k][j];
         }
      }
   }


   print_matrix(res1, ah, bw);
   return res1;
}

float **transpose_matrix(float **a, int ah, int aw)
{
   printf("%d %d\n", aw, ah);
   float **res2;
   res2 = make2Darray(aw, ah);

   for (int i = 0; i<aw; i++)
   {
      for (int j = 0; j<ah; j++)
      {
         res2[i][j] = a[j][i];
      }
   }

   print_matrix(res2, aw, ah);

   return res2;

}



void print_matrix(float **a, int ah, int aw)
{
   for (int i = 0; i < ah; i++)
   {
      for (int j = 0; j < aw; j++)
      {
         printf("%.1f", a[i][j]);
         if (j != aw - 1){
            printf(" ");
         }
         
      }
      printf("\n");
   }
}

float **make2Darray(int a, int b)
{
   float **arr1 = (float**)malloc(sizeof(float*)*a);

   for (int i = 0; i < a; i++)

   {
      arr1[i] = (float*)malloc(sizeof(float)*b);
   }

   return arr1;
}


float **read_mat(char* filename, int *r, int *c)
{
   float **mat;
   FILE *fp = fopen(filename, "r");

   fscanf(fp, "%d %d", r, c);

   mat = make2Darray(*r, *c);

   for (int i = 0; i< *r; i++)
   {
      for (int j = 0; j< *c; j++)
      {
         fscanf(fp, "%f", &mat[i][j]);
      }
   }
   return mat;

}