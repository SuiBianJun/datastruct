//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/*
 * 快速排序
 *
 * 快速排序使用分治策略(Divide and Conquer)来把一个序列分为两个子序列。步骤为：

    从序列中挑出一个元素，作为"基准"(pivot).
    把所有比基准值小的元素放在基准前面，所有比基准值大的元素放在基准的后面（相同的数可以到任一边），
     这个称为分区(partition)操作。
    对每个分区递归地进行步骤1~2，递归的结束条件是序列的大小是0或1，这时整体已经被排好序了。
 */

int n3 = 10;
int arr3[] = {3, 1, 5, 9, 4, 6, 2, 8, 7, -1};

void quick_sort_test(){

    quick_sort(0, n3 - 1);

    for(int i = 0; i < n3; i++){
        printf("%d ", arr3[i]);
    }

}

void quick_sort(int left, int right){

    int temp_right = right;

    int index = left;
    int pivote = arr3[left];

    int temp = 0;

    if(left >= right)
        return;

    while(left < right){
        while(left < right && arr3[right] > pivote){
            right--;
        }

        temp = pivote;
        arr3[index] = arr3[right];
        arr3[right] = temp;

        index = right;

        while(left < right && arr3[left] < pivote){
            left++;
        }

        temp = pivote;
        arr3[index] = arr3[left];
        arr3[left] = temp;

        index = left;



    }

    quick_sort(0, index - 1);
    quick_sort(index + 1, temp_right);

}