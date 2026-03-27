#include<stdio.h>

void display(int a[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d,",a[i]);
    } 
    printf("\n");
}

int insertion(int a[],int* len,int cap,int val,int pos){
    if(*len >= cap || pos < 0 || pos > *len){
        printf("Cannot insert: either array full or position invalid\n");
        return -1;
    }
    // Loops from length of an array to index
    for(int i = (*len)-1; i>=pos;i--){
        a[i+1] = a[i];
    }
    a[pos] = val;
    (*len)++;
    return 0;
}

int main() {
    int arr[100] = {2,90,45,23,89};
    int size = 5, capacity = 100, index = 5,num = 66;
    display(arr,size);
    insertion(arr,&size,capacity,num,index);
    display(arr,size);

    return 0;
}