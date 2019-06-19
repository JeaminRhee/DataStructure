#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float **matadd(float **mat1, float **mat2, int row, int col);
float **matmul(float **mat1, int row1, int col1, float **mat2, int row2, int col2);
float **mattran(float **mat, int row, int col);

int main() {
  FILE * fp1 = NULL;
  FILE * fp2 = NULL;
  
  char temp1[1024];
  char temp2[1024];
  char fileName[2][20];
  char ops = '\0';
  int i = 0;
  
  //printf("What operation do you want? (\'a\', \'m\', \'t\')\n");
  scanf("%c", &ops);
  
  if(ops != 'a' && ops != 'm' && ops != 't'){
    fprintf(stderr, "Invalid operation.\n");
    return -1;
  }
  
  if(ops == 'a' || ops == 'm'){
  //printf("Input files names:\n");
  for(i=0; i< 2; i++){
    scanf("%s", fileName[i]);
  }
  
  fp1 = fopen(fileName[0], "r");
  fp2 = fopen(fileName[1], "r");
  
  if(fp1 == NULL || fp2 == NULL){
    fprintf(stderr, "Invalid file name. File open Error!\n");
    return -1;
  }
  
  fgets(temp1,1024,fp1);
  fgets(temp2,1024,fp2);

  //printf("%d\n",int(temp[0]-'0'));
  int row1 = int(temp1[0] - '0');
  int col1 = int(temp1[2] - '0');
  int row2 = int(temp2[0] - '0');
  int col2 = int(temp2[2] - '0');
  
  // printf("%d %d\n", row1, col1);
  // printf("%d %d\n", row2, col2);
  
  float **arr1 = (float **)malloc(row1 * sizeof(float *));
  for (int i = 0; i < row1; i++){
    arr1[i] = (float *)malloc(col1 * sizeof(float));
  }
  
  float **arr2 = (float **)malloc(row2 * sizeof(float *));
  for(int i = 0; i < row2; i++){
    arr2[i] = (float *)malloc(col2 * sizeof(float));
  }
  
  for(int r = 0; r < row1; r++){
    fgets(temp1,1024,fp1);
    int len = strlen(temp1);
    char temp[len];

    int j = 0;
    int k = 0;
    for(int i = 0; i < len+1; i++){
      if (temp1[i] == '\0'){
        float a = atof(temp);
        arr1[r][k] = a;
        k++;
        for(int l = 0; l < j; l++){
          temp[l] = '\0';
        }
        j = 0;
      }
      else if(temp1[i] != ' '){
        temp[j] = temp1[i];
        j++;
      }
      else{
        float a = atof(temp);
        arr1[r][k] = a;
        k++;
        for(int l = 0; l < j; l++){
          temp[l] = '\0';
        }
        j = 0;
      }
    }
  }
  
  for(int r = 0; r < row2; r++){
    fgets(temp2,1024,fp2);
    int len = strlen(temp2);
    char tempo[len];
    int j = 0;
    int k = 0;
    for(int i = 0; i < len+1; i++){
      if (temp2[i] == '\0'){
        float a = atof(tempo);
        arr2[r][k] = a;
        k++;
        for(int l = 0; l < j; l++){
          tempo[l] = '\0';
        }
        j = 0;
      }
      else if(temp2[i] != ' '){
        tempo[j] = temp2[i];
        j++;
      }
      else{
        float a = atof(tempo);
        arr2[r][k] = a;
        k++;
        for(int l = 0; l < j; l++){
          tempo[l] = '\0';
        }
        j = 0;
      }
    }
  }
  
  // for(int i = 0; i < col1; i++){
  //   printf("%f ", arr1[0][i]);
  // }
  // printf("\n");
  // for(int i = 0; i < col2; i++){
  //   printf("%f ", arr2[0][i]);
  // }
  // printf("\n");
  // printf("\n");
  
  if (ops == 'a'){
    if (row1 != row2 || col1 != col2){
      printf("Matrix dimension mismatch");
      //exit(1);
    }
    else{
      printf("The output is:\n");
      float **newmat = matadd(arr1, arr2, row1, col1);
      printf("%d %d\n", row1, col1);
      for(int i = 0; i < row1; i++){
        printf("%.1f", newmat[i][0]);
        for(int j = 1 ; j < col1; j++){
          printf(" %.1f", newmat[i][j]);
        }
        printf("\n");
      }
    }
  }
  
  else if(ops == 'm'){
    if(col1 != row2){
      printf("Matrix dimension mismatch");
      //exit(1);
    }
    else{
      printf("The output is:\n");
      float **newmat = matmul(arr1, row1, col1, arr2, row2, col2);
      printf("%d %d\n", row1, col2);
      for(int i = 0; i < row1; i++){
        printf("%.1f", newmat[i][0]);
        for(int j = 1 ; j < col2; j++){
          printf(" %.1f", newmat[i][j]);
        }
        printf("\n");
      }
    }
  }
  }
  
  // float **newmat = matadd(arr1, arr2, row1, col1);
  // printf("%d %d\n", row1, col1);
  // for(int i = 0; i < row1; i++){
  //   for(int j = 0 ; j < col1; j++){
  //     printf("%.1f ", newmat[i][j]);
  //   }
  //   printf("\n");
  // }
  

  // float **newmat = matmul(arr1, row1, col1, arr2, row2, col2);
  // printf("%d %d\n", row1, col2);
  // for(int i = 0; i < row1; i++){
  //   for(int j = 0 ; j < col2; j++){
  //     printf("%.1f ", newmat[i][j]);
  //   }
  //   printf("\n");
  // }

  else if(ops == 't'){
    scanf("%s", fileName[0]);
  
  fp1 = fopen(fileName[0], "r");
  
  if(fp1 == NULL){
    fprintf(stderr, "Invalid file name. File open Error!\n");
    return -1;
  }
  
  fgets(temp1,1024,fp1);

  //printf("%d\n",int(temp[0]-'0'));
  int row1 = int(temp1[0] - '0');
  int col1 = int(temp1[2] - '0');
  
  // printf("%d %d\n", row1, col1);
  // printf("%d %d\n", row2, col2);
  
  float **arr1 = (float **)malloc(row1 * sizeof(float *));
  for (int i = 0; i < row1; i++){
    arr1[i] = (float *)malloc(col1 * sizeof(float));
  }
  
  
  for(int r = 0; r < row1; r++){
    fgets(temp1,1024,fp1);
    int len = strlen(temp1);
    char temp[len];

    int j = 0;
    int k = 0;
    for(int i = 0; i < len+1; i++){
      if (temp1[i] == '\0'){
        float a = atof(temp);
        arr1[r][k] = a;
        k++;
        for(int l = 0; l < j; l++){
          temp[l] = '\0';
        }
        j = 0;
      }
      else if(temp1[i] != ' '){
        temp[j] = temp1[i];
        j++;
      }
      else{
        float a = atof(temp);
        arr1[r][k] = a;
        k++;
        for(int l = 0; l < j; l++){
          temp[l] = '\0';
        }
        j = 0;
      }
    }
  }
  
    printf("The output is:\n");
    float **newmat = mattran(arr1, row1, col1);
    printf("%d %d\n", col1, row1);
    for(int i = 0; i < col1; i++){
      printf("%.1f", newmat[i][0]);
      for(int j = 1 ; j < row1; j++){
        printf(" %.1f", newmat[i][j]);
      }
      printf("\n");
    }
  }


  
  // float **newmat = mattran(arr1, row1, col1);
  // printf("%d %d\n", col1, row1);
  // for(int i = 0; i < col1; i++){
  //   for(int j = 0 ; j < row1; j++){
  //     printf("%.1f ", newmat[i][j]);
  //   }
  //   printf("\n");
  // }
  
  else{
    printf("input should be a/m/t");
  }
  

  return 0;
}

float **matadd(float **mat1, float **mat2, int row, int col){
  float **newmat = (float **)malloc(row * sizeof(float *));
  for (int i = 0; i < row; i++){
    newmat[i] = (float *)malloc(col * sizeof(float));
  }
  
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      newmat[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  
  return newmat;
}

float **matmul(float **mat1, int row1, int col1, float **mat2, int row2, int col2){
  float **newmat = (float **)malloc(row1 * sizeof(float *));
  for (int i = 0; i < row1; i++){
    newmat[i] = (float *)malloc(col2 * sizeof(float));
  }
  
  for(int i = 0; i < row1; i++){
    for(int j = 0 ; j < col2; j++){
      for(int k = 0; k < col1; k++){
        newmat[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  
  return newmat;
}

float **mattran(float **mat, int row, int col){
  float **newmat = (float **)malloc(col * sizeof(float *));
  for (int i = 0; i < col; i++){
    newmat[i] = (float *)malloc(row * sizeof(float));
  }
  
  for(int i = 0; i < col; i++){
    for(int j = 0; j < row; j++){
      newmat[i][j] = mat[j][i];
    }
  }

  return newmat;
}

