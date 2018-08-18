//
// Created by 26233 on 2018/8/15.
//

#ifndef DATASTRUCT_SORT_H
#define DATASTRUCT_SORT_H

#endif //DATASTRUCT_SORT_H

#include "../main.h"

/**
 * MaoPao.cpp
 * 冒泡
 */

void maopao();
void maopao2();

/*
 * SelectSort.cpp
 * 选择排序
 */
void select_sort();

/*
 * InsertSort2.cpp
 * 插入排序
 */

void insert_sort();
void insert_sort2();
int insert_binary(int [], int);

/*
 * ShellSort2.cpp
 * 希尔排序
 *
 */

void shell_sort();

/*
 * MergeSort3.cpp
 * 归并排序
 */

void merge_sort_test();
void merge_sort(int, int);
void merge(int, int, int);
void merge(int, int, int);
// 归并非递归算法
void merge_none_recursive();

/*
 * HeapSort.cpp
 * 堆排序
 *
 */

void heap_sort();

/*
 * QuikSort.cpp
 * 快速排序
 */
void quick_sort_test();
void quick_sort(int, int);


/*
 * BaseSort.cpp
 * 基数排序
 *
 */

void base_sort();