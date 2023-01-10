#include <stdio.h>
#include <stdlib.h>
/*
       1
    2     3
  4  5          ağaç yapısı
*/  
struct node {
  int veri;
  struct node* sol;
  struct node* sag;
};

void inorderTraversal(struct node* root) { //SOL KÖK SAĞ
  if (root == NULL) return;
  inorderTraversal(root->sol);
  printf("%d ->", root->veri);
  inorderTraversal(root->sag);
}

void preorderTraversal(struct node* root) { //KÖK SOL SAĞ
  if (root == NULL) return;
  printf("%d ->", root->veri);
  preorderTraversal(root->sol);
  preorderTraversal(root->sag);
}

void postorderTraversal(struct node* root) { //SOL SAĞ KÖK
  if (root == NULL) return;
  postorderTraversal(root->sol);
  postorderTraversal(root->sag);
  printf("%d ->", root->veri);
}

struct node* createNode(int data) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->veri = data;
  newNode->sol = NULL;
  newNode->sag = NULL;
  return newNode;
}

struct node* insertSol(struct node* root, int data) {
  root->sol = createNode(data);
  return root->sol;
}

struct node* insertSag(struct node* root, int data) {
  root->sag = createNode(data);
  return root->sag;
}

int main() {
  struct node* root = createNode(1);
  insertSol(root, 2);       //root'un solu
  insertSag(root, 3);       //root'un sağı
  insertSol(root->sol, 4);  //root'un solunun solu
  insertSag(root->sol, 5);  //root'un solunun sağı

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}