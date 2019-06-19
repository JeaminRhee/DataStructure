#ifndef __BST_H__
#define __BST_H__
#include <iostream>
using namespace std;

typedef struct{
	int key;
	string value;
}Element;

typedef struct node{
	Element data;
	struct node *left_child;
	struct node *right_child;
}tree_node;

class BST{
	private:
		string line;
		tree_node *root;
	public:
		BST();
		~BST();
		void ReadFile(string);
		void Implement(char *);
		void insert_node(int, string);
		void delete_node(int);
		tree_node *insert_search(int key);
		tree_node *delete_search(int key);
		void delete_all(tree_node *);
		bool IsEmpty();
		void Print(tree_node *ptr);

};
#endif