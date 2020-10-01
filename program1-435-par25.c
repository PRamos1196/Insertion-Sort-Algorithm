#include <stdio.h>
#include <stdlib.h>

int COMPCOUNT;

int smaller(int* array, int x, int y){
    COMPCOUNT++;
    return (array[x] < array[y])?1:0;
}

int swap(int* array, int x, int y){
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void insertionSort(int* arr, int size) {
    COMPCOUNT = 0;
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && smaller(arr, j, j - 1)) {
            swap(arr, j, j-1);
            j--;
        }
    }
}

void printArray(int* array, int size){
    int i = 0;
    while(i < size){
        printf("%d ", array[i]);
        i++;
    }
}

int* makeAnArray(int size, int c){
    int* arr = malloc(size * sizeof(int));
    int i = 0;
    switch(c){
        case(1):
            while(i < size){arr[i] = size-i; i++;}
            break;
        case(2):
            while(i < size){arr[i] = i; i++;}
            break;
        case(3):
            for(i=0;i<size;i++){arr[i] = rand()%size;}
            break;
    }
    return arr;
}

int main() {
    
    int* worstcase = makeAnArray(32, 1);
    printf("Unsorted Array: ");
    printArray(worstcase, 32);
    insertionSort(worstcase, 32);
    printf("\nWorst case sorted: \n");
    printArray(worstcase, 32);
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);

    int* worstcase_100 = makeAnArray(100, 1);
    insertionSort(worstcase_100, 100);
    printf("\nWorst case has sorted 100 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);

    int* worstcase_1000 = makeAnArray(1000, 1);
    insertionSort(worstcase_1000, 1000);
    printf("\nWorst case has sorted 1000 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* worstcase_10000 = makeAnArray(10000, 1);
    insertionSort(worstcase_10000, 10000);
    printf("\nWorst case has sorted 10000 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);


    printf("\n");


    int* bestcase = makeAnArray(32, 2);
    printf("Unsorted Array: ");
    printArray(bestcase, 32);
    insertionSort(bestcase, 32);
    printf("\nBest case: sorted: ");
    printArray(bestcase, 32);
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* bestcase_100 = makeAnArray(100, 2);
    insertionSort(bestcase_100, 100);
    printf("\nBest case has sorted 100 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* bestcase_1000 = makeAnArray(1000, 2);
    insertionSort(bestcase_1000, 1000);
    printf("\nBest case has sorted 1000 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* bestcase_10000 = makeAnArray(10000, 2);
    insertionSort(bestcase_10000, 10000);
    printf("\nBest case has sorted 10000 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    
    printf("\n");


    int* averagecase = makeAnArray(32, 3);
    printf("Unsorted Array: ");
    printArray(averagecase, 32);
    insertionSort(averagecase, 32);
    printf("\nAverage case sorted: ");
    printArray(averagecase, 32);
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* averagecase_100 = makeAnArray(100, 3);
    insertionSort(averagecase_100, 100);
    printf("\nBest case has sorted 100 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* averagecase_1000 = makeAnArray(1000, 3);
    insertionSort(averagecase_1000, 1000);
    printf("\nBest case has sorted 1000 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
    
    int* averagecase_10000 = makeAnArray(10000, 3);
    insertionSort(averagecase_10000, 10000);
    printf("\nAverage case has sorted 10000 elements... \n");
    printf("\nCOMPCOUNT: %d\n", COMPCOUNT);
}