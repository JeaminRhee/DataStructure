#include <iostream>
#include "BST.h"
using namespace std;

int main(void) {
	BST bst;
	string filename;
	cin>>filename;
	bst.ReadFile(filename);
	return 0;
}