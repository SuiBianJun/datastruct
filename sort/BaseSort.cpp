//
// Created by 26233 on 2018/8/17.
//

#include "sort.h"

/*
 * 基数排序
 *
 * 基数排序又称为“桶子法”，从低位开始将待排序的数按照这一位的值放到相应的编号为0~9的桶中。
 * 等到低位排完得到一个子序列，再将这个序列按照次低位的大小进入相应的桶中，
 * 一直排到最高位为止，数组排序完成。
 */

void base_sort(){

    int n = 10 ;
    int arr[] = {123, 234, 564, 765, 876, 324, 651, 874, 432, 1997};

    int len = 4;

    int temp = 0;
    int s[10][10] = {0};

    for(int i  = 0; i < 4; i++){

        for(int j = 0; j < 10; j++){
            int k = 0;
            if(i == 0){
                temp = arr[j] % 10;

                while(s[temp][k] != 0){
                    k++;
                }

                s[temp][k] = arr[j];
            }else if(i == 1){
                temp = (arr[j] / 10) % 10;
                while(s[temp][k] != 0){
                    k++;
                }
                s[temp][k] = arr[j];
            }else if(i == 2){
                temp = (arr[j] / 100) % 10;
                while(s[temp][k] != 0){
                    k++;
                }
                s[temp][k] = arr[j];
            } else if(i == 3){
                temp = (arr[j] / 1000) % 10;
                while(s[temp][k] != 0){
                    k++;
                }
                s[temp][k] = arr[j];
            }
        }

        int p = 0;

        for(int k = 0; k < 10; k++)
            for(int l = 0; l < 10; l++){
            if(s[k][l] != 0){
                arr[p] = s[k][l];
                p++;
                s[k][l] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }


}