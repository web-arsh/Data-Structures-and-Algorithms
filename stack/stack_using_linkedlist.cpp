#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class StackLinkedList{
    private:
        Node* top;
        int size;
    public:
        StackLinkedList(): top(nullptr), size(0){}

        bool isEmpty(){
            return top == nullptr;
        }

        bool isFull(){
            try{
                Node* ptr = new Node();
                delete ptr;
                return false;
            }catch(bad_alloc&){
                return true;
            }
        }

        int getSize() const {
            return size;
        }

        void push(int data){
            if(isFull()){
                throw overflow_error("Stack Overflow: Stack is full\n");
            }
            top = new Node{data,top};
            size++;
        }

        int pop(){
            if(isEmpty()){
                throw underflow_error("Stack Underflow: Stack is empty\n");
            }
            Node* temp = top;
            int n = temp->data;
            top = top->next;
            delete temp;
            size--;
            return n;
        }

        int stackTop(){
            if(isEmpty()){
                throw underflow_error("Stack Underflow: Stack is empty\n");
            }
            return top->data;
        }

        int stackBottom(){
            if(isEmpty()){
                throw underflow_error("Stack Underflow: Stack is empty\n");
            }
            Node* ptr = top;
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            return ptr->data;
        }

        int peek(int index){
            if(isEmpty()){
                throw underflow_error("Stack Underflow: Stack is Empty\n");
            }
            if(index <= 0 || index > size){
                throw out_of_range("Index out of range: valid range is 1 to " + to_string(size));
            }

            Node* ptr = top;
            for(int i =1 ;i < index;i++){
                ptr = ptr->next;
            }
            return ptr->data;
        }

        void display(){
            if(isEmpty()){
                throw underflow_error("Stack Underflow: Stack is empty\n");
            }
            cout << "Top -> ";
            Node* ptr = top;
            while(ptr != nullptr){
                cout << ptr->data;
                if(ptr->next != nullptr) cout << " -> ";
                ptr = ptr->next;
            }
            cout << "-> nullptr \n";
        }
        ~StackLinkedList(){
            while(!isEmpty()){
                pop();  
            }
        }
};


int main(){
    try{
        StackLinkedList s;
        s.push(12);
        s.push(45);
        s.push(90);
        s.push(55);
        s.display();

        cout << "Top       : " << s.stackTop()    << "\n";
        cout << "Bottom    : " << s.stackBottom() << "\n";
        cout << "peek(1)   : " << s.peek(1)       << "\n";
        cout << "peek(2)   : " << s.peek(2)       << "\n";
        cout << "peek(5)   : " << s.peek(5)       << "\n";

        cout << "Popped: " << s.pop() << "\n";
        s.display();

        cout << "Size: " << s.getSize() << "\n";
    }catch(const out_of_range& e){
        cout << "Out of Range Error: "<<e.what() <<"\n";
    }catch (const underflow_error& e) {
        cout << "Underflow Error    : " << e.what() << "\n";
    }catch (const overflow_error& e) {
        cout << "Overflow Error     : " << e.what() << "\n";
    }
    return 0;
}