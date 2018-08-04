//
// Created by 26233 on 2018/7/7.
//

#include <stdio.h>
#include <malloc.h>

typedef struct graph{
    int noedge;// flag of link of two point
    int vertice;// number of point
    int ** G;// matrix of graph
} Graph;

void createGraphMatricx(Graph*, int, int);// g vertics noedge
void printGraphMatricx(Graph*, int);// g vertics
void addEdge(Graph*, int, int, int);// g u v noedge

/*int main() {

    Graph g;
    int i = 0;
    int edge[] = {0,1, 0,3, 1,2, 1,3, 2,3};
    createGraphMatricx(&g, 4, 0);
    printGraphMatricx(&g, 4);
    for(i = 0; i < 10; i = i + 2){
        addEdge(&g, edge[i], edge[i + 1], 1);
    }
    printf("----------------\n");
    printGraphMatricx(&g, 4);

    return 0;
}*/

void createGraphMatricx(Graph* g, int vertice, int noedge){

    int i = 0, j = 0;
    g->noedge = noedge;
    g->vertice = vertice;
    g->G = (int **)malloc(vertice *  sizeof(int *));// malloc row point

    for(; i < vertice; i++){
        g->G[i] = (int *)malloc(vertice * sizeof(int));// malloc element memory
        for(j = 0; j < vertice; j++)
            g->G[i][j] = noedge;
        g->G[i][i] = 0;
    }
}

void printGraphMatricx(Graph* g, int vertics){
    Graph *tempg;
    tempg = g;
    int i = 0, j = 0;
    for(; i < vertics; i++){
        for(j = 0; j < vertics; j++)
            printf("%d ", tempg->G[i][j]);
        printf("\n");
    }
}

void addEdge(Graph* g, int u, int v, int noedge){
    Graph *tempg;
    tempg = g;
    tempg->G[u][v] = noedge;
    tempg->G[v][u] = noedge;
}