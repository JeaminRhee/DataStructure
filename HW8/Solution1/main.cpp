#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct node{
  string key;
  string value;
  struct node *left, *right;
}tree_node;

class BST{
  public:
      void inorderPrint(tree_node* node);

    tree_node *root = NULL;
    string search(tree_node* tree,string n);
    void insertBST(string n, string data);
    tree_node* modified_search(string n);
};

void BST::inorderPrint(tree_node* node)
{
  if(node){
    inorderPrint(node->left);
    cout << "("<<node->key<<","<<node->value<<")" << endl;
    inorderPrint(node->right);
  }
}

void BST::insertBST(string n, string data)
{
  tree_node* cur = new tree_node;
  cur->left = cur->right = NULL;
  cur->key = n;
  cur->value = data;
  
  if(root == NULL)
  {
    root = cur;
  }
  else
  {
    tree_node* temp = NULL;
    temp = modified_search(n);
    if(temp->key.compare(cur->key)>0)
    {
      if(temp->left == NULL)
      {
        temp->left = cur;
        return;
      }
      else
      {
        temp = temp->left;
      }
    }
    else
    {
      if(temp->right == NULL)
      {
        temp->right = cur;
        return;
      }
      else
      {
        temp = temp->right;
      }
    }
  }
}

tree_node* BST::modified_search(string n)
{
  tree_node *tree = root;
  while(tree != NULL){
    if(tree->key.compare(n)==0) return NULL;
    else if(tree->key.compare(n)>0)
      if(tree->left == NULL) return tree;
      else tree = tree->left;
    else
      if(tree->right == NULL) return tree;
      else tree = tree->right;
  }
  return NULL;
}

string BST::search(tree_node* tree,string n)
{
  while(tree)
  {
    if(n.compare(tree->key)==0)
      return tree->value;
    if(n.compare(tree->key)<0)
      tree= tree->left;
    else
      tree=tree->right;
  }
  return n;
}

int main() {
  BST tree;
  
  FILE *inf = NULL;
  char inputname[16];
  scanf("%s",inputname);
  inf = fopen(inputname,"r");
  
  FILE *mapf = NULL;
  char mapname[16];
  scanf("%s",mapname);
  mapf = fopen(mapname,"r");
  
  char b[1024];
  char a[1024];
  
  while(!feof(mapf))
  {
    fgets(b,1024,mapf);
    char *s = strtok(b,":");
    char *t = strtok(NULL," \n");
    
  //  cout<<s<<t<<endl;

    tree.insertBST(s,t);
  }

  fclose(mapf);
  //tree.inorderPrint(tree.root);
  
  while(!feof(inf))
  { int l=0;
    int i=0;
    fgets(a,1024,inf);
    char *ptr = strtok(a," ");
    i=strlen(a);
   // ptr = strtok(NULL," ");
  
    while(ptr != NULL)
    {
      string r = tree.search(tree.root,ptr);
      l=r.length();
      //cout<<r<<i<<l<<endl;
      if(r[l-1]=='.'&&l>=5) cout<<r;
      //else
     // if(&r[l-1]==&a[i-1]) cout<<r;
      else cout<<r<<" ";
    
      ptr = strtok(NULL," \n");
    } 

    printf("\n");
  }
  fclose(inf);
    
}