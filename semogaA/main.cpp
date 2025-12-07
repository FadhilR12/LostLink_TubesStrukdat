#include <iostream>
#include "lostLink.h"
using namespace std;

void main_menu(){
    cout << "=== LostLink ===" << endl;
    cout << "1. Add New Item" << endl;
    cout << "2. View All Items" << endl;
    cout << "3. Search Item" << endl;
    cout << "4. Update Item" << endl;
    cout << "5. Delete Item" << endl;
    cout << "6. View Items by Category" << endl;
    cout << "7. Exit" << endl;
    cout << "Select an option (1-7): ";
}

void menuTambahBarang(){
    cout << "=== Add New Item ===" << endl;
    
}

void menuLihatBarang(){
    cout << "===   List Item  ===" << endl;
    inorder(root);
}

void menuCariBarang(){
    cout << "=== Search Item ===" << endl;
    while (true){
        cout << "1. Search by ID" << endl;
        cout << "2. Search by Name" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Select an option (1-3): ";
        int choice;
        cin >> choice;
        if (choice == 1){
            menuCariID();
        } else if (choice == 2){
            menuCariNama();
        } else if (choice == 3){
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void menuCariID(){
    cout << "=== Search Item by ID ===" << endl;

}

void menuCariNama(){
    cout << "=== Search Item by Name ===" << endl;

}

void menuUpdateBarang(){
    cout << "=== Update Item ===" << endl;

}

void menuHapusBarang(){
    cout << "=== Delete Item ===" << endl;

}

void menuKategori(){
    cout << "=== View Items by Category ===" << endl;

}

int main()
{
    int input = 0, id, minID, maxID;
    adrNode root = nullptr;
    infotype x;
    string name;

    createTree(root);

    while (input != 7){
        main_menu();
        cin >> input;
        switch (input){
            case 1:
                // Code to add new item
                break;
            case 2:
                // Code to view all items
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
