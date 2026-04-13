#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoubleLinkedList(): head(nullptr), tail(nullptr), length(0){}

        void insertAtEnd(int data){
            // If head is empty then create a node
            if(head == nullptr){
                head = tail = new Node{data,nullptr,nullptr};
                length++;
                return;
            }
            // If head is present then insert the new node at the end
            Node* newNode = new Node{data,nullptr,tail};
            tail->next = newNode;
            tail = newNode;
            length++;
            return;
        }

        void deleteAtBegining(){
            // If head is null it means list doesnot exists
            if(head == nullptr){
                cout << "List is Empty\n";
                return;
            }
            Node* temp = head;
            // If head and tail both are equal then do both null and delete so both doesnot store any address else point head to next element and prev element to null
            if(head == tail){
                head = tail = nullptr;
            }else{
                head = head->next;
                head->prev = nullptr;
            }

            delete temp;
            length--;
        }
        void deleteAtEnd(){
            if(head == nullptr){
                cout << "List is Empty\n";
                return;
            }
            Node* temp = tail;
            if(head == tail){
                head = tail = nullptr;
            }
            else{
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }
        void deleteAtIndex(int index){
            if(index >= length || index < 0){
                cout << "Index out of bound\n";
                return;
            }
            if(index == 0){
                deleteAtBegining();
                return;
            }
            else if(index == length -1){
                deleteAtEnd();
                return;
            }else{
                Node* start;
                if(index < length/2){
                    start = head;
                    for(int i = 0;i<index;i++){
                        start = start->next;
                    }
                }else{
                    start = tail;
                    for(int i = length -1;i> index;i--){
                        start = start->prev;
                    }
                }
                Node* prev = start->prev;
                prev->next = start->next;
                start->next->prev = prev;
                length--;
                delete start;
            }
        }

        void display(){
            if(head == nullptr){
                cout << "List is empty\n";
                return;
            }
            Node* temp = head;
            bool rev = false;

            while(temp != nullptr){
                cout << temp->data;

                if(temp->next == nullptr && !rev){
                    rev = true;
                    cout <<endl;
                }else if(temp->prev == nullptr && rev){
                    break; 
                }else{
                    temp = (rev) ? temp->prev : temp->next;
                    if(temp != nullptr) cout << ",";
                }                 
            }
            cout << endl;
        }

        ~DoubleLinkedList(){
            if(head == nullptr) return;
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
    DoubleLinkedList list;
    list.insertAtEnd(50);
    list.insertAtEnd(40);
    list.insertAtEnd(3);
    list.insertAtEnd(500);
    list.insertAtEnd(60);
    list.insertAtEnd(90);
    list.deleteAtIndex(2);
    list.display();

    return 0;
}