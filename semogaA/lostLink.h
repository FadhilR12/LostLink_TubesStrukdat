#ifndef LOSTLINK_H_INCLUDED
#define LOSTLINK_H_INCLUDED
#include <iostream>

using namespace std;

struct item {
    int id;
    string nama;
    int kategori;
    string lokasi;
};

typedef item infotype;
typedef struct Node *adrNode;

struct Node{
    infotype info;
    adrNode left;
    adrNode right;
};

void createTree (adrNode &root);
adrNode createNode (infotype x);
void insertNode (adrNode &root, adrNode p);
void preorder(adrNode root);
void inorder(adrNode root);
void postorder(adrNode root);
void bfs(adrNode root);
void showByCategory(adrNode root, int minID, int maxID);
adrNode searchID(adrNode root, int id);
adrNode searchByName(adrNode root, string name);
void updateNode(adrNode &root, int id);
void deleteNode(adrNode &root, int id);
adrNode minValueNode(adrNode root);

#endif // LOSTLINK_H_INCLUDED
