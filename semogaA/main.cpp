#include <iostream>
#include "lostLink.h"
using namespace std;

int main()
{
    adrNode root = nullptr;
    infotype x;
    string nama;
    int id, input, pil, cat, sub;

    createTree(root);

    while (input != 7){
        main_menu();
        cin >> input;
        cout << endl;
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
                cout << endl;
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
                    cout << endl;
                    if (pil == 1){
                        cout << "Masukkan ID item yang ingin dicari: ";
                        cin >> id;
                        adrNode result = searchID(root, id);
                        cout << endl;
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
                        cout << endl;
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
                    cout << endl;
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
                cout << "Item dengan ID " << id << " telah dihapus." << endl << endl;;
                break;
            case 6:
                cat = 0;
                while (cat != 6){
                    menuLihatKategori();
                    cin >> cat;
                    cout << endl;
                    switch (cat){
                        case 1:
                            cout << "=========== Kategori Elektronik ===========" << endl;
                            showByCategory(root, 1, 100);
                            cout << "===========================================" << endl << endl;
                            break;
                        case 2:
                            cout << "=========== Kategori Pakaian ===========" << endl;
                            showByCategory(root, 101, 200);
                            cout << "========================================" << endl << endl;
                            break;
                        case 3:
                            cout << "=========== Kategori Makanan ===========" << endl;
                            showByCategory(root, 201, 300);
                            cout << "========================================" << endl << endl;
                            break;
                        case 4:
                            cout << "=========== Kategori Buku ===========" << endl;
                            showByCategory(root, 301, 400);
                            cout << "=====================================" << endl << endl;
                            break;
                        case 5:
                            cout << "=========== Kategori Lainnya ===========" << endl;
                            showByCategory(root, 401, 1000);
                            cout << "========================================" << endl << endl;
                            break;
                        case 6:
                            cout << "Kembali ke menu utama..." << endl << endl;
                            break;
                        default:
                            cout << "Invalid option. Please try again." << endl << endl;
                        }
                }
                break;
            case 7:
                cout << "Exiting the program.";
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
