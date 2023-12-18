// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <iostream>
using namespace std;

struct Binary_Tree_Node {
  int data;
  Binary_Tree_Node *left;
  Binary_Tree_Node *right;
};

/************** begin assignment **************/
// Implement a function to check if a binary tree is a binary search tree (BST).
// A binary search tree satisfies the condition:
// left->data <= current->data < right->data.
// More precisely, the condition is that all left nodes must be less than or
// equal to the current node, which must be less than all the right nodes.
//
// Let's state again clearly the properties for a binary search tree:
// - The left subtree of a node contains only nodes with keys lesser than the
//   node's key.
// - The right subtree of a node contains only nodes with keys greater than the
//   node's key.
// - The left and right subtree each must also be a binary search tree.
//
// Be careful with duplicate values:
//    20                  20
//   /    valid BST         \    invalid BST
// 20                       20
//
// Optimal: O(n) time, if binary tree is balanced O(log n) space,
// worst case O(n) space
// --> It's challenging to do it optimal although there is not much code ...
// Try to solve it somehow.
//
// Before you start coding the function "is_binary_search_tree", write test
// cases in the main function to test the "is_binary_search_tree" function.
// Start with simple tests (like nullptr, one node, two nodes, three nodes)
// before writing more complicated tests.
// The style of writing tests before actual coding is called "Test-driven
// development" (TDD). You have indirectly familiarized yourself with it in the
// first exercises of this course, now you can try TDD yourself.
// (If you need an idea how to start writing tests, take a look at the main
// function in "is_symmetric.cpp".)

// write a helper function if you need to
// TODO: write code here
bool isBinary=true;
int counter=0;
void inorderTraversal(Binary_Tree_Node *node)
{
    if(node==nullptr) return;

    if(node->left!=nullptr&&node->left->data>node->data) {isBinary=false;return;}
    if(node->right!=nullptr&&node->right->data<=node->data) {isBinary=false;return;}
    inorderTraversal(node->left);
    inorderTraversal(node->right);
}
bool is_binary_search_tree(Binary_Tree_Node *node) {
  isBinary=true;
  inorderTraversal(node);
  return isBinary;
}

int main() {
     {
    Binary_Tree_Node *tree=nullptr;
    assert(is_binary_search_tree(tree));
    }
     {
    Binary_Tree_Node root {1,nullptr,nullptr};
    assert(is_binary_search_tree(&root));
    }
     {
     Binary_Tree_Node node1{1,nullptr,nullptr};
    Binary_Tree_Node root {1,&node1,nullptr};
    assert(is_binary_search_tree(&root));
    }
    {
     Binary_Tree_Node node1{2,nullptr,nullptr};
    Binary_Tree_Node root {1,nullptr,&node1};
    assert(is_binary_search_tree(&root));
    }
    {
     Binary_Tree_Node node1{1,nullptr,nullptr};
    Binary_Tree_Node root {1,nullptr,&node1};
    assert(!is_binary_search_tree(&root));
    }
    {
     Binary_Tree_Node node2{1,nullptr,nullptr};
     Binary_Tree_Node node1{3,nullptr,nullptr};
    Binary_Tree_Node root {2,&node2,&node1};
    assert(is_binary_search_tree(&root));
    }
    {
   
    Binary_Tree_Node node3{1,nullptr,nullptr};
    Binary_Tree_Node node4{3,nullptr,nullptr};
     Binary_Tree_Node node5{6,nullptr,nullptr};
      Binary_Tree_Node node1{2,&node3,&node4};
    Binary_Tree_Node node2{7,&node5,nullptr};
    Binary_Tree_Node root {4,&node1,&node2};
    assert(is_binary_search_tree(&root));
    }
    cout<<"all tests passed"<<endl;
}
/*************** end assignment ***************/
