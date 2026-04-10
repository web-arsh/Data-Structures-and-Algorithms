#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class CircularLinkedList{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        int length = 0;
    
    public: 
        void insertElementEmptyList(int data){
            head = tail = new Node{data,nullptr};
            head->next = head;
            length++;
        }
        void insertAtEnd(int data){
            if(head == nullptr){
                insertElementEmptyList(data);
                return;
            }

            Node* newNode = new Node{data,nullptr};
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
            length++;
            
        }
        void display(){
            if(head == nullptr) return;
            Node* temp = head;
            do{
                cout << temp->data;
                temp = temp->next; 
                if(temp != head) cout<<","; 
            }while(temp != head);
            cout << endl;
        }

        void insertAtBegining(int data){
            if(head == nullptr) {
                insertElementEmptyList(data);
                return;
            }

            Node* newNode = new Node{data,nullptr};
            newNode->next = head;
            tail->next = newNode;
            head= newNode;
            length++;
        };
        void insertAtIndex(int index,int data){
            if(index > length || index < 0) {
                cout << "Index out of bound\n";
                return;
            }
            if(head == nullptr){
                if(index == 0){
                    insertElementEmptyList(data);
                }else{
                    cout << "Index out of bound\n";
                }
                return;
            }
            // Insert At Begining if index == 0
            if(index == 0){
                insertAtBegining(data);
                return;
            }
            // Insert At End if index is == lastIndex
            else if(index == length){
                insertAtEnd(data);
                return;
            }
            else{
                Node* newNode = new Node{data,nullptr};
                Node* temp = head;
                
                for(int i = 1;i < index;i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
                return;    
            }
        }

        ~CircularLinkedList(){
            if(head == nullptr) return; 
            tail->next = nullptr;
            Node* temp = head;
            while(temp != nullptr){
                Node* ptr = temp;
                temp = temp->next;
                delete ptr;
            }
            head = tail = nullptr;
            length = 0;
        }
};


int main(){
    CircularLinkedList list;
    list.insertAtEnd(80);
    list.insertAtEnd(60);
    list.insertAtEnd(70);
    list.display();

    return 0;
}