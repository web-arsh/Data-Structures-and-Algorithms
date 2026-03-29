#include<iostream>
using namespace std;

int linearSearch(const int a[],int size,int elem){
    if(size == -1) return -1;    
    if(a[size] == elem){
        return size;
    }

    return linearSearch(a,size-1,elem);
}

int main(){
    const int* arr = new int[5]{43,52,23,64,37};
    int size = 5;
    int elem = 37;
    int index = linearSearch(arr,size-1,elem);
    if(index >= 0) cout << "Element "<<elem<<" is found at "<<index+1<<" position.";
    else cout <<"Element is not found.";

    delete[] arr;
    return 0;
}