//Implementation of Stack using array
#include <iostream>
using namespace std;

const int sz = 10;
int stk[sz];
int pointer = -1;
void display()
{cout<<"\nElements in stack are ";
        for(int i =0; i<=pointer;i++)
        cout<<stk[i]<<" ";}
void push(int element);
void pop();

int main() {
    push(5);
    push(11);
    display();
    pop();
    cout<< "\nAfter pop ";
    display();

    return 0;
}

void push(int element) {
    if(pointer == sz - 1) {
        cout << "Stack is full\n";
    } else {
        pointer++;
        stk[pointer] = element;
    }
}

void pop() {
    if(pointer == -1) {
        cout << "Stack is empty\n";
    } else {
        pointer--;
    }
}
                                                                                                                                            1,14          Top

