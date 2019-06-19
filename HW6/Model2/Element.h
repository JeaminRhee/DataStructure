#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 200

using namespace std;

class Element {
  char name[MAX_STRING];
  int id;
  char email[MAX_STRING];
  
  public:
    Element(char* n, int i, char* e) { set(n, i, e); }
    void set(char* n, int i, char* e) {
      strcpy(name, n);
      id = i;
      strcpy(email, e);
    }
    void display() {
      printf("%d, %s, %s\n", id, name, email);
    }
};