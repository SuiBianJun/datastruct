//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/**
 * 希尔排序，也叫递减增量排序，是插入排序的一种更高效的改进版本。希尔排序是不稳定的排序算法。

　　 希尔排序是基于插入排序的以下两点性质而提出改进方法的：
    插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率
    但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位
    希尔排序通过将比较的全部元素分为几个区域来提升插入排序的性能。

     这样可以让一个元素可以一次性地朝最终位置前进一大步。然后算法再取越来越小的步长进行排序，
     算法的最后一步就是普通的插入排序，但是到了这步，
     需排序的数据几乎是已排好的了（此时插入排序较快）

     希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
     随着增量逐渐减少，每组包含的关键词越来越多，
     当增量减至1时，整个文件恰被分成一组，算法便终止。

     一般增量选择为len = len / 2 -> 1
 */

void shell_sort(){

    int n = 9;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};

    int m = n / 2;
    int temp = 0;
    while(m > 1) {
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j = j + m) {
                for(int k = j; k > 0; k = k - m) {
                    if(k - m >= 0) {// 保证k - m在数组范围内
                        if (arr[k] < arr[k - m]) {
                            temp = arr[k - m];
                            arr[k - m] = arr[k];
                            arr[k] = temp;
                        }
                    }
                }
            }
        }
        m = m / 2;
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]){
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}