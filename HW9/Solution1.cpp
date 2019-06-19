#include <iostream>
#include <cstring>
#include <string>


#include <algorithm>
#include <vector>
using namespace std;

class UserInfo{
  string name;
  int age;
  string email;

public:
  UserInfo(string name, int age, string email){
    this->name = name;
    this->age = age;
    this->email = email;
  }

  // bool operator <(const UserInfo &a) const {
  //   // return this->age > a.age;
  //   return this->name > a.name;
  // }

  string get_name(){return name;}
  int get_age(){return age;}
  string get_email(){return email;}

};

int main() {

  FILE * fp1 = NULL;
  char fileName[20];
  char line[256];
  int i;


  vector<UserInfo> v;

  scanf("%s", fileName);
  fp1 = fopen(fileName, "r");

  while(!feof(fp1)) {
    char * token;
    if(fgets(line, sizeof(line), fp1)){
        token = strtok(line, ", ");

        string name;
        int age;
        string email;
        i = 0;

        while(token) {
            if(i==0){
              name = token;
              token = strtok(NULL, ", ");
            }
            else if(i==1){
              age = stoi(token);
              token = strtok(NULL, ", \n");
            }
            else {
              email = token;
              token = strtok(NULL, ", ");
            }
            i++;
        }
        v.push_back(UserInfo(name, age, email));
    }
  }

  reverse(v.begin(), v.end());

  for(int i=0 ; i<v.size() ; i++){
    cout << v[i].get_age() << ", " << v[i].get_name() << ", " << v[i].get_email() << endl;
  }



  return 0;
}
