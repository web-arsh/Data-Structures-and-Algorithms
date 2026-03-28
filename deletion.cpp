#include<iostream>

using namespace std;

void display(int a[],int size){
    for(int i=0;i<size;i++){
        cout << a[i] <<",";
    }
    cout<<endl;
}
int erase(int a[],int* size,int idx){
    if(idx < 0 || idx >= *size) {
        cout << "Your element cann't be deleted. \n";
        return -1;
    }
    for(int i=idx;i<*size-1;i++){
        a[i] = a[i+1];
    }
     (*size)--;
    return 0;
}

int main(){
    int* arr = new int[100]{34,56,32,34};
    int size = 4;
    int capacity = 100;
    int index = 1;
    display(arr,size);
    erase(arr,&size,index);
    display(arr,size);
    delete[] arr;

    return 0;
}