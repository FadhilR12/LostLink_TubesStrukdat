#include <iostream>
#include "lostLink.h"

using namespace std;

void createTree (adrNode &root){
    root = nullptr;
}

adrNode createNode (infotype x){
    adrNode p =new Node;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

void insertNode (adrNode &root, adrNode p){
    if (root == nullptr){
        root = p;
    } else {
        if (p->info.id < root->info.id){
            insertNode(root->left, p);
        } else {
            insertNode(root->right, p);
        }
    }
}

void preorder(adrNode root);
void inorder(adrNode root);
void postorder(adrNode root);
void bfs(adrNode root);
void showByCategory(adrNode root);
adrNode searchID(adrNode root, int id);
adrNode searchByName(adrNode root, string name);
void updateNode(adrNode &root, int id);
void deleteNode(adrNode &root, int id);

