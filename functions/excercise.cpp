#include <iostream>

using namespace std;

/*
1. Write a program in C++ to print a welcome text in a separate line.
*/
inline void welcome(){
    string name;
    cout << "Enter your name to continue" << endl;
    cin >> name;
    cout << "Welcome" << endl << name << endl;
}

/*
2. Write a program in C++ to print the sum of two numbers.
*/
inline void sum(){
   int a, b, sum;

   cout << "Enter a number" <<endl;
   cin >> a;
   cout << "Enter another to get their sum" << endl;
   cin >> b;

   sum = a+b;

   cout << "The sum of " << a << " and " << b << " is " << sum << endl;
}



int main(){
  //welcome();
  sum();

  return 0;
}