
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
      
      //delete rip;
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
bool BinarySearchTree::find(const string& x){

  BinaryNode* parent = seek(root, x);
  int c = x.compare(parent->value);
  if(c == 0){
    return true;
  }
  else
    return false;

}
int BinarySearchTree::numNodes() const{
  return nodes;
}
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
string BinarySearchTree::min(BinaryNode* node) const{
  if(node->left != NULL)
    return min(node->left);
  else
    return node->value;

}
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft){

  

}
//returns the node which is the root of the node where the string should
//be inserted, or if the value is the same it returns the node
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
