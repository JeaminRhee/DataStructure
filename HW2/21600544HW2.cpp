#include <stdio.h>
#include <iostream>
#include <string.h>

#define MAX_LEN 1024
 
void upper_string(char []);
 
int main(void)
{
    char string[100];
   	int c = 0, count[255] = {0,}, x;
   	
   	int i,j,k=0;

	FILE *fp;
	char  file_name[MAX_LEN];
	char line[MAX_LEN];
	scanf("%s", file_name);
	
	fp = fopen(file_name, "r");
	
	if(fp == NULL){
		fprintf(stderr, "ERROR: file open has failed.");
		return -1;
	}
	
	while(fgets(line, MAX_LEN, fp)){
    	upper_string(line);
    	c=0;
    	k=0;
    	
    	while (line[c]!='\0') {
   			if ((line[c] >= 'A') && (line[c] <= 'Z')) {
       			x = line[c];
       			count[x]++;
    		}
			
			if((line[c]>='0') && (line[c]<='9')){
				x = line[c];
				count[x]++;
			}
			
			c++;
   		}
	}
	
	for(c=65;c<91;c++){
    	printf("%c: %d\n", c, count[c]);
    }
   	for(c=48;c<=57;c++){
   		printf("%c: %d\n", c, count[c]);
	}    
	
   	return 0;
}
 
void upper_string(char s[]) {
    int c = 0;
   
    while (s[c] != '\0') {
    	if (s[c] >= 'a' && s[c] <= 'z') {
			s[c] = s[c] - 32;
     	}
      	c++;
   }
}