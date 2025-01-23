#include <iostream>

using namespace std;

int sum(int n){
  int total = 0;
  for (int i = 1; i <= n; i++){
    total += 1;
  }
  return total;
}

int product(int n){
  int total = 1;
  for(int i = 1; i < n; i++){
    result *= i;
  }
  return total;
}

int main(){
  int number;
  cout << "Please give me a number";
  cin >> number;

  int total_sum = sum(number);
  cout << "Here is the sum of the number " << total_sum << endl;

  int total_product = product(number);
  cout << "Here is the product of the number " << total_product << endl;
}
