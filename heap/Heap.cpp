//
// Created by 26233 on 2018/5/28.
//

#include <stdio.h>

void heapInsert(int[], int, int);
int deleteMin(int[]);

/*int main() {

    int a[] = {5, 4, 7, 1, 2, 9, 3, 6, 8, 10};
    int i = 0;
    int heap[20] = {9999};
    heap[0] = 0;
    for(i = 1; i < 20; i++)
        heap[i] = 9999;
    for(i = 0; i < 10; i++)
        heapInsert(heap, a[i], 11);

    for(i = 0; i < 10; i++)
        printf("%d\n", deleteMin(heap));

    for(i = 0; i < 10; i++)
        heapInsert(heap, a[i], 11);

    return 0;
}*/

void heapInsert(int heap[], int data, int len){

    int seat = 0;
    int i = 1;

    for(; i < len; i++){
        if(heap[i] == 9999){
            seat = i;
            break;
        }
    }

    while(data < heap[seat / 2] && seat != 1){
        int temp = heap[seat / 2];
        heap[seat] = temp;
        heap[seat / 2] = data;
        seat = seat / 2;
    }
    heap[seat] = data;

}

int deleteMin(int heap[]){
    int seat = 1;
    int result = heap[1];

    int last = 0;
    int i = 1;
    while(heap[i] != 9999){
        i++;
    }

    last = heap[i - 1];
    //heap[i - 1] = 9999;

    while(heap[seat * 2] != 9999 && heap[seat * 2 + 1] != 9999){
        if(heap[seat * 2] > heap[seat * 2 + 1]){
            heap[seat] = heap[seat * 2 + 1];
            seat = seat * 2 + 1;
        }else{
            heap[seat] = heap[seat * 2];
            seat = seat * 2;
        }
    }

    /*if(heap[seat * 2] == 9999 && heap[seat * 2 + 1] == 9999){
        heap[seat] = last;
        heap[i - 1] = 9999;
    }else{
        // heap[seat * 2 + 1] ==9999
        if(seat == 1){
            heap[seat] = last;
        }else {
            heap[seat] = last;
        }
        heap[i - 1] = 9999;
    }*/


    if(seat == 1){
        heap[seat] = last;
    }else {
        heap[seat] = last;
    }
    heap[i - 1] = 9999;


    return result;

}