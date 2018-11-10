#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode(){
  left = NULL;
  right = NULL;
  value = "?";
  
}
BinaryNode::BinaryNode(const string& val){
  left = NULL;
  right = NULL;
  value = val;
}
//binary node constructor with value
BinaryNode::~BinaryNode(){

  delete right;
  delete left;
  delete this;
  
}
//recursive deletion function
