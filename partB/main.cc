#include <iostream>

#include "redblacktree.h"

using namespace std;

int main() {
  RedBlackTree* tree = new RedBlackTree();

  tree->insert(10);
  tree->insert(20);
  tree->insert(30);

  tree->printTree();
  return 0;
}