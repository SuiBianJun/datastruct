//
// Created by 26233 on 2018/8/15.
//

#include "sort.h"

/**
 * 插入排序
 *
 * 对于未排序数据(右手抓到的牌)，
 * 在已排序序列(左手已经排好序的手牌)中从后向前扫描，
 * 找到相应位置并插入
 */

void insert_sort(){

    int n = 9;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};

    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j >= 1; j--){
            if(arr[j] < arr[j - 1]){
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}
/**
 * 插入排序改进
 * 如果比较操作的代价比交换操作大的话，
 * 可以采用二分查找法来减少比较操作的次数，
 * 我们称为二分插入排序
 */

int n = 9;
int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};

void insert_sort2(){

    /*int n = 9;
    int arr[] = {3, 1, 5, 9, 4, 6, 2, 8, 7};*/

    int index = 0;
    int temp = 0;
    for(int i = 1; i < n; i++){
        //temp = arr[i];
        if(arr[i] < arr[i - 1]) {
            index = insert_binary(arr, i);
            /*temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;*/

            temp = arr[i];

            for(int j = i; j > index; j--){
                arr[j] = arr[j - 1];
            }

            arr[index] = temp;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int insert_binary(int arr[], int index){
    int min = 0;
    int max = index - 1;

    int v = arr[index];

    int mid = (index - 1) / 2;

    while(min < mid && mid < max){
        if(arr[mid] == v){
            return mid;
        }else if(arr[mid] > v){
            max = mid;
        }else{
            min = mid;
        }

        mid = (min + max) / 2;
    }

    if(arr[mid] > v)
        return mid;
    else
        return mid + 1;

}