
#include <string>
#include <iostream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(){
  root = NULL;

}
BinarySearchTree::~BinarySearchTree(){
  delete root;
}
//constructors
void BinarySearchTree::insert(const string& x){
  if(root == NULL){
    root = new BinaryNode(x);
      return;
      }
  
  BinaryNode* parent = seek(root, x);

  int c = (parent->value).compare(x);

  if(c < 0){
    parent->left = new BinaryNode(x);
    nodes++;
  }
  if(c > 0){
    parent->right = new BinaryNode(x);
    nodes++;
  }
  
}
//inserts a node with string value x into the tree at the proper location
void BinarySearchTree::remove(const string& x){
  if(find(x)){
   
    BinaryNode* rip = seek(root, x);
    BinaryNode* parent = remove(root, x);
  
    if(rip->right == NULL && rip->left == NULL){;
      //leaf node to be removed
      if(rip == root){

	root = NULL;
	return;

      }
      if(parent->left == rip)
	parent->left = NULL;
      else
	parent->right = NULL;
      
      return;
    }

    if(rip->left == NULL || rip->right == NULL){
      //node with one child to be removed
      if(rip == root){
	if(root->right != NULL)
	  root = root->right;
	else
	  root = root->left;

      }

      if(rip->left == NULL)
	if(parent->left == rip)
	  parent->left = rip->right;
	else
	  parent->right = rip->right;
      else
	if(parent->left == rip)
	  parent->left = rip->left;
	else
	  parent->right = rip->left;

      return;
    }

    if(rip->left != NULL && rip->right != NULL){
      //node with two children to be removed
      string s = min(rip->right);
      remove(s);
      
      rip->value = s;
      //replaces rip with the smallest value in it's right subtree

    }

  }
}
//removes a node with value of string x from the tree
void BinarySearchTree::printTree(){

}
string BinarySearchTree::pathTo(const string& x){
   string route = "";
  if(find(x)){
    BinaryNode* curr = root;
    if(curr->value == x)
      return x;
    while(x != curr->value){

      if((curr->value).compare(x) < 0){
	route = route+curr->value+" ";
	curr = curr->left;
      }else{
	route = route+curr->value+" ";
	curr = curr->right;
      } 
    }
    route = route + curr->value;

  }
  return route;
}
//returns a string of the path to a node with string value x
bool BinarySearchTree::find(const string& x){

  BinaryNode* parent = seek(root, x);
  int c = x.compare(parent->value);
  if(c == 0){
    return true;
  }
  else
    return false;

}
//a boolean function that returns whether or not the given node with value string x exists in the tree
int BinarySearchTree::numNodes() const{
  return nodes;
}
//returns the size of the tree
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x){
  //this should return the parent node of 
  int c = x.compare(n->value);
  int c1;
  int c2;
  if(n->right != NULL)
    c1 = x.compare(n->right->value);

  if(n->left != NULL)
    c2 = x.compare(n->left->value);

  if(c1 == 0 || c2 == 0)
    return n;
  if(c > 0)
    if(n->left != NULL)
      return remove(n->left, x);
    else
      return NULL;
  else
    if(n->right != NULL)
      return remove(n->right, x);
    else
      return NULL;
}
//recursive helper function for the remove function
string BinarySearchTree::min(BinaryNode* node) const{
  if(node->left != NULL)
    return min(node->left);
  else
    return node->value;

}
//recursive helper function that finds the minimum value in a subtree.

void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft){

  //STUB

}
//didn't need this helper function for printing the tree.  Left it for posterity

BinaryNode* BinarySearchTree::seek(BinaryNode*& node, const string& x) const{
  //the one in the parentheses is lower if the number is negative
  int c = x.compare(node->value);
  if(c == 0)
    return node;
  if(c > 0)
    if(node->left != NULL)
      return seek(node->left, x);
    else
      return node;
  else
    if(node->right != NULL)
      return seek(node->right, x);
    else
      return node;
}
/*
returns the node which is the root of the node where the string should be inserted, or if the value is the same it returns the node
*/
