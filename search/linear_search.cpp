#include<iostream>
using namespace std;

int linearSearch(const int a[],int elem,int size){
    for(int i=0;i<size;i++){
        if(a[i] == elem) return i;
        
    }
    return -1;
}


int main() {
    const int* arr = new int[10]{10,23,2,34,21,80,24,7,3,9};
    int size = 10;
    int elem = 24;
    int search = linearSearch(arr,elem,size);
    if (search >= 0) cout << "Element "<<elem<<" at "<<search+1<<" position.";
    else cout << "Element not found";

    delete[] arr;
    return 0;
}