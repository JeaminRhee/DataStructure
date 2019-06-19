#include "Element.h"

class Node : public Element {
  Node * link;
  public :
    Node(char* name, int id, char * email) : Element(name, id, email) { link = NULL; }
    ~Node(void) { }
    Node* getLink() {return link; }
    void setLink(Node *p) { link = p; }
};