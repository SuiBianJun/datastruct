//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/*
 * 堆排序
 *
 * 由输入的无序数组构造一个最大堆，作为初始的无序区
    把堆顶元素（最大值）和堆尾元素互换
    把堆（无序区）的尺寸缩小1，并调用heapify(A, 0)从新的堆顶元素开始进行堆调整
    重复步骤2，直到堆的尺寸为1

    大顶堆的建立：
    向当前位置site插入数据，比较 site / 2处的值是否满足堆条件，不满足进行交换，并递归地处理直到堆顶
 */

void heap_sort(){

    int n = 8;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8};

    int temp[n + 1] = {0};// 第0个位置空出来

    int site = 1;
    int tempdata = 0;
    temp[site] = arr[0];

    /*for (int i = 1; i < n; i++) {
        site = i + 1;
        temp[site] = tempdata = arr[i];
        while (tempdata > temp[site / 2] && site != 1) {

            int x = temp[site / 2];
            temp[site / 2] = tempdata;
            temp[site] = x;

            site /= 2;
        }
    }*/

    for(int j = 0; j < n; j++) {
        site = 1;
        temp[site] = arr[0];
        for (int i = 1; i < n - j; i++) {// 每次少一个以排序的数据
            site = i + 1;
            temp[site] = tempdata = arr[i];
            while (tempdata > temp[site / 2] && site != 1) {// 调整堆结构

                int x = temp[site / 2];
                temp[site / 2] = tempdata;
                temp[site] = x;

                site /= 2;
            }
        }

        for(int i = 1; i < n - j + 1; i++){// 只把未排序的数据复制到待排数组中
            arr[i - 1] = temp[i];
        }

        tempdata = arr[0];
        arr[0] = arr[n - j - 1];
        arr[n - j - 1] = tempdata;// 把最大的数据交换到最后面
    }

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);



}
