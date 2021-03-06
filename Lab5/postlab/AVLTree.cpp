//Jared Hawkins jmh7ax 3/29/2021

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    root = new AVLNode();
    root -> value = x;
  }
  else{
    insert(root, x);
  }
}

void AVLTree :: insert(AVLNode*& node, const string& x){
  if(node == NULL){
    node = new AVLNode();
    node -> value = x;
  }
  else if(x < node -> value){
    insert(node -> left, x);
  }
  else if(x > node -> value){
    insert(node -> right, x);
  }
  else{
    ;
  }
  node -> height = 1 + max(height(node -> left), height(node -> right)); 
  balance(node);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return pathTo(x, root);
}

string AVLTree :: pathTo(const string& x, AVLNode* node) const {
  if(find(x)){
    if(node == NULL){
      return "";
    }
    if(x < node -> value){
       return node -> value + " " + pathTo(x, node -> left);
    }
    else if(x > node -> value){
       return node -> value + " " + pathTo(x, node -> right);
    }
    else{
      return node -> value;
    }
  }
 return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree :: find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
 string found = find(root, x);
  if(found == x) {
    return true;
  }
  else {
    return false;
  }
}

string AVLTree :: find(AVLNode* node, const string& x) const{
  if(node == NULL) {
    return "";
  }
  if(x == node -> value) {
    return node->value;
  }
  else if(x < node -> value) {
    return find(node -> left, x);
  }
  else if(x > node -> value) {
    return find(node -> right, x);
  }
  return "";
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

int AVLTree :: numNodes(AVLNode* node) const{
 if(node == NULL){
    return 0;
  }
  return 1 + numNodes(node -> left) + numNodes(node -> right);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  int bal = height(n -> right) - height(n -> left);
  if(bal == 2) {
    if(height((n -> right) -> right) - height((n -> right) -> left) < 0) {
      rotateRight(n -> right);  
    }
    rotateLeft(n);
  }
  else if(bal == -2) { 
    if(height((n -> left) -> right) - height((n -> left) -> left) > 0) {
      rotateLeft(n -> left);
    }
    rotateRight(n);
  }
  else{
    ;
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* temp = n;
  AVLNode* tempRL = n -> right -> left;

  n = n -> right;
  n -> left = temp;
  n -> left -> right = tempRL;

  (n -> left) -> height = 1 + max(height((n -> left) -> left), height((n -> left) -> right)); 
  n -> height = 1 + max(height(n -> left), height(n -> right));
  
  return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* temp = n;
  AVLNode* tempLR = n -> left -> right;

  n = n -> left;
  n -> right = temp;
  n -> right -> left = tempLR;

  (n -> right) -> height = 1 + max(height((n -> right) -> left), height((n -> right) -> right)); 
  n -> height = 1 + max(height(n -> left), height(n -> right));
  
  return n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
