//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/**
 * 选择排序
 *
 * 初始时在序列中找到最小（大）元素，
 * 放到序列的起始位置作为已排序序列；
 * 然后，再从剩余未排序元素中继续寻找最小（大）元素，
 * 放到已排序序列的末尾。以此类推，直到所有元素均排序完毕
 */

void select_sort(){

    int n = 9;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};

    int index = 0;
    int temp = 0;

    for(int i = 0; i < n; i++){
        temp = arr[i];
        index = i;
        for(int j = i; j < n; j++){
            if(arr[j] < temp){
                temp = arr[j];
                index = j;
            }
        }

        arr[index] = arr[i];
        arr[i] = temp;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}
