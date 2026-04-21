#include<iostream>
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

        void append(int data){
            if(head == nullptr){
                head = tail = new Node{data,nullptr};
                return;
            }
            Node* newNode = new Node{data,nullptr};
            tail->next = newNode;
            tail = newNode;
        }

        void display(){
            if(head == nullptr){
                cout << "List is Empty\n";
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

        void deleteAllElement(int data){
            if(head == nullptr) return;
            Node dummy{0,head};
            Node* curr = &dummy;
            Node* lastValid = &dummy;

            while(curr->next != nullptr){
                if(curr->next->data == data){
                    Node* temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
                }else{
                    lastValid = curr->next;
                    curr = curr->next;
                }
            }
            head = dummy.next;
            tail = (head == nullptr) ? nullptr : lastValid;
        }

        ~LinkedList(){
            while(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
        }

};

int main(){
    LinkedList list;
    list.append(70);
    list.append(70);
    list.append(70);
    list.append(70);
    list.append(70);
    list.append(0);
    list.display();
    list.deleteAllElement(70);
    list.display();
    list.append(60);
    list.display();

    return 0;
}