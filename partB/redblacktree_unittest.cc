#include "gtest/gtest.h"
#include "redblacktree.h"

class RedBlackTreeTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}

 protected:
  RedBlackTree tree;
};

TEST(RedBlackTreeTests, CopyConstructorTests) {
  RedBlackTree tree;
  RedBlackTree empty_copy(tree);
  EXPECT_EQ(empty_copy.isEmpty(), true);
  EXPECT_EQ(empty_copy.size(), 0);

  tree.insert(10);
  tree.insert(5);
  tree.insert(15);

  RedBlackTree copy(tree);

  EXPECT_EQ(copy.size(), tree.size());
  EXPECT_EQ(copy.isInTree(10), true);
  EXPECT_EQ(copy.isInTree(5), true);
  EXPECT_EQ(copy.isInTree(15), true);

  tree.remove(10);
  EXPECT_EQ(copy.isInTree(10), true);
}

TEST(RedBlackTreeTests, OperatorEqualTests) {
  RedBlackTree tree1;
  tree1.insert(1);
  tree1.insert(2);
  tree1 = tree1;
  EXPECT_TRUE(tree1.isInTree(1));
  EXPECT_TRUE(tree1.isInTree(2));

  tree1.insert(3);

  RedBlackTree tree2;
  tree2.insert(100);

  tree2 = tree1;

  EXPECT_EQ(tree2.size(), tree1.size());
  EXPECT_TRUE(tree2.isInTree(1));
  EXPECT_TRUE(tree2.isInTree(2));
  EXPECT_TRUE(tree2.isInTree(3));

  tree1.remove(1);
  EXPECT_TRUE(tree2.isInTree(1));
}


TEST_F(RedBlackTreeTest, InsertTests) {
  tree.insert(23);
  tree.insert(46);
  tree.insert(-3);
  EXPECT_EQ(tree.isInTree(23), true);
  EXPECT_EQ(tree.isInTree(-3), true);
}

TEST_F(RedBlackTreeTest, RemoveTests) {
  tree.insert(70);
  tree.remove(70); //remove the root
  EXPECT_EQ(tree.size(), 0);

  tree.insert(30);
  tree.insert(-90);
  tree.insert(10);
  tree.insert(20);
  EXPECT_EQ(tree.size(), 4);
  tree.remove(999);
  EXPECT_EQ(tree.size(), 4);
  tree.remove(10);
  EXPECT_EQ(tree.size(), 3);
  EXPECT_EQ(tree.isInTree(10), false);
  tree.remove(-90);
  EXPECT_EQ(tree.size(), 2);
  EXPECT_EQ(tree.isInTree(-90), false);
  tree.remove(-90);
  EXPECT_EQ(tree.size(), 2);
  EXPECT_EQ(tree.isInTree(-90), false);
}

TEST_F(RedBlackTreeTest, GetRootTests) {
  EXPECT_EQ(tree.getRoot(), 0);
  tree.insert(-1);
  EXPECT_EQ(tree.getRoot(), -1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  EXPECT_EQ(tree.getRoot(), 2);
  tree.clear();
  EXPECT_EQ(tree.getRoot(), 0);
}

TEST_F(RedBlackTreeTest, SizeTests) {
  EXPECT_EQ(tree.size(), 0);
  tree.insert(23);
  tree.insert(46);
  tree.insert(3);
  EXPECT_EQ(tree.size(), 3);
  tree.insert(23);
  tree.insert(23);
  EXPECT_EQ(tree.size(), 5);
}

TEST_F(RedBlackTreeTest, IsEmptyTests) {
  EXPECT_EQ(tree.isEmpty(), true);
  tree.insert(23);
  tree.insert(46);
  tree.insert(3);
  EXPECT_EQ(tree.isEmpty(), false);
}

TEST_F(RedBlackTreeTest, IsFullTreeTests) {
  EXPECT_EQ(tree.isFullTree(), true);
  tree.insert(1);
  tree.insert(5);
  tree.insert(50);
  EXPECT_EQ(tree.isFullTree(), true);
  tree.insert(15);
  EXPECT_EQ(tree.isFullTree(), false);
}

TEST_F(RedBlackTreeTest, GetHeightTests) {
  int height1 = tree.getHeight();
  tree.insert(100);
  tree.insert(200);
  tree.insert(300);
  tree.insert(400);
  tree.insert(500);
  int height2 = tree.getHeight();

  EXPECT_EQ(height1, 0);
  EXPECT_EQ(height2, 3);
}

TEST_F(RedBlackTreeTest, ClearTests) {
  tree.clear();
  EXPECT_EQ(tree.isEmpty(), true);

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  EXPECT_EQ(tree.isEmpty(), false);
  tree.clear();
  EXPECT_EQ(tree.isEmpty(), true);
  EXPECT_EQ(tree.size(), 0);
}

TEST_F(RedBlackTreeTest, InorderTraversalTests) {
  testing::internal::CaptureStdout();
  tree.inorderTraversal();
  std::string output0 = testing::internal::GetCapturedStdout();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);

  testing::internal::CaptureStdout();
  tree.inorderTraversal();
  std::string output1 = testing::internal::GetCapturedStdout();

  //negative case
  tree.clear();
  tree.insert(1);
  tree.insert(2);
  tree.insert(-3);
  tree.insert(4);
  tree.insert(5);
  testing::internal::CaptureStdout();
  tree.inorderTraversal();
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output0, "\n");
  EXPECT_EQ(output1, "1B 2B 3R 4B 5R \n");
  EXPECT_EQ(output2, "-3B 1B 2R 4B 5R \n");
}

TEST_F(RedBlackTreeTest, PreorderTraversalTests) {
  testing::internal::CaptureStdout();
  tree.preorderTraversal();
  std::string output0 = testing::internal::GetCapturedStdout();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);

  testing::internal::CaptureStdout();
  tree.preorderTraversal();
  std::string output1 = testing::internal::GetCapturedStdout();

  //negative case
  tree.clear();
  tree.insert(1);
  tree.insert(2);
  tree.insert(-3);
  tree.insert(4);
  tree.insert(5);
  testing::internal::CaptureStdout();
  tree.preorderTraversal();
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output0, "\n");
  EXPECT_EQ(output1, "2B 1B 4B 3R 5R \n");
  EXPECT_EQ(output2, "1B -3B 4B 2R 5R \n");
}

TEST_F(RedBlackTreeTest, PostorderTraversalTests) {
  testing::internal::CaptureStdout();
  tree.postorderTraversal();
  std::string output0 = testing::internal::GetCapturedStdout();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);

  testing::internal::CaptureStdout();
  tree.postorderTraversal();
  std::string output1 = testing::internal::GetCapturedStdout();
  //negative case
  tree.clear();
  tree.insert(1);
  tree.insert(2);
  tree.insert(-3);
  tree.insert(4);
  tree.insert(5);
  testing::internal::CaptureStdout();
  tree.postorderTraversal();
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output0, "\n");
  EXPECT_EQ(output1, "1B 3R 5R 4B 2B \n");
  EXPECT_EQ(output2, "-3B 2R 5R 4B 1B \n");
}

TEST_F(RedBlackTreeTest, PrintTreeTests) {
  testing::internal::CaptureStdout();
  tree.printTree();
  std::string output1 = testing::internal::GetCapturedStdout();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);

  testing::internal::CaptureStdout();
  tree.printTree();
  std::string output2 = testing::internal::GetCapturedStdout();

  //negative case
  tree.clear();
  tree.insert(1);
  tree.insert(2);
  tree.insert(-3);
  tree.insert(4);
  tree.insert(5);
  testing::internal::CaptureStdout();
  tree.printTree();
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "Tree is empty!\n");
  EXPECT_EQ(output2, "        Red(5)\n    Black(4)\n        Red(3)\nBlack(2)\n    Black(1)\n");
  EXPECT_EQ(output3, "        Red(5)\n    Black(4)\n        Red(2)\nBlack(1)\n    Black(-3)\n");
}

TEST_F(RedBlackTreeTest, InTreeTests) {
  EXPECT_FALSE(tree.isInTree(0));

  tree.insert(10);
  tree.insert(-20);
  EXPECT_EQ(tree.isInTree(10), true);
  EXPECT_EQ(tree.isInTree(-20), true);
  EXPECT_EQ(tree.isInTree(3), false);
}

TEST_F(RedBlackTreeTest, MinMaxTests) {
  EXPECT_THROW(tree.getMinimum(), std::runtime_error);
  EXPECT_THROW(tree.getMaximum(), std::runtime_error);

  tree.insert(40);
  EXPECT_EQ(tree.getMinimum(), 40);
  EXPECT_EQ(tree.getMaximum(), 40);

  tree.insert(10);
  tree.insert(30);
  tree.insert(-70);
  tree.insert(0);
  EXPECT_EQ(tree.getMinimum(), -70);
  EXPECT_EQ(tree.getMaximum(), 40);

  tree.insert(2147483647);
  tree.insert(-2147483648);
  EXPECT_TRUE(tree.isInTree(2147483647));
  EXPECT_TRUE(tree.isInTree(-2147483648));
}

TEST_F(RedBlackTreeTest, LargeScaleInsertDeleteTest) {
  for (int i = 0; i < 1000; ++i) {
    tree.insert(i);
  }
  EXPECT_EQ(tree.size(), 1000);

  for (int i = 0; i < 1000; ++i) {
    EXPECT_TRUE(tree.isInTree(i));
  }

  for (int i = 0; i < 500; ++i) {
    tree.remove(i);
  }
  EXPECT_EQ(tree.size(), 500);
}

TEST_F(RedBlackTreeTest, ConsistencyTest) {
  tree.insert(10);
  tree.insert(20);
  tree.remove(10);
  tree.insert(10);
  tree.remove(20);
  tree.insert(30);
  tree.remove(30);

  EXPECT_TRUE(tree.isInTree(10));
  EXPECT_FALSE(tree.isInTree(20));
  EXPECT_FALSE(tree.isInTree(30));
  EXPECT_EQ(tree.size(), 1);
}

TEST_F(RedBlackTreeTest, BalancedHeightTest) {
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);
  EXPECT_EQ(tree.getHeight(), 2);
}
