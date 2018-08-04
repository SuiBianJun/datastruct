//
// Created by 26233 on 2018/5/29.
//

#include <stdio.h>

void insertSort(int[], int);

/*int main() {

    int a[] = {34, 8, 64, 51, 32, 21};
    int i = 0;

    insertSort(a, 6);

    for(; i < 6; i++){
        printf("%d ", a[i]);
    }

    return 0;
}*/

void insertSort(int arr[], int len){

    int i = 0, j = 0;

    for(i = 1; i < len; i++){
        for(j = i; j >=1; j--){
            if(arr[j] < arr[j - 1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}