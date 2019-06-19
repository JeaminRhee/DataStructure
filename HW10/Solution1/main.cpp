#include <iostream>
#include <fstream>
#include <string.h>
#include <map>

using namespace std;

int main(){
  string filename;
  cin >> filename;
  ifstream fp;
  fp.open(filename);
  char stat;
  string buff;
  int num;
  map<int, string> my_map;
  map<int, string> :: iterator it;
  
  while(fp.peek() !=EOF){
    fp>>stat;
    if(stat=='q'){
      return 0;
    }
    else if(stat=='p'){
      for(it=my_map.begin(); it!=my_map.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
    }
    else if(stat=='a'){
      fp>>num;
      fp>>buff;
      if(my_map.find(num)==my_map.end())
        my_map.insert(make_pair(num, buff));
      else{
        cout <<num<<" is already in the tree."<<endl;
      }
    }
    else if(stat=='d'){
      fp>>num;
      if(my_map.find(num)!=my_map.end())
        my_map.erase(num);
      else
        cout <<num<<" is not in the tree."<<endl;;
    }
  }
}
