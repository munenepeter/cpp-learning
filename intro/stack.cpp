#include <iostream>

/*
|   Sample data structure using a class
|   Can add items into the stack (push)
|   Can remove items from the stack (pop)
|   Can display all the items and the size of the stack
|
*/

#define STACK_SIZE 10

using namespace std;

class stack{
    private:
    int size; //size of the stack
    int data[STACK_SIZE]; //actual contents of the stack

    public:
    /* Here to initialize the stack by setting the size to 0*/
    stack(void){
        this->size = 0;
    }
    /*Add an item to the stack, i.e by increasing the size and setting the index by one*/
    void push(int item){
        if(this->size >= STACK_SIZE - 1){
            cout << "The stack is full!"<< endl;
        }else{
            this->data[this->size] = item;
            this->size++;
        }
    }
    /* Remove an item from the stack by decreasing the size and return the item at that index*/
    int pop(void){
        if(this->size <= 0){
            cout << "There are no items in the stack!"<< endl;
            return -1;
        }else{
            this->size--;
            return this->data[this->size];
        }
    }
    int get_size(void){
        return this->size;
    }
    void print_stack(void){
        for(int i = 0; i < this->size; ++i){
            cout << "stack[" << i <<"]" << " = " << this->data[i] << endl;
        }
        cout << "--------------" << endl;
    }
};

int main(){
    stack new_stack;

    new_stack.push(10);
    new_stack.push(20);
    new_stack.print_stack();
    new_stack.push(30);
    new_stack.print_stack();
    new_stack.pop();
    new_stack.push(70);
    new_stack.print_stack();
    new_stack.pop();

}
