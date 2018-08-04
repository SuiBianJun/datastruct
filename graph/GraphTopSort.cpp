//
// Created by 26233 on 2018/6/1.
//

#include <stdio.h>

void buildGraph(int[], int);
void topSort(int[], int);

/*int main() {

    int g[] = {1,2,1,4,1,3, 2,4,2,5, 3,6, 4,3,4,6,4,7, 5,4,5,7, 6,0, 7,0};
    topSort(g, 26);
    return 0;
}*/

void topSort(int g[], int len){
    int count[7] = {0, 0, 0, 0, 0, 0, 0};
    int i = 1, j = 0, k = 0, q = 0;
    for(; k < 7; k++) {
        i = 1;
        q = 0;
        for(; q < 7; q++)
            count[q] = 0;
        for (; i < len; i = i + 2) {
            count[g[i] - 1]++;
        }

        j = 0;
        while (j < 7) {
            if (count[j] == 0) {
                printf("%d \n", j + 1);

                i = 1;
                for (; i < len; i = i + 2) {
                    if(g[i - 1] == j + 1){
                        g[i] = j + 1;
                    }
                }

                break;
            }
            j++;
        }
    }
}