#include <iostream>

using namespace std;

//n! = n * (n-1) * (n-2) * (n-3) ... * 1

int factorial(int num) {

  if (num > 1) {

    return (num * factorial(num - 1));

  } else {

    return 1;
    
  }
}

int main() {

  int number;

  cout << "Enter a number to get it's factorial" << endl;
  cin >> number;

  cout << "****************************************" << endl;

  cout << number << "!= " << factorial(number) << endl;

  return 0;
}