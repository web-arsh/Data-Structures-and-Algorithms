#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(Stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
int isFull(Stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}

int main(){
    Stack* s = new Stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    if(isEmpty(s)){
        cout << "Stack is empty";
    }else{
        cout << "Stack is not empty";
    }

    return 0;
}