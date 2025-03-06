#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <fstream>
#include <string>

struct Node {
  std::string first_name;
  std::string last_name;
  std::string phone_number;
  Node* next;
};

class Phonebook {
public:
  Phonebook();
  ~Phonebook();

  void add(const std::string& first, const std::string& last, const std:: string& phone)
  void add(const std::string& first, const std::string& last, const std::string& phone);
  void load(const std::string& filename);
  void save(const std::string& filename);
  void print();
  std::string find_by_last(const std::string& last);
  std::string find_by_phone(const std::string& phone);
  void remove(const std::string& first, const std::string& last);

private:
    Node* head;
};

#endif
