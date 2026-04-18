#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int* arr;
};

bool isEmpty(Stack* ptr){
    return ptr->top == -1;
}
bool isFull(Stack* ptr){
    return ptr->top == ptr->size - 1;
}

void push(Stack* ptr,int value){
    if (isFull(ptr)){
        cout << "Stack Overflow\n";
        return;
    }
    ptr->arr[++ptr->top] = value;
}

int pop(Stack* ptr){
    if(isEmpty(ptr)){
        cout << "Stack Underflow\n";
        return -1;
    }
    int val = ptr->arr[ptr->top--];
    return val;

}

int peek(Stack* ptr,int i){
    if(ptr->top-i+1 < 0 || i<=0 ){
        cout << "Invalid Position\n";
        return -1;
    }
    int index = ptr->top-i+1;
    return index;
}

int main(){
    Stack* s = new Stack();
    s->size = 5;
    s->top = -1;
    s->arr = new int[s->size];

    cout << isFull(s) << endl;
    cout << isEmpty(s) << endl;
    push(s,56);
    push(s,16);
    push(s,526);
    push(s,5346);
    cout << isFull(s) << endl;
    cout << isEmpty(s) << endl;
    cout << "Popped " << pop(s) << " from stack\n";

    int val = peek(s,0);
    if(val != -1) cout << "Element at "<<val<<" is "<<s->arr[val];

    delete[] s->arr;
    delete s;

    return 0;
}