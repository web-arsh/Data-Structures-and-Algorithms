#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void display(Node* ptr){
    while(ptr != nullptr){
        cout << ptr->data;
        ptr = ptr->next;
        if(ptr != nullptr) cout <<",";
    }
    cout << endl;
}

bool isEmpty(Node* top){
    if(top == nullptr) return true;
    return false;
}

bool isFull(Node* top){
    try{
        Node* ptr = new Node();
        delete ptr;
        return false;
    }catch(bad_alloc&){
        return true;
    }
}

Node* push(Node*& top,int data){
    if(isFull(top)){
        cout << "Stack Overflow\n";
        return nullptr;
    }

    Node* newNode = new Node{data,top};
    top = newNode;
    return top;
}

int pop(Node*& top){
    if(isEmpty(top)){
        cout << "Stack Underflow\n";
        return -1;
    }
    Node* n = top;
    int pop = n->data;
    top = top->next;
    delete n;
    return pop;
}

int main(){
    Node* top = nullptr;
    push(top,22);
    push(top,66);
    push(top,33);

    int p = pop(top);
    cout << "Pop element is "<<p<<endl;
    display(top);

    while(top != nullptr){
        pop(top);
    }

    return 0;
}