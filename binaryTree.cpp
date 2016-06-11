#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
struct node {
  T element;
  node* left;
  node* right;
};

template <class T>
class binaryTree {
private:
  node<T>* root;

public:
  binaryTree();
  void inOrder();
  void inOrder(node<T>* root);
  void preOrder();
  void preOrder(node<T>* root);
  void postOrder();
  void postOrder(node<T>* root);
  void levelOrder();
  void depthFirstTraversal();
  void breadthFirstTraversal();
  void DFS();
  void BFS();
  node<T>* getRoot();
};

template <class T>
binaryTree<T>::binaryTree() {
  this->root = new node<T>();
  /*this->root = new node<T>();
  this->root->element = 5;
  this->root->left = new node<T>();
  this->root->right = new node<T>();
  this->root->left->element = 3;
  this->root->right->element = 8;
  this->root->left->right = new node<T>();
  this->root->left->right->element = 7;
  */
}

template <class T>
void binaryTree<T>::inOrder() {
  inOrder(this->root);
}

template <class T>
void binaryTree<T>::inOrder(node<T>* root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  cout << root->element;
  inOrder(root->right);
}

template <class T>
void binaryTree<T>::preOrder() {
  preOrder(this->root);
}

template <class T>
void binaryTree<T>::preOrder(node<T>* root) {
  if (root == NULL)
    return;

  cout << root->element;
  preOrder(root->left);
  preOrder(root->right);

}

template <class T>
void binaryTree<T>::postOrder() {
  postOrder(this->root);
}

template <class T>
void binaryTree<T>::postOrder(node<T>* root) {
  if (root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->element;

}
template <class T>
node<T>* binaryTree<T>::getRoot() {
  return this->root;
}

int main() {
  /*binaryTree<int> bt = binaryTree<int>();
  node<int>* n = bt.getRoot();
  n->element = 1;
  n->left = new node<int>();
  n->left->element = 2;
  n->right = new node<int>();
  n->right->element = 3;
  n->left->right = new node<int>();
  n->left->right->element = 2;

  //bt.inOrder();
  //bt.preOrder();
  //bt.postOrder();
  */
  return 0;
}
