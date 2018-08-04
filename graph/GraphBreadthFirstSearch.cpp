//
// Created by 26233 on 2018/6/1.
//
#include <stdio.h>

void breadthFirstSearch(int[], int, int, int[]);

/*int main(){

    int g[] = {1,2,1,4, 2,4,2,5, 3,1,3,6, 4,3,4,6,4,7,4,5, 5,7, 6,0, 7,6};
    int flag[] = {0, 0, 0, 0, 0, 0, 0};
    breadthFirstSearch(g, 1, 26, flag);

    return 0;
}*/

void breadthFirstSearch(int g[], int id, int len, int flag[]){

    int i = 0, j = 0;

    if(flag[id - 1] == 0) {
        printf("%d ", id);
        flag[id - 1] = 1;
    }
    for(; i < len; i = i + 2){
        if(id == g[i]){
            j = i;
            while(g[j] == id){
                if(flag[g[j + 1] - 1] == 0) {
                    printf("%d ", g[j + 1]);
                    flag[g[j + 1] - 1] = 1;
                }
                j = j + 2;
            }
            while(g[i] == id) {
                breadthFirstSearch(g, g[i + 1], 26, flag);
                i = i + 2;
            }

            break;
        }
    }

    return;
}
