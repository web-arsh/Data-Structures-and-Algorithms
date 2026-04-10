#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularLinkedList{
    private:
        Node* head = nullptr;
    public:
        void insertElement(int data){
            
            if(head == nullptr){
                head = new Node{data,nullptr};
                head->next = head;
                return;
            }

            Node* temp = head; 
            do{
                temp = temp->next; 
            }while(temp->next != head);  
            
            Node* ptr = new Node{data,nullptr};
            ptr->next = head;
            temp->next  = ptr;
        }
        void displayElement(){
            if(head == nullptr) return;
            Node* temp = head;
            do{
                cout << temp->data;
                if(temp->next != head) cout<<","; 
                temp = temp->next;
            }while(temp != head); 
        }

        ~CircularLinkedList(){
            if(head == nullptr) return;
             Node* temp = head;
            // Step1: Find last element;
            while(temp->next != head){
                temp = temp->next;
            }
            // Break circular Link
            temp->next = nullptr;
            // Delete all list
            temp = head;
            while(temp != nullptr){
                Node* ptr = temp;
                temp = temp->next;
                delete ptr;
            }

        }
};

int main(){
    CircularLinkedList list;
    list.insertElement(60);
    list.insertElement(40);
    list.insertElement(30);
    list.displayElement();

    return 0;
}