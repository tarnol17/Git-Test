/**
 * Name: Tyson Arnold
 * Date: March 6, 2025
 * Program: Phonebook Linked List
 */

#include "phonebook.h"
#include <iostream>
using namespace std;

int main() {
    Phonebook phonebook;
    string filename, first, last, phone;
    int choice = 0;

    while (choice != 7) {
        cout << "Welcome to the Phonebook! Please enter number to use. " << endl;
        cout << "1. Load phonebook from file" << endl;
        cout << "2. Save phonebook to file" << endl;
        cout << "3. Print phonebook" << endl;
        cout << "4. Find number by last name" << endl;
        cout << "5. Find name by phone number" << endl;
        cout << "6. Add contact" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter filename: " << endl;
            cin >> filename;
            phonebook.load(filename);
        }
        if (choice == 2) {
            cout << "Enter filename: " << endl;
            cin >> filename;
            phonebook.save(filename);
        }
        if (choice == 3) {
            phonebook.print();
        }
        if (choice == 4) {
            cout << "Enter last name: " << endl;
            cin >> last;
            cout << "Phone number: " << phonebook.find_by_last(last) << endl;
        }
        if (choice == 5) {
            cout << "Enter phone number: " << endl;
            cin >> phone;
            cout << "Name: " << phonebook.find_by_phone(phone) << endl;
        }
        if (choice == 6) {
            cout << "Enter first name, last name, and phone number: " << endl;
            cin >> first >> last >> phone;
            phonebook.add(first, last, phone);
        }
    }

}
