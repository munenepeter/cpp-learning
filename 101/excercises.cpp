// Write a program to print your name and age.
# include <iostream>

using namespace std;

int main() {
    char name[10];
    int age;

    cout << "Enter your name" << endl;
    cin >> name;
    cout << "Enter your age" << endl;
    cin >> age;

    cout << "Your name: " << name << endl;
    cout << "Your age: " << age << endl;
}
// Write a program to print the sum of two numbers.
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int x,y;

    cout << "Enter a number" << endl;
    cin >> x;
    cout << "Enter a number" << endl;
    cin >> y;

    cout << "Sum of two numbers is " << x + y << endl;
}
// Write a program to find the factorial of a number.
#include <iostream>

using namespace std;
int factorial(int num) {
    if (num > 1) {
        return (num * factorial(num - 1));
    } else {
        return 1; 
  }
}

int main(int argc, char **argv) {
    //n! = n * (n-1) * (n-2) * (n-3) ... * 1
    int x;
    cout << "Enter a number" << endl;
    cin >> x;
    cout << "Factorial of " << x << " is " << factorial(x) << endl;
}
// Write a program to reverse a string.
// Write a program to check whether a number is prime.
// Write a program to print the Fibonacci sequence.
// Write a program to sort an array of numbers.
// Write a program to search for an element in an array.
// Write a program to implement a linked list.
// Write a program to implement a stack.