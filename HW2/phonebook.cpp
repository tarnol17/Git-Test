#include "phonebook.h"

/**
 * @brief Constructs an empty phonebook.
 */
Phonebook::Phonebook() {
    head = nullptr;
}

Phonebook::~Phonebook() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief Adds a new contact to the front of the phonebook.
 * @param first The first name of the contact.
 * @param last The last name of the contact.
 * @param phone The phone number of the contact.
 */
void Phonebook::add(const std::string& first, const std::string& last, const std::string& phone) {
    Node* new_node = new Node{first, last, phone, head};
    head = new_node;
}


void Phonebook::load(const std::string& filename) {
    std::ifstream file(filename);
    std::string first, last, phone;
    
    while (file >> first >> last >> phone) {
        add(first, last, phone);
    }
}

void Phonebook::save(const std::string& filename) {
    std::ofstream file(filename);
    Node* current = head;
    
    while (current) {
        file << current->first_name << " " << current->last_name << " " << current->phone_number << "\n";
        current = current->next;
    }
}

/**
 * @brief Prints all contacts in the phonebook.
 */
void Phonebook::print() {
    Node* current = head;
    
    while (current) {
        std::cout << current->first_name << " " << current->last_name << " - " << current->phone_number << "\n";
        current = current->next;
    }
}

std::string Phonebook::find_by_last(const std::string& last) {
    Node* current = head;
    
    while (current) {
        if (current->last_name == last) {
            return current->phone_number;
        }
        current = current->next;
    }
    
    return "Not found";
}

std::string Phonebook::find_by_phone(const std::string& phone) {
    Node* current = head;
    
    while (current) {
        if (current->phone_number == phone) {
            return current->first_name + " " + current->last_name;
        }
        current = current->next;
    }
    
    return "I'm sorry but this is not found";
}

/**
 * @brief Removes a contact from the phonebook.
 * @param first The first name of the contact to remove.
 * @param last The last name of the contact to remove.
 */
void Phonebook::remove(const std::string& first, const std::string& last) {
    Node* current = head;
    Node* previous = nullptr;

    while (current) {
        if (current->first_name == first and current->last_name == last) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}
