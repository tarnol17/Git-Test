#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

/**
 * @brief Constructor make a new Node with key and a value.
 * 
 * @param key The key used to store in the node.
 * @param value The value for the key.
 */
Node::Node(string k, int d) {
    key = k;
    data = d;
    left = NULL;
    right = NULL;
}

BST::BST() {
    root = NULL;
}

BST::~BST() {
    destroy(root);
}

/**
 * @brief Destorys Node.
 * 
 * @param current destorys current thing.
 */
void BST::destroy(Node* current) {
    if (current == NULL) return;
    destroy(current->left);
    destroy(current->right);
    delete current;
}

/**
 * @brief Inserts into the tree.
 * 
 * @param key The key to insert.
 * @param value The associated value.
 */
void BST::set(string key, int value) {
    setHelper(root, key, value);
}

/**
 * @brief setHelper.
 * 
 * @param current the current node.
 * @param key
 * @param value
 */
void BST::setHelper(Node*& current, string key, int value) {
    if (current == NULL) {
        current = new Node(key, value);
    } else if (key < current->key) {
        setHelper(current->left, key, value);
    } else if (key > current->key) {
        setHelper(current->right, key, value);
    } else {
        current->data = value;
    }
}

/**
 * @brief Finds a key in the tree.
 * 
 * @param key The key to search for.
 * @return The value associated with the key.
 */
int BST::find(string key) {
    return findHelper(root, key);
}

int BST::findHelper(Node* current, string key) {
    if (current == NULL) return -1;
    if (key == current->key) return current->data;
    if (key < current->key) return findHelper(current->left, key);
    return findHelper(current->right, key);
}

/**
 * @brief Prints all nodes in the tree.
 */
void BST::print() {
    printHelper(root);
    cout << endl;
}

/**
 * @brief Helper function to print the tree.
 * 
 * @param current The current node to print the thing.
 */
void BST::printHelper(Node* current) {
    if (current == NULL){
        return;
    }
    printHelper(current->left);
    cout << "(" << current->key << ", " << current->data << ") ";
    printHelper(current->right);
}


/**
 * @brief Prints the smallest key in the tree.
 */
void BST::min() {
    minHelper(root);
}

/**
 * @brief finds the smallest word
 * 
 * @param current The associated current.
 */
void BST::minHelper(Node* current) {
    if (current == NULL) return;
    while (current->left != NULL) {
        current = current->left;
    }
    cout << "Min: " << current->key << " -> " << current->data << endl;
}

/**
 * @brief Prints the largest key in the tree.
 */
void BST::max() {
    maxHelper(root);
}

void BST::maxHelper(Node* current) {
    if (current == NULL) return;
    while (current->right != NULL) {
        current = current->right;
    }
    cout << "Max: " << current->key << " -> " << current->data << endl;
}


/**
 * @brief Saves the things of the tree to a file.
 * 
 * @param filename The name of the file that is saved.
 */
void BST::save_file(string filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        saveHelper(root, file);
        file.close();
    }
}

void BST::saveHelper(Node* current, ofstream& file) {
    if (current == NULL){
        return;
    }
    saveHelper(current->left, file);
    file << current->key << " " << current->data << endl;
    saveHelper(current->right, file);
}


/**
 * @brief Deletes a key from the tree.
 * 
 * @param key The key that gets deletedv.
 */
void BST::delete_key(string key) {
    deleteHelper(root, key);
}

/**
 * @brief Helper function to delete a node from the tree.
 * 
 * @param current The current node to check.
 * @param key The key to delete.
 */
void BST::deleteHelper(Node*& current, string key) {
    if (current == NULL){
        return;
    }
    if (key < current->key) {
        deleteHelper(current->left, key);
    } else if (key > current->key) {
        deleteHelper(current->right, key);
    } else {
        Node* temp;
        if (current->left == NULL) {
            temp = current->right;
            delete current;
            current = temp;
        } else if (current->right == NULL) {
            temp = current->left;
            delete current;
            current = temp;
        } else {
            Node* next = current->right;
            while (next->left != NULL){
                next = next->left;
            }
            current->key = next->key;
            current->data = next->data;
            deleteHelper(current->right, next->key);
        }
    }
}
