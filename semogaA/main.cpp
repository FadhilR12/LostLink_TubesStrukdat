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
        x.kategori = 1; // Elektronik
    } else if (x.id <= 200) {
        x.kategori = 2; // Pakaian
    } else if (x.id <= 300) {
        x.kategori = 3; // Makanan
    } else if (x.id <= 400) {
        x.kategori = 4; // Buku
    } else {
        x.kategori = 5; // Lainnya
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

int main()
{
    int input = 0;
    int pil = 0;
    int sub = 0;

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
                sub = 0;
                while (sub != 1){
                sub = 0;
                cout << "=========== Semua Item ===========" << endl;
                inorder(root);
                cout << "==================================" << endl;
                cout << "1. Kembali ke menu utama" << endl;
                cin >> sub;
                }
                break;
            case 3:
                pil = 0;
                while (pil != 3){
                    cout << "=========== Cari Item ===========" << endl;
                    cout << "1. Cari berdasarkan ID" << endl;
                    cout << "2. Cari berdasarkan Nama" << endl;
                    cout << "3. Kembali ke menu utama" << endl;
                    cout << "Select an option (1-3): ";
                    cin >> pil;
                    if (pil == 1){
                        cout << "Masukkan ID item yang ingin dicari: ";
                        cin >> id;
                        adrNode result = searchID(root, id);
                        if (result != nullptr){
                            cout << "==================================" << endl;
                            cout << "Item ditemukan: " << endl;
                            cout << "ID: " << result->info.id
                                 << " | Item: " << result->info.nama
                                 << " | Lokasi: " << result->info.lokasi
                                 << endl;
                            cout << "==================================" << endl;
                        } else {
                            cout << "Item dengan ID " << id << " tidak ditemukan." << endl;
                        }
                    }
                    else if (pil == 2){
                        cout << "Masukkan nama item yang ingin dicari: ";
                        cin >> nama;
                        adrNode result = searchByName(root, nama);
                        if (result != nullptr){
                            cout << "==================================" << endl;
                            cout << "Item ditemukan: " << endl;
                            cout << "ID: " << result->info.id
                                 << " | Item: " << result->info.nama
                                 << " | Lokasi: " << result->info.lokasi
                                 << endl;
                            cout << "==================================" << endl;
                        } else {
                            cout << "Item dengan nama " << nama << " tidak ditemukan." << endl;
                        }
                    }
                }
                break;
             case 4:
                cout << "Masukkan ID item yang ingin diupdate: ";
                cin >> id;
                updateNode(root, id);
                break;
             case 5:
                cout << "Masukkan ID item yang ingin dihapus: ";
                cin >> id;
                deleteNode(root, id);
                cout << "Item dengan ID " << id << " telah dihapus." << endl;
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
