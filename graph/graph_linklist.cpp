//
// Created by 26233 on 2018/7/7.
//

#include <stdio.h>
#include <malloc.h>

typedef struct enode{
    int adjnode;// one linked node
    int w;// weight of edge
    struct enode* nextnode;// next node of list
} Enode;

typedef struct graph{
    int vertices;// number of points
    Enode** G;// linklist of graph
} Graph;

void createGraph(Graph*, int);// g vertices
void createGraph2(Graph*, int);// g vertices// digraph
void addEdge2(Graph*, int, int, int);// g u v noedge
void addEdge3(Graph*, int, int, int);// g u v noedge // digraph
void printGraph(Graph*, int);
void printGraph2(Graph*, int);
void travel_dfs(Graph*, int *, int);// travel
void dfs(Graph*, int *, int, int);// search
void bfs(Graph*, int *, int);
int checkFlag(int *, int);

void topOrder(Graph *, int *);
int computeInDegree(Graph *, int *, int *);

void prim(Graph*, int *, int, int);
int computeMin(Graph*, int, int *);
int getPoint(Graph*, int *, int);

/*int main() {

    Graph g;
    Graph g2;
    int edge[] = {0,1,0,3, 1,0,1,2,1,3, 2,1,2,3, 3,0,3,1,3,2};// undigraph construct
    int edge2[] = {1,0,1,2, 2,3, 3,0,3,1};// digraph
    int edge3[] = {0,2,0,7, 1,2,1,3,1,4, 2,3, 3,5,3,6, 4,5, 7,8, 8,6};// digraph
    int edge4[] = {0,1,6, 0,2,1, 0,3,5,
                   1,0,6, 1,2,5, 1,4,3,
                   2,0,1, 2,1,5, 2,3,5, 2,4,6, 2,5,4,
                   3,0,5, 3,2,5, 3,5,2,
                   4,1,3, 4,2,6, 4,5,6,
                   5,2,4, 5,3,2, 5,4,6};// undigraph
    int i = 0, j = 0;
    int *flag;
    int *flag2;
    int* flag3;
    /*createGraph(&g, 4);
    createGraph(&g2, 4);
    //addEdge2(&g, 0, 1, 0);
    for(i = 0; i < 20; i = i + 2){
        addEdge2(&g, edge[i], edge[i + 1], 0);
    }
    printGraph(&g, 4);
    printf("-----------------");
    for(i = 0; i < 10; i = i + 2){
        addEdge2(&g2, edge2[i], edge2[i + 1], 0);
    }*/

    /*createGraph2(&g, 4);
    for(i = 0; i < 20; i = i + 2){
        addEdge3(&g, edge[i], edge[i + 1], 0);
    }
    //Graph *p;
    //p = &g;
    //printGraph(p, 4);
    printf("---------------------\n");
    flag = (int *)malloc(sizeof(4 * sizeof(int)));
    for(i = 0; i < 4; i++){
        flag[i] = 0;
    }
    //travel_dfs(&g, flag, 3);
    //dfs(&g, flag, 3, 1);
    bfs(&g, flag, 3);*/

    /*createGraph2(&g, 9);
    for(i = 0; i < 22; i = i + 2){
        addEdge3(&g, edge3[i], edge3[i + 1], 0);
    }

    printGraph2(&g, 9);
    printf("-------------------\n");
    flag2 = (int *)malloc(sizeof(9 * sizeof(int)));
    for(i = 0; i < 9; i++){
        flag2[i] = 0;
    }
    topOrder(&g, flag2);*/


    /*createGraph2(&g, 6);
    for(i = 0; i < 60; i = i + 3){
        addEdge3(&g, edge4[i], edge4[i + 1], edge4[i + 2]);
    }
    printGraph2(&g, 6);
    flag3 = (int *)malloc(sizeof(6 * sizeof(int)));
    for(i = 0; i < 6; i++){
        flag3[i] = 0;
    }
    prim(&g, flag3, 6, 0);
    return 0;
}*/

void createGraph(Graph* g, int vertices){

    int i = 0;
    g->vertices = vertices;
    g->G = (Enode **)malloc(vertices * sizeof(Enode *));
    for(; i < vertices; i++)g->G[i] = NULL;
    /*{
        g->G[i] = (Enode *)malloc(sizeof(Enode *));
        g->G[i]->nextnode = NULL;
    }*/
}

void createGraph2(Graph* g, int vertices){

    int i = 0;
    g->vertices = vertices;
    g->G = (Enode **)malloc(vertices * sizeof(Enode *));
    for(; i < vertices; i++)
    {
        g->G[i] = (Enode *)malloc(sizeof(Enode));
        g->G[i]->nextnode = NULL;
        g->G[i]->adjnode = i;
        g->G[i]->w = 0;
    }
}

void addEdge2(Graph* g, int u, int v, int noedge){

    Graph* tempg;
    tempg = g;
    Enode *enode2;
    enode2 = (Enode *)malloc(sizeof(Enode));
    enode2->adjnode = v;
    enode2->w = noedge;
    enode2->nextnode = tempg->G[u];
    tempg->G[u] = enode2;
    //free(&enode2);
}

void addEdge3(Graph* g, int u, int v, int noedge){

    Graph* tempg;
    tempg = g;
    Enode *enode2;
    enode2 = (Enode *)malloc(sizeof(Enode));
    enode2->adjnode = v;
    enode2->w = noedge;
    enode2->nextnode = tempg->G[u]->nextnode;
    tempg->G[u]->nextnode = enode2;
    //free(&enode2);
}

void printGraph(Graph* g, int vertices){
    Graph* tempg;
    //tempg = (Graph *)malloc(sizeof(Graph *));
    tempg = g;
    int i = 0;
    for(; i < vertices; i++){
        if(tempg->G[i] != NULL){// this way maybe cause problem for run
            while(tempg->G[i] != NULL){
                printf("%d ", tempg->G[i]->adjnode);
                tempg->G[i] = tempg->G[i]->nextnode;
            }
        }
        printf("\n");
    }
}

void printGraph2(Graph* g, int vertices){
    Graph* tempg;
    //tempg = (Graph *)malloc(sizeof(Graph *));
    tempg = g;
    Enode *node;
    //node = (Enode *)malloc(sizeof(Enode));
    int i = 0;
    for(; i < vertices; i++){
        node = tempg->G[i];
        //if(node != NULL){
            while(node != NULL){
                printf("%d ", node->adjnode);
                node = node->nextnode;
            }
        //}
        printf("\n");
    }
    //free(node);
}

void travel_dfs(Graph* tempg, int *flag, int point){
    //int *a;
    //a = (int *)malloc(sizeof(int) * vertices);
    Graph *g;
    g = tempg;
    if(flag[point] == 0){
        printf("%d ", g->G[point]->adjnode);
        flag[point] = 1;
        while(g->G[point]->nextnode != NULL){
            travel_dfs(g, flag, g->G[point]->nextnode->adjnode);
            g->G[point] = g->G[point]->nextnode;
        }
    }
}

void dfs(Graph* tempg, int *flag, int point, int data){
    //int *a;
    //a = (int *)malloc(sizeof(int) * vertices);
    Graph *g;
    g = tempg;

    if (flag[point] == 0) {
        if(g->G[point]->adjnode == data){
            printf("\nhave find\n");
            flag[point] = 1;
            return;
        }else {
            flag[point] = 1;
            while (g->G[point]->nextnode != NULL) {
                dfs(g, flag, g->G[point]->nextnode->adjnode, data);
                g->G[point] = g->G[point]->nextnode;
            }
        }
    }

}

void bfs(Graph* g, int *flag, int point){
    Graph *tempg;
    Enode *node;
    tempg = g;
    node = g->G[point];

    /*if(flag[point] == 0){
        printf("%d ", point);
        flag[point] = 1;
    }*/

    while(node != NULL && checkFlag(flag, 4) == 0){
        if(flag[node->adjnode] == 0){
            printf("%d ", node->adjnode);
            flag[node->adjnode] = 1;
        }
        node = node->nextnode;
    }
    node = g->G[point]->nextnode;
    while(node != NULL && checkFlag(flag, 4) == 0){
        bfs(g, flag, node->adjnode);
        node = node->nextnode;
    }
}

int checkFlag(int *flag, int len){
    int i = 0;
    for(; i < len; i++){
        if(flag[i] == 0)
            return 0;
    }
    return 1;
}

void topOrder(Graph* g, int *flag){
    int inDegree[9];
    int i = 0, point = 0;
    Graph *tempg;
    Enode *node;
    tempg = g;
    //point = computeInDegree(tempg, inDegree, flag);

    for(i = 0; i < 9; i++)
        inDegree[i] = 0;

    while(checkFlag(flag, 9) == 0){
        tempg = g;
        point = computeInDegree(tempg, inDegree, flag);
        if(point >= 0){
            printf("C%d ", point);
        }
        for(i = 0; i < 9; i++){
            inDegree[i] = 0;
        }
    }
    printf("\ntopOrder done\n");
}

int computeInDegree(Graph* g, int* inDegree, int* flag){
    Graph* tempg;
    Enode* node;
    tempg = g;
    int i = 0;
    for(i = 0; i < 9; i++){// compute indegeree
        if(flag[i] == 0) {
            node = tempg->G[i]->nextnode;
            while (node != NULL) {
                inDegree[node->adjnode]++;
                node = node->nextnode;
            }
        }
    }
    for(i = 0; i < 9; i++){
        if(inDegree[i] == 0 && flag[i] == 0){
            flag[i] = 1;
            return i;
        }
    }
    return -1;
}

void prim(Graph* g, int* flag, int vertices, int point){

    Graph* tempg;
    tempg = g;

    int temppoint;
    while(checkFlag(flag, vertices) == 0){
        if(flag[point] == 0){
            printf("%d ", point);
            flag[point] = 1;
            temppoint = computeMin(tempg, point, flag);
            if(temppoint == point){
                if((point = getPoint(tempg, flag, vertices)) < 0)
                    continue;
            }else{
                point = temppoint;
            }
        }
    }
}

int computeMin(Graph* g, int point, int *flag){

    Graph* tempg;
    tempg = g;
    Enode *node;
    int w = 1000;
    node = tempg->G[point]->nextnode;
    while(node != NULL){
        if(flag[node->adjnode] == 0){
            if(node->w < w){
                w = node->w;
                point = node->adjnode;
            }
        }
        node = node->nextnode;
    }
    return point;
}

int getPoint(Graph* g, int *flag, int vertices){

    int i = 0;
    for(; i < vertices; i++){
        if(flag[i] == 0){
            return i;
        }
    }
    return -1;
}