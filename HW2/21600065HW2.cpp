#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

int main(){
  FILE *fp;
  char file_name[MAX_LEN];
  char line[MAX_LEN];
  int i, j;           // variables for looping
  int length;
  int alphanum[MAX_LEN] = {0};      // array giving number of alphabet char
  int numbernum[MAX_LEN] = {0};     // array giving number of numeric char
  
  //printf("Input file name: ");
  scanf("%s", file_name);
  
  fp = fopen(file_name, "r");
  if(fp == NULL){
    fprintf(stderr, "ERROR: file open has failed.");
    return -1;
  }
  
  while(fgets(line, MAX_LEN, fp)){
    length = strlen (line);
    //printf("%s", line);
    
    for (i = 0; i < length; i++) {
      if (isalpha(line[i]) != 0) {
        for (j = 0; j < 26; j++) {
          if (line[i] == 'A'+j || line[i] == 'a'+j)
            alphanum[j]++;
        }
      }       // the number of alphabet is 26 (A ~ Z)
      
      else if (isdigit(line[i]) != 0) {
        for (j = 0; j < 10; j++) {
          if (line[i] == '0'+i || line[i] == '0'+j)
            numbernum[j]++;
        }
      }     // the number of digit is 10 (0 ~ 9)
    }
  }
  for (i = 0; i < 26; i++) {
    printf ("%c: %d\n", 'A'+i, alphanum[i]);
  }
  for (i = 0; i < 10; i++) {
    printf ("%c: %d\n", '0'+i, numbernum[i]);
  }
  
  fclose(fp);
  return 0;
}