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
        DoubleLinkedList(): head(nullptr),tail(nullptr),length(0){};

        void insertAtEnd(int data){
            if(head == nullptr){
                head = tail = new Node{data,nullptr,nullptr};
                length++;
                return;
            }
            Node* newNode = new Node{data,nullptr,tail};
            tail->next = newNode;
            tail = newNode;
            length++;
        }
        void insertAtBeginning(int data){
            if(head == nullptr){
                head = tail = new Node{data,nullptr,nullptr};
                length++;
                return;
            }
            Node* newNode = new Node{data,head,nullptr};
            head->prev = newNode;
            head = newNode;
            length++;
        }

        void insertAtIndex(int index,int data){
            if(index > length || index < 0){
                cout << "Index out of the bound \n";
                return;
            }
            if(index == 0){
                insertAtBeginning(data);
                return;
            }
            else if(index == length){
                insertAtEnd(data);
                return;
            }
            else{
                Node* start;
                if(index < length /2){
                    // If index is smaller than half of the length then start loop from head
                    start = head;
                    for(int i =0;i<index;i++){
                        start = start->next;
                    }
                }
                else{
                    // If index is greater than half of the length then start loop from tail
                    start = tail;
                    //index = 5 , lenght = 7 , i = 5 ,start = 6
                    for(int i = length-1;i>index;i--){
                        start = start->prev;
                    }
                }
                Node* prevNode = start->prev;
                Node* newNode = new Node{data,start,prevNode};
                prevNode->next = newNode;
                start->prev = newNode;
                length++;
            }
        }

        void display(){
            if(head == nullptr) {
                cout << "List is empty\n";
                return;
            }
            // Forward
            Node* temp = head;
            cout << "Forward \n";
            while(temp != nullptr){
                cout <<temp->data;
                temp = temp->next;
                if(temp != nullptr) cout <<",";
            }
            cout <<endl;

            // Backward
            temp = tail;
            cout << "Backward\n";
            while(temp != nullptr){
                cout << temp->data;
                temp = temp->prev;
                if(temp != nullptr) cout <<",";
            }
            cout <<endl;
 
            cout << "Length: "<<length;
            cout<<endl; 
        }

        ~DoubleLinkedList(){
            if(head == nullptr) return;
            Node* temp = head;
            while(temp != nullptr){
                Node* ptr = temp;
                temp = temp->next;
                delete ptr;
            }
            length = 0;
            head = tail = nullptr;
        }
};


int main(){
    DoubleLinkedList list;
    list.insertAtEnd(40);
    list.insertAtEnd(60);
    list.insertAtEnd(80);
    list.insertAtEnd(50);
    list.insertAtIndex(0,0);
    list.display();

    return 0;
}