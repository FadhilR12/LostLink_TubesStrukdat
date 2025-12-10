#include <iostream>
#include "lostLink.h"
using namespace std;

adrNode root = nullptr;
infotype x;
string nama, lokasi;
int id, kategori;

void main_menu(){
    cout << "=========== LostLink ===========" << endl;
    cout << "1. Tambahkan Item" << endl;
    cout << "2. Lihat Semua Item" << endl;
    cout << "3. Cari Item" << endl;
    cout << "4. Update Item" << endl;
    cout << "5. Hapus Item" << endl;
    cout << "6. Lihat Items Berdasarkan Kategori" << endl;
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
    if (id <= 100) {
        x.kategori = 1; // Elektronik
    } else if (id <= 200) {
        x.kategori = 2; // Pakaian
    } else if (id <= 300) {
        x.kategori = 3; // Makanan
    } else if (id <= 400) {
        x.kategori = 4; // Buku
    } else {
        x.kategori = 5; // Lainnya
    }
    cout << "Item berhasil ditambahkan!" << endl;
    return x;
}


int main()
{
    int input = 0;
    
    createTree(root);

    while (input != 7){
        main_menu();
        cin >> input;
        switch (input){
            case 1:
                x = menuTambahItem();
                insertNode(root, createNode(x));
                cout << "Kembali ke menu utama..." << endl;
                cout << endl;
                break;
            case 2:
                cout << "=========== Semua Item ===========" << endl;
                inorder(root);
                break;
            case 3:
                // Code to search item by ID
                break;
            case 4:
                // Code to search item by Name
                break;
            case 5:
                // Code to update item
                break;
            case 6:
                // Code to view items by category
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
