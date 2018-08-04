//
// Created by 26233 on 2018/5/29.
//

#include <stdio.h>

void shellSort(int[], int);

/*int main() {

    int a[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15, 1};
    shellSort(a, 14);

    int i = 0;

    for(; i < 13; i++)
        printf("%d ", a[i]);

    return 0;
}*/

void shellSort(int arr[], int len){

    int i = len / 2;
    int j = 0, k = 0;

    for(; i > 0; i = i / 2){
        for(j = 1; j < len; j = j + i){
            for(k = j; k > 0; k = k - i){
                if(arr[k] < arr[k - 1]){
                    int temp = arr[k];
                    arr[k] = arr[k - 1];
                    arr[k - 1] = temp;
                }
            }
        }
    }

}