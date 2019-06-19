#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
  char *name;
  scanf("%s", name);

  FILE *pFile = NULL;

  pFile = fopen(name, "r");
  char c;
  bool findNum = false;
  string myStr;
  float total;
  if( pFile == NULL){
    printf("error~");
  }
  else{

    while(c != EOF){
        c = fgetc(pFile);

        if(findNum || isdigit(c)){
          findNum = true;


          if(c != '.' && !isdigit(c)){
            findNum = false;
            myStr += '\0';
            // cout << myStr << endl;

            total += stof(myStr);
            myStr = "";
          }
          else{
              myStr += c;
          }
        }

        // if(isdigit(c) || c == '.'){
        //   cout << c << " ";
        // }
    }
  }
  cout << "The sum is ";
  cout << total;
  fclose(pFile);
	return 0;
}
