#include <iostream>

using namespace std;

int main(){
    //first datatype then variable name
    int age = 10;
    string name;

    cout << "Enter your name" << endl;

    getline(cin, name);

    cout << "Your name is :" << name << " and you're " << age << " years old" << endl;

  return 0;
}