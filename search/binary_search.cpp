#include<iostream>
using namespace std;

int binarySearch(const int a[],int size,int elem){
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(a[mid] == elem){
            return mid;
        }
        else if(a[mid] > elem){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    const int* arr = new int[10]{7,11,21,32,35,45,66,79,81,94};
    int size = 10;
    int elem = 21;
    int index = binarySearch(arr,size,elem);
    if(index >= 0) cout << "Element "<<elem<<" is found at "<<index+1<<" position.";
    else cout << "Element is not found.";
    delete[] arr;

    return 0;
}