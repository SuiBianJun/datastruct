//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/**
 * 冒泡排序
 * 每次选出一个最大值（最小值）
 *
 */

void maopao(){

    int n = 9;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};

    int temp = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

/**
 * 鸡尾酒排序
 * 鸡尾酒排序，也叫定向冒泡排序，是冒泡排序的一种改进。
 * 此算法与冒泡排序的不同处在于从低到高然后从高到低，
 * 而冒泡排序则仅从低到高去比较序列里的每个元素
 */

void maopao2(){

    int n = 9;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};

    int left = 0, right = n;
    int temp = 0;

    while(left < right){

        for(int i = left; i < right - 1; i++){
            if(arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        for(int i = right - 1; i > 0; i--){
            if(arr[i] < arr[i - 1]){
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }

        left++;
        right--;

    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}