#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversel(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    
}


int main(){
    // Start
    struct Node* head;   
    struct Node* second;
    struct Node* third;
    
    // Allocates memory for Node in linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    // You can write code from start to end in c++ like this 
    // Node* head = new Node();
    // Node* second = new Node();
    // Node* third = new Node();
   
    // End


    // link first node to second node
    head->data = 56;
    head->next = second;

    // link second node to third node
    second->data = 80;
    second->next = third;

    // Terminate the list at third node
    third->data = 231;
    third->next = NULL;
    linkedListTraversel(head);

    free(head);
    free(second);
    free(third);
    return 0;
}
