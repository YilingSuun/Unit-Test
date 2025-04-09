#include <iostream>

#include "redblacktree.h"

using namespace std;

int main() {
  RedBlackTree* tree = new RedBlackTree();
  tree->clear();

  tree->insert(1);
  tree->insert(1);
  tree->insert(1);
  tree->insert(1);
  tree->insert(1);

  tree->printTree();
  tree->inorderTraversal();

  return 0;
}