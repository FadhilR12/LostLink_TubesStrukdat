#include <iostream>
#include "lostLink.h"
#include <queue>

using namespace std;

void createTree(adrNode &root)
{
    root = nullptr;
}

adrNode createNode(infotype x)
{
    adrNode p = new Node;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

void insertNode(adrNode &root, adrNode p)
{
    if (root == nullptr)
    {
        root = p;
    }
    else
    {
        if (p->info.id < root->info.id)
        {
            insertNode(root->left, p);
        }
        else
        {
            insertNode(root->right, p);
        }
    }
}

void inorder(adrNode root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << "ID: " << root->info.id << "|"
            << ", Item: " << root->info.nama << "|"
            << ", Kategori: " << root->info.kategori << "|"
            << ", Lokasi: " << root->info.lokasi << "|"
            << endl;
        inorder(root->right);
    }
}

void showByCategory(adrNode root, int minID, int maxID)
{
    if (root == nullptr)
        return;

    showByCategory(root->left, minID, maxID);

    if (root->info.id >= minID && root->info.id <= maxID)
    {
        cout << "ID: " << root->info.id
             << " | Item: " << root->info.nama
             << " | Lokasi: " << root->info.lokasi
             << endl;
    }

    showByCategory(root->right, minID, maxID);
}

adrNode searchID(adrNode root, int id)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->info.id == id)
    {
        return root;
    }
    else if (id < root->info.id)
    {
        return searchID(root->left, id);
    }
    else
    {
        return searchID(root->right, id);
    }
}

adrNode searchByName(adrNode root, string name) {
    if (root == nullptr) return nullptr;

    queue<adrNode> q;
    q.push(root);

    while (!q.empty()) {
        adrNode current = q.front();
        q.pop();
        if (current->info.nama == name) {
            return current;
        }
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }

    return nullptr;
}

void updateNode(adrNode &root, int id)
{
    adrNode target = searchID(root, id);
    if (target != nullptr)
    {
        cout << "Masukkan Item baru: ";
        cin >> target->info.nama;
        cout << "Masukkan lokasi baru: ";
        cin >> target->info.lokasi;
        cout << "Data berhasil diperbarui." << endl;
        cout << endl;
    }
    else
    {
        cout << "Item dengan ID " << id << " tidak ditemukan." << endl << endl;
    }
}
adrNode minValueNode(adrNode root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}
void deleteNode(adrNode &root, int id)
{
    if (root == nullptr)
    {
        return;
    }
    if (id < root->info.id)
    {
        deleteNode(root->left, id);
    }
    else if (id > root->info.id)
    {
        deleteNode(root->right, id);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            adrNode temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            adrNode temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            adrNode temp = minValueNode(root->right);
            root->info = temp->info;
            deleteNode(root->right, temp->info.id);
        }
    }
}
void main_menu(){
    cout << "=========== LostLink ===========" << endl;
    cout << "1. Tambahkan Item" << endl;
    cout << "2. Lihat Semua Item" << endl;
    cout << "3. Cari Item" << endl;
    cout << "4. Update Item" << endl;
    cout << "5. Hapus Item" << endl;
    cout << "6. Lihat Item Berdasarkan Kategori" << endl;
    cout << "7. Keluar" << endl;
    cout << "Select an option (1-7): ";
}

infotype menuTambahItem(){
    infotype x;
    cout << "=========== Tambah Item Baru ===========" << endl;
    cout << "Masukkan ID Item: ";
    cin >> x.id;
    cout << "Masukkan Nama Item: ";
    cin >> x.nama;
    cout << "Masukkan Lokasi Item: ";
    cin >> x.lokasi;
    if (x.id <= 100) {
        x.kategori = "Elektronik";
    } else if (x.id <= 200) {
        x.kategori = "Pakaian";
    } else if (x.id <= 300) {
        x.kategori = "Makanan";
    } else if (x.id <= 400) {
        x.kategori = "Buku";
    } else {
        x.kategori = "Lainnya";
    }
    cout << "Item berhasil ditambahkan!" << endl;
    return x;
}

void menuCariItem(){
    cout << "=========== Cari Item ===========" << endl;
    cout << "1. Cari berdasarkan ID" << endl;
    cout << "2. Cari berdasarkan Nama" << endl;
    cout << "3. Kembali ke menu utama" << endl;
    cout << "Select an option (1-3): ";
}

void menuLihatKategori(){
    cout << "=========== Lihat Item Berdasarkan Kategori ===========" << endl;
    cout << "1. Elektronik" << endl;
    cout << "2. Pakaian" << endl;
    cout << "3. Makanan" << endl;
    cout << "4. Buku" << endl;
    cout << "5. Lainnya" << endl;
    cout << "6. Kembali ke menu utama" << endl;
    cout << "Select an option (1-6): ";
}


