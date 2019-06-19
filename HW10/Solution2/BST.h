#ifndef __BST_H__
#define __BST_H__
#include <iostream>
#include <map>
using namespace std;

class BST{
	private:
		string line;
		map<int,string> my_map;
		
	public:
		void ReadFile(string);
		void Implement(char *);
		void insert_node(int, string);
		void delete_node(int);
		void Print();

};
#endif