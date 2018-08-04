//
// Created by 26233 on 2018/5/30.
//
#include <stdio.h>

void mergeSort(int[], int, int);
void orderMerge(int[], int, int, int);

/*int main(){

    int a[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15, 1, 100, 2};
    mergeSort(a, 0, 15);

    int i = 0;

    for(; i < 16; i++)
        printf("%d ", a[i]);


    *//*int b[4] = {6, 5, 1, 2};
    int i = 0;
    orderMerge(b, 0, 1, 2);
    for(; i < 4; i++){
        printf("%d ", b[i]);
    }*//*

    return 0;
}*/

void mergeSort(int arr[], int min, int max){

    int mid = (min + max) / 2;
    if(min + 1 < max){
        mergeSort(arr, min, mid);
        mergeSort(arr, mid + 1, max);
    }

    orderMerge(arr, min, mid, max);
    //return;
}

void orderMerge(int arr[], int min, int mid, int max){

    int p = 0;
    int temp[max + 1];
    int i = min, j = mid + 1, k = 0;
    while(i <= mid && j <= max){

        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
        //i++;
        //j++;
    }

    if(i > mid && j > max){

        for(; min < max + 1; min++) {
            arr[min] = temp[p];
            p++;
        }
        return;
    }

    if(i > mid && j <= max){
        while(j <= max){
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    if(i <= mid && j > max){
        while(i <= mid){
            temp[k] = arr[i];
            k++;
            i++;
        }
    }

    for(; min < max + 1; min++) {
        arr[min] = temp[p];
        p++;
    }

}
