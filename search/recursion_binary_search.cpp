#include<iostream>
using namespace std;

int binarySearch(const int a[],int h,int l,int elem){
    if(l <= h){
        int mid = l + (h -l)/2;
        if(a[mid] == elem){
            return mid;
        }
        else if(a[mid] > elem){
            return binarySearch(a,mid-1,l,elem);
        }
        else{
            return binarySearch(a,h,mid+1,elem);
        }
    }
    return -1;
}

int main(){
    const int* arr = new int[10]{7,11,21,32,35,45,66,79,81,94};
    int size = 10;
    int elem = 21;
    int low = 0;
    int high = size - 1;
    int index = binarySearch(arr,high,low,elem);
    if(index >= 0) cout << "Element "<<elem<<" is found at "<<index+1<<" position.";
    else cout << "Element is not found.";
    delete[] arr;

    return 0;
}