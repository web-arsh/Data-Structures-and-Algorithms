#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoubleLinkedList(): head(nullptr), tail(nullptr), length(0){}
        void insertAtEnd(int data){
            if(head == nullptr){
                head = tail = new Node{data,nullptr,nullptr};
                length++;
                return;
            }
            Node* newNode = new Node{data,tail,nullptr};
            tail->next = newNode;
            tail = newNode;
            length++;
            return;
        }
        void display(){
            if(head == nullptr){
                cout << "List is empty\n";
                return;
            };
           
            // Forward
            cout << "Forward \n";
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->data;
                temp = temp->next;
                if(temp != nullptr) cout<<",";
            }
            cout<<endl;

            // Backward
            cout<<"Backward\n";
            temp = tail;
            while(temp != nullptr){
                cout << temp->data;
                temp = temp->prev;
                if(temp!=nullptr) cout <<",";
            }
            cout <<endl;
            
            cout << "Length: "<<length;
        }

        ~DoubleLinkedList(){
            Node* temp = head;
            while(temp != nullptr){
                Node* ptr = temp;
                temp = temp->next;
                delete ptr;
            }
            length = 0;
        }
};

int main(){
    DoubleLinkedList list;
    list.insertAtEnd(40);
    list.insertAtEnd(70);
    list.insertAtEnd(50);
    list.display();

    return 0;
}