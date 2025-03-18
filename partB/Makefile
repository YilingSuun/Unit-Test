CXX=g++
CXXFLAGS = -std=c++17 -g
DEP_DIR= ../dependencies

all: redblacktree_unittest redblacktree

redblacktree: redblacktree.o main.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib redblacktree.o main.cc -o $@

redblacktree_unittest: redblacktree.o redblacktree_unittest.cc
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -Iinclude -L$(DEP_DIR)/lib redblacktree_unittest.cc redblacktree.o -lgtest_main -lgtest -lgmock -pthread -o $@

clean:
	rm -f redblacktree_unittest redblacktree
