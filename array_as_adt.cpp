#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int* base_address;
};

void createArray(struct myArray *a,int tSize,int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->base_address = (int *)malloc(tSize*sizeof(int));
}

// void show(struct myArray a){
//     for(int i=0;i<a.used_size;i++){
//         printf("%d\n",a.base_address[i]);
//     }
// } We use function like this this the the example of call by value but programmer did not use it because if the array is large it copy the whole the array which make the program slower.

void show(struct myArray * a){
    for(int i=0;i<a->used_size;i++){
        printf("%d\n",a->base_address[i]);
    }
}

void set(struct myArray * a){
    for(int i=0;i<a->used_size;i++){
        printf("Enter Element %d: \t",i);
        scanf("%d",&(a->base_address[i]));
    }
}

int main(){
    struct myArray marks;
    createArray(&marks,10,2);
    set(&marks);
    show(&marks);
    return 0;
}



// When i pass array in the function line this myFunction(array) it basically pass the base address of the array so it acts like the pointer what changes will i do to an array in function it reflects the original array but when i passs the variable in the function it copy the variable value to the function so we want to pass the variable in the function like this myFunc(&x)