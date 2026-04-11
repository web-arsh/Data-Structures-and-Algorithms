#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularLinkedList{
    private: 
        Node* head;
        Node* tail;
        int length = 0;
    public:
        CircularLinkedList(): head(nullptr),tail(nullptr){}
        
        void insertAtEnd(int data){
            if(head == nullptr){
                head = tail = new Node{data,nullptr};
                head->next = head;
                length++;
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
                if(temp != head) cout << ",";
            }while(temp != head);
            cout<<endl;
        }

        void deleteAtBegining(){
            if(head == nullptr) return;
            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                length--;
                return;
            }
            Node* ptr = head->next;
            tail->next = ptr;
            delete  head;
            head = ptr;
            length--;
        }
        void deleteAtEnd(){
            if(head == nullptr) return;

            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                length--;
                return;
            }
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            Node* del = tail;
            tail = temp;
            temp->next = head;
            delete del;
            length--;
        }
        void deleteAtIndex(int index){
            if(head == nullptr) return;
            if(index >= length || index < 0) {
                cout <<"Index out of bound\n";
                return;
            }
            if(index == 0){
                deleteAtBegining();
                return;
            }
            else if(index == length - 1){
                deleteAtEnd();
                return;
            }
            else{
                int i = 0;
                Node* temp = head;
                while(i < index - 1){ //if want to delete index 3 then we want to traverse it to 2 
                    temp = temp->next;
                    i++;
                }
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                length--;
                return; 
            }

        }

        ~CircularLinkedList(){
            if(head == nullptr) return;
            Node* temp = head;
            if(tail) tail->next = nullptr;
            while(temp!= nullptr){
                Node* ptr = temp;
                temp = temp->next;
                delete ptr;
            }
            length=0;
        }

};

int main(){
    CircularLinkedList list;
    list.insertAtEnd(60);
    list.insertAtEnd(70);
    list.insertAtEnd(50);
    list.display();
    list.deleteAtIndex(1);
    list.display();

    return 0;
}