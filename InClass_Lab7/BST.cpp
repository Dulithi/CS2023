#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a new node
struct node* createNode(int data) {
  struct node* newNode = new struct node;
  newNode->key = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode; 
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  // check if the BST is empty
  if(root == NULL) {
    return;
  }

  // traverse the left tree
  traverseInOrder(root->left);

  // print the key
  cout << root->key << " ";

  // traverse the right tree
  traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  // create new node if the tree is empty
  if(node == NULL) {
    return createNode(key);
  }

  // recurse down the left sub tree
  if(key <= node->key) {
    node->left = insertNode(node->left, key);
  }
  // recurse down the right sub tree
  else if(key > node->key) {
    node->right = insertNode(node->right, key);
  }

  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

  // check if the tree is empty
  if(root == NULL) {
    return root;
  }

  // finding node to be deleted
  if(key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  else if(key > root->key) {
    root->right = deleteNode(root->right, key);
  }

  else {
    // when node has no children, remove the linkto parent
    if (root->right == NULL && root->left == NULL){
      delete(root);
      return NULL;
    }
    // when  the node has only one child, replace link with link to the child
    else if(root->right == NULL) {
      struct node* temp = root->left;
      delete(root);
      return temp;
    } 
    else if(root->left == NULL) {
      struct node* temp = root->right;
      delete(root);
      return temp;
    }

    // if the node has 2 children, find min in right sub tree, copy its key in targeted node, delete duplicate. 
    struct node* minNode = root->right;
    while(minNode->left != NULL){
      minNode = minNode->left;
    }
    root->key = minNode->key;
    root->right = deleteNode(root->right, minNode->key); 
  } 
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}