#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <string.h>


using namespace std;

class FileChecking
{
  private:
   FILE * fp= NULL;
   char Line[512];
   char* token = NULL;
   string target[50];
   int i=0, j=0;
   
   stack<string> name;
   stack<string> age;
   stack<string> email;

   
  public:
   void ReadName(char* Naming);
   void split();
   void trim();
};

void FileChecking::ReadName(char* Naming)
{
  fp = fopen(Naming, "r");
  
  while(fgets(Line, 512, fp) != NULL) //한줄씩 받아들임
  {
    split();
  }
  j=0;
  
  for (i=0; i<15; i++)
   trim();
   
  int cct=0;
  
  for (i=0; i<5; i++)
  {
    name.push(target[cct++]);
    age.push(target[cct++]);
    email.push(target[cct++]);
  }
  
  for (i=0; i<5; i++)
  {
    cout << age.top() << ", " << name.top() << ", " << email.top() << endl;
    age.pop();
    name.pop();
    email.pop();
  }
  
  j=0;
}

void FileChecking::split()
{
  token = strtok(Line, ",");
  target[j++]=token;

  token = strtok(NULL, ",");
  target[j++]=token;

  token = strtok(NULL, ",");
  target[j++]=token;
}// if we meet "," , cut the string


void FileChecking::trim()
{
  if (target[j].front() == ' ')
    target[j].erase(0,1);
    
  if (target[j].back() == '\n')
    target[j].erase(target[j].length()-1,1);
   
  j++;
}// if we meet blank(white space) or ''\n' , erase it.

int main() 
{
  char* Name;
  
  FileChecking ck;
  cin >> Name;
  ck.ReadName(Name);
  
  return 0;
}