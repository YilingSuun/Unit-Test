/******************************************************************************
csci3081 s25 hw3
*******************************************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

enum Color { RED, BLACK };

class Node {
 private:
  int value;     // value of the node
  Color color;   // color of the node
  Node* left;    // left child
  Node* right;   // right child
  Node* parent;  // parent node

 public:
  Node(int value);  // constructor
  Node();           // default constructor
  ~Node();          // destructor
  void setParent(Node* parent);
  void setLeftChild(Node* child);
  void setRightChild(Node* child);
  void setColor(Color color);
  int getValue() const;
  Node* getParent() const;
  Node* getLeftChild() const;
  Node* getRightChild() const;
  Color getColor() const;
};

class RedBlackTree {
 private:
  Node* root;   // root of the tree
  Node* TNULL;  // Sentinel NIL node
  int height;   // height of the tree
  int count;    // number of elements in the tree

  void destructorHelper(Node* node);
  void rotateLeft(Node* node);
  void rotateRight(Node* node);
  void insertionFixHelper(Node* node);  // restore tree after insertion
  void deletionFixHelper(Node* node);   // restore tree after deletion
  void transplant(Node* u, Node* v);    // replaces the subtree rooted at node u
                                        // by the subtree rooted at node v
  int countNodes(Node* node) const;     // counts all the nodes in the tree

  void inorderHelper(Node* node) const;
  void preorderHelper(Node* node) const;
  void postorderHelper(Node* node) const;
  int getHeightHelper(Node* node) const;
  bool isFullHelper(Node* node) const;
  void printHelper(Node* node, int indent) const;
  Node* search(
      int value) const;  // search for node that contains a specific value
  Node* minimum(Node* node) const;  // search for the minimum node
  Node* maximum(Node* node) const;  // search for the maximum node
  Node* copyHelper(Node* node, Node* parent, Node* TNULL_copy);

 public:
  RedBlackTree();                                    // constructor
  ~RedBlackTree();                                   // destructor
  RedBlackTree(const RedBlackTree& rbt);             // copy constructor
  RedBlackTree& operator=(const RedBlackTree& rbt);  // assignment operator

  void insert(int data);  // insert new data
  void remove(int data);  // remove data
  int getRoot() const;    // get root value
  int size() const;       // return the current number of elements
  bool isEmpty() const;   // check if the tree is empty
  bool isFullTree()
      const;  // check if every internal node has zero or two children
  int getHeight() const;            // returns the height of the tree
  void clear();                     // clears the tree
  void inorderTraversal() const;    // print out tree in inorder
  void preorderTraversal() const;   // print out tree in preorder
  void postorderTraversal() const;  // print out tree in postorder
  void printTree() const;           // print out tree in BST format
  bool isInTree(int number) const;  // check if a boolean is in the Tree
  int getMinimum() const;           // get the maximum value
  int getMaximum() const;          // get the maximum value
  };