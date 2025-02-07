/**
 * @file main.cpp
 * @author Tyson Arnold
 * @date 2025-02-07
 */


#include "Vector.h"
#include <iostream>

using namespace std;

int main(){
  Vector v;
  for (int i = 0; i < 1030; i++){
    v.push_back(i);
  }

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;

  Vector copy = v;
  Vector assigned;
  assigned = v;

  cout << "Here is copy size: " << copy.size() << " and capacity " << copy.capacity() << endl;

}
