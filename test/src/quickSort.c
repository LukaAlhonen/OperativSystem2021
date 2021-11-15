#include <stdio.h>
#include <luka.h>

#define A = 0

void insertionSort(int *arr, int left, int right){
    // insertionsort for array of integers
    int key, i, j;
    for(i = left + 1; i < right + 1; i++){
        key = arr[i];
        // for loop checks if current element is greater than key and
        // swaps with key if so untill end of arr
        for(j = i - 1; j > -1 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key; // put key in correct place
    }
}

int partition(int *arr, int left, int right){
    // partition array and return pivot
    int pivot = arr[right]; // set last element as pivot
    int i = left - 1;
    
    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, right);
    return (i+1); // return pivot
}

void quickSort(int *arr, int left, int right){
    int cutoff = 20;
    if((left + cutoff) <= right){
        // do quicksort
        int pivot = partition(arr, left, right);
        
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    } else {
        // do insertionsort
        insertionSort(arr, left, right);
    }
}

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

int main(){
    int size = 100;
    int arr[size];
    initArr(arr, size);
    printf("Array before quicksort:\n");
    printArr(arr, size);
    quickSort(arr, 0, size-1);
    printf("Array after quicksort:\n");
    printArr(arr, size);

    return 0;
}
