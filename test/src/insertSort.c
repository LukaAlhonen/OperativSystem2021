#include <stdio.h>
#include <luka.h>

void insertionSort(int *arr, int size){
    // insertionsort for array of integers
    int key, i, j;
    for(i = 1; i < size; i++){
        key = arr[i];
        // for loop checks if current element is greater than key and
        // swaps with key if so untill end of arr
        for(j = i - 1; j > -1 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key; // put key in correct place
    }
}

void printArr(int *arr, int size){
    // print arr
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

int main() {
    int size = 10; // array size
    int arr[size]; // declare array arr of size size
    initArr(arr, size); // fill arr with random numbers from 0 - 50
    printf("Array before sorting:\n");
    printArr(arr, size); // print arr before insertionsort
    insertionSort(arr, size); // sort arr
    printf("Array after sorting:\n");
    printArr(arr, size); // print arr after sorting
    return 0;
}
