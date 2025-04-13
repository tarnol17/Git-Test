/**
* @file main.cpp
* @author Tyson Arnold
* @date 04-11-2025
* @brief Binary Search Tree
* 
*/
 
#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
using namespace std;

void showMenu() {
    cout << "1. Set" << endl;
    cout << "2. Find" << endl;
    cout << "3. Print" << endl;
    cout << "4. Min" << endl;
    cout << "5. Max" << endl;
    cout << "6. Save to File" << endl;
    cout << "7. Delete" << endl;
    cout << "8. Load Filet" << endl;
    cout << "9. Quit" << endl;
    cout << "Choose: ";
}

int main() {
    BST tree;
    int choice;
    string key;
    int value;

    // Main loop for displaying menu and interacting with the user
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            tree.set(key, value);
        }
        else if (choice == 2) {
            cout << "Key: ";
            cin >> key;
            int found = tree.find(key);
            if (found == -1)
                cout << "The thing was not found\n";
            else
                cout << "Value: " << found << endl;
        }
        else if (choice == 3) {
            tree.print();
        }
        else if (choice == 4) {
            tree.min();
        }
        else if (choice == 5) {
            tree.max();
        }
        else if (choice == 6) {
            cout << "Filename: ";
            cin >> key;
            tree.save_file(key);
        }
        else if (choice == 7) {
            cout << "Key to delete: ";
            cin >> key;
            tree.remove(key);
        }
        else if (choice == 8) {
            cout << "File: ";
            cin >> key;
            ifstream file(key.c_str());
            string word;
            while (file >> word) {
                int count = tree.find(word);
                if (count == -1) count = 0;
                tree.set(word, count + 1);
            }
            file.close();
            cout << "The File has been loaded! :D" << endl;
        }
        else if (choice == 9) {
            cout << "Goodbye!" << endl;
            break;
        }
    }

}

