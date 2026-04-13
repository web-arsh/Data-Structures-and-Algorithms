#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class LinkedList{
    private:
        Node* head;
        Node* tail;
    public: 
        LinkedList(): head(nullptr), tail(nullptr){}
        
        void insertAtEnd(int data){
            if (head == nullptr){
                head = tail = new Node{data,nullptr};
                return;
            }
            
            Node* newNode = new Node{data,nullptr};
            tail->next = newNode;
            tail = newNode;
        }
        void display(){
            if(head == nullptr){
                cout << "List is empty\n";
                return;
            }
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->data;
                temp = temp->next;
                if(temp != nullptr) cout << ",";
            }
            cout << endl;
        }
        void reverse(){
            if(head == nullptr || head->next == nullptr) return;
            
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;
            tail = curr;
            while(curr != nullptr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
        ~LinkedList(){
            Node* temp = head;
            while(temp != nullptr){
                Node* ptr = temp;
                temp = temp->next;
                delete ptr;
            }
            head = tail = nullptr;
        }
};

int main() {
    LinkedList list;
    list.insertAtEnd(40);
    list.insertAtEnd(60);
    list.insertAtEnd(50);
    list.insertAtEnd(5);
    
    list.display();
    list.reverse();
    list.display();

    return 0;
}