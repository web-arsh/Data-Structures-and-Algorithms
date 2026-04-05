#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void display(Node * ptr){
    int i = 0;
    while(ptr!=NULL){
        cout << "Element is: "<<i<<" : "<<ptr->data<<endl;
        ptr = ptr->next;
        i++;    
    }
}
// Insert at begining
void insertAtBegining(Node*& head,int data){
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = head;
    head = ptr;
}

// Insert between
void insertInBetween(Node* head,int data,int index){
    if(index == 0) return;
    Node* ptr = new Node();
    Node* p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

// Insert at End
void insertAtLast(Node* ptr,int data){
    Node* p = new Node();
    p->data = data;
    p->next = NULL;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = p;
    
}

// Insert at specific node
void insertAtNode(Node* prevNode,int data){
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main(){
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Adding value in the Node
    first->data = 45;
    second->data = 67;
    third->data = 99;

    // Assining the next pointer
    first->next = second;
    second->next = third;
    third->next = NULL;

    display(first);
    // cout << "---Insert At Begining---\n";
    // insertAtBegining(first,79);
    
    // cout << "--Insert In Between ---\n";
    // insertInBetween(first,500,2);

    // cout << "---Insert At End---\n";
    // insertAtLast(first,12);

    cout << "---Insert At Node---\n";
    insertAtNode(third,33);
    display(first);

    delete first,second,third;
    return 0;
}

