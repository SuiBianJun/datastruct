//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/*
 * 归并排序
 *
 * 归并排序算法主要依赖归并(Merge)操作。归并操作指的是将两个已经排序的序列合并成一个序列的操作，归并操作步骤如下：

    申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
    设定两个指针，最初位置分别为两个已经排序序列的起始位置
    比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
    重复步骤3直到某一指针到达序列尾
    将另一序列剩下的所有元素直接复制到合并序列尾
 */

int n2 = 9;
int arr2[] = {4, 3, 9, 5, 6, 4, 8, 2, 7};

void merge_sort_test(){

    int start = 0;
    int end = 9;

    merge_sort(start, end);
    //merge(0, );

    //merge(0, 1, 3);

    for(int i = 0; i < n2; i++){
        printf("%d ", arr2[i]);
    }
}

void merge_sort(int start, int end){

    /*if(start == end)
        return;*/
    int mid = (start + end) / 2;
    if(start < mid && mid < end) {
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
    }
    merge(start, mid, end);
    //orderMerge2(arr2, start, mid, end);
    //return;

}

void merge(int start, int mid, int end){

    int temp[9] = {0};
    int k = 0;

    int l = start;
    int l2 = mid + 1;

    while(l <= mid && l2 <= end){
        if(arr2[l] > arr2[l2]){
            temp[k] = arr2[l2];
            k++;
            l2++;
        }else{
            temp[k] = arr2[l];
            k++;
            l++;
        }
    }

    if(l > mid){
       while(l2 <= end){
           temp[k] = arr2[l2];
           k++;
           l2++;
       }
    }

    if(l2 > end){
        while(l <= mid){
            temp[k] = arr2[l];
            k++;
            l++;
        }
    }

    for(int i = start, j = 0; i <= end; i++, j++){
        arr2[i] = temp[j];
    }

}

/*
 * 归并非递归
 *
 */

void merge_none_recursive(){

    /*int n = 10 ;
    int arr[] = {3, 4, 5, 9, 4, 6, 2, 8, 7, -1};*/

    int len = 2;

    for(int i = len; (i / 2) < n2; i *= 2){
        int j = 0;
        for(; j < n2; j += i){
            if(j + i - 1 >= n2)// 长度越界
                merge(j, j + i / 2 - 1, n2 - 1);
            else{
                /*if(j + i - 1 >= n2){// 长度越界
                    merge(j, j + i / 2 - 1, n2 - 1);
                }else*/
                merge(j, j + i / 2 - 1, j + i - 1);
            }

        }

    }

    //merge(4, 4, 5);

    for(int i = 0; i < n2; i++){
        printf("%d ", arr2[i]);
    }

}