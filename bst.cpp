// #include "function.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
extern ofstream fileOut;
BikePtr _BST::search(LicenseType License)
{
  if(root == NULL) return NULL;
  _node *cur = root;
  while(1) {
    if(cur->bike->License == License)
      return cur->bike;
    else if(cur->bike->License < License) {
      if(cur -> right != NULL)
        cur = cur -> right;
      else
        return NULL;
    } else {
      if(cur -> left != NULL)
        cur = cur -> left;
      else
        return NULL;
    }

  }

}

void _BST::ins(BikePtr bike)
{
  if(root == NULL) {
    root = new _node();
    root->bike = bike;
    return;
  }
  _node *cur = root;
  while(1) {
    if(cur->bike->License == bike->License)
      return;
    else if(cur->bike->License < bike->License) {
      if(cur -> right != NULL)
        cur = cur -> right;
      else
        break;
    } else {
      if(cur -> left != NULL)
        cur = cur -> left;
      else
        break;
    }
  }
  if(cur->bike->License < bike->License) {
      cur -> right = new _node();
      cur -> right -> bike = bike;
  } else {
    cur -> left = new _node();
    cur -> left -> bike = bike;
  }

}

void _BST::del(BikePtr bike)
{
  if(root == NULL) return;
  int l = -1;
  _node *cur = root, *p = NULL;
  while(1) {
    if(cur->bike->License == bike->License)
      break;
    else if(cur->bike->License < bike->License) {
      if(cur -> right != NULL){
        p = cur;
        l = 0;
        cur = cur -> right;
      } else
        return; // find no
    } else {
      if(cur -> left != NULL){
        p = cur;
        l = 1;
        cur = cur -> left;
      } else
        return; // find no
    }
  }
  if(cur == root) {
    root = NULL;
    delete cur;
    return;
  }
  if(cur -> left == NULL && cur -> right == NULL) {
    if(cur == root) {
      root = NULL;
    } else {
      if(l) p -> left  = NULL;
      else  p -> right = NULL;
    }
    delete cur;
    return;
  } else if( cur -> left == NULL && cur -> right != NULL) {
    if(l) p -> left = cur -> right;
    else  p -> right = cur -> right;
    delete cur;
  } else {
    // cur -> left != NULL
    // Replace with the left child which has the largest value case
    _node *temp = cur -> left, *prev = NULL;
    while(1){
      if(temp -> right != NULL) { prev = temp; temp = temp -> right; }
      else break;
    }
    if(prev != NULL) {
      prev -> right = NULL;
      temp -> right = cur -> right;
      temp -> left = cur -> left;
    } else {
      temp -> right = cur -> right;
    }

    if(l) p -> left = temp;
    else  p -> right = temp;
    delete cur;
  }

}
void _BST::show(_node *n)
{
  if(n == NULL) return;
  _node *cur = n;
  this->show(n->left);
  std::cout << n->bike->License << " ";
  this->show(n->right);
}
