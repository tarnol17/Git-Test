#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

class Node {
public:
    string key;
    int data;
    Node* left;
    Node* right;
    Node(string k, int d);
};

class BST {
private:
    Node* root;
    void setHelper(Node*& current, string key, int value);
    int findHelper(Node* current, string key);
    void printHelper(Node* current);
    void destroy(Node* current);
    void minHelper(Node* current);
    void maxHelper(Node* current);
    void saveHelper(Node* current, ofstream& file);
    void deleteHelper(Node*& current, string key);

public:
    BST();
    ~BST();
    void set(string key, int value);
    int find(string key);
    void print();
    void min();
    void max();
    void save_file(string filename);
    void delete_key(string key);
};

#endif
