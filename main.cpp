#include <iostream>

using namespace std;

int sum(int n){
  int total = 0;
  for (int i = 1; i <= n; i++){
    total += 1;
  }
  return total;
}

int main(){
  int number;
  cout << "Please give me a number";
  cin >> number;

  int total_number = sum(number);
  cout << "Here is the sum of the number " << total_number << endl;
}
