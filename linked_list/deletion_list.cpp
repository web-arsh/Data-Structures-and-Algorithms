#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
void display(Node* head){
    while(head != nullptr){
        cout << "Element is "<<head->data<<endl;
        head = head->next;
    }
}

void deleteAtBegining(Node*& head){
    Node* ptr = head;
    head = head->next;
    delete ptr;
    ptr = nullptr;
}

void deleteAtIndex(Node*& head,int index){
    if(head == nullptr){
        cout << "Head is empty\n";
        return;
    }

    Node* temp = head;
    if(index == 0){
        head = head->next;
        delete temp;
        temp = nullptr;
        return;
    }
    int i = 0;
    while(i<index-1){ //0<3
        if(temp->next == nullptr){
            cout << "Index out of bound\n";
            return;
        }
        temp = temp->next; //temp = 90  i = 2
        i++;
    }
    if(temp->next == nullptr || index < 0){
        cout << "Index out of bound\n";
        return;
    }
    Node* ptr = temp->next;
    temp->next = ptr->next;
    delete ptr;
    ptr = nullptr;

}

void deleteAtLast(Node* head){
    Node* q = head->next;
    Node* p = head;
    while(q->next != nullptr){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    delete q;
    
}

void deleteByValue(Node*& head,int value){
    // In this code we delete the element when value matches
    if(head == nullptr){
        cout << "Head is empty \n";
        return;
    }
    
    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr && curr->next->data != value){
        curr = curr->next;
    }
    if(curr->next != nullptr){
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }else{
        cout << "Element not found\n";
    }
}

void deleteAtPointer(Node* ptr){
    // In this pointer bascially we copy the next element data and next pointer and paste in the current ptr which we want to delete and delete the next element
    if(ptr == nullptr || ptr->next == nullptr){
        cout << "Last element is not deleted"<<endl;
        return;
    }
    Node* temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete temp;
}

int main(){
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    first->data = 54;
    second->data = 34;
    third->data = 90;
    fourth->data = 80;

    first->next = second;
    second->next =third;
    third->next = fourth;
    fourth->next = nullptr;

    display(first);

    // cout << "---Delete At Begining---"<<endl;
    // deleteAtBegining(first);

    // cout << "---Delete At Specific Index---"<<endl;
    // deleteAtIndex(first,5);
    
    // cout<<"---Delete at End---"<<endl;
    // deleteAtLast(first);

    // cout << "---Delete when value is given ---"<<endl;
    // deleteByValue(first,70);

    cout << "---Delete when pointer is given---"<<endl;
    deleteAtPointer(second);

    display(first);


    return 0;
}