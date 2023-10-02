#include <iostream>

#define STACK_SIZE 10

using namespace std;

class stack{
    private:
    int size;
    int data[STACK_SIZE];

    public:
    stack(void){
        this->size = 0;
    }
    void push(int item){
        if(this->size >= STACK_SIZE - 1){
            cout << "The stack is full!"<< endl;
        }else{
            this->data[this->size] = item;
            this->size++;
        }
    }
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
