#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

struct Node{
    int data;
    int height;
    Node* left;
    Node* right;
};
void insert2(Node *root, int data, int height);
void traversalLRD(Node*);
void traversalLRD2(Node*, Node*);
int computeHeight(Node*);
void leftRotate(Node*, Node*, Node*);
int rightRotate(Node*, Node*, Node*);
void leftRightRotate(Node*, Node*, Node*);
void rightLeftRotate(Node*, Node*, Node*);
Node* findParent(Node*, Node*);
void checkAndChange(Node* root);

void insert(Node*, int);
Node* search(Node*, int);
void deleteNode(Node*, Node*, int);//
void traversal(Node*);
void traversalInsert(Node*, Node*);

/*int main(int argc, char *argv[]) {

    Node *root = (Node *)malloc(sizeof(struct Node));
    root->left = NULL;
    root->right = NULL;
    root->data = 0;
    root->height = 0;
    int a[] = {5, 1, 2, 9, 4, 6, 3, 8, 7};
    int i = 0;
    for(; i < 9; i++){
        insert2(root, a[i], 0);
        //checkAndChange(root);
        traversalLRD2(root, root);
    }
    insert2(root, 10, 0);
    Node *temproot = root;
    //checkAndChange(root);
    //traversalLRD2(temproot);
    //temproot = root;
    //printf("\nroot height = %d \n", computeHeight(temproot->right->right->right));

    *//*if(root->right != root->left)
        printf("aa");*//*

    return 0;

}*/

void insert(Node *root, int data){

    if(root->data == 0){
        root->data = data;
        return;
    }

    if(root->data >= data){
        if(root->left != NULL){

            insert(root->left, data);
        }
        else{
            Node *newNode = (Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->left = newNode;
        }
    }

    if(root->data < data){
        if(root->right != NULL){
            insert(root->right, data);
        }
        else{
            Node *newNode = (Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
        }
    }
}

void insert2(Node *root, int data, int height){

    if(root->data == 0){
        root->data = data;
        return;
    }

    if(root->data >= data){
        height++;
        if(root->left != NULL){
            //height++;
            insert2(root->left, data, height);
        }
        else{
            Node *newNode = (Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = height;
            root->left = newNode;
        }
    }

    if(root->data < data){
        height++;
        if(root->right != NULL){
            insert2(root->right, data, height);
        }
        else{
            Node *newNode = (Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = height;
            root->right = newNode;
        }
    }
}

void avlInsert(Node *root, int data, int height){

    //Node *temproot = root;

    if(root->data == 0){
        root->data = data;
        return;
    }

    if(root->data >= data){
        height++;
        if(root->left != NULL){
            //height++;
            avlInsert(root->left, data, height);
        }
        else{
            Node *newNode = (Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = height;
            root->left = newNode;

        }
    }

    if(root->data < data){
        height++;
        if(root->right != NULL){
            avlInsert(root->right, data, height);
        }
        else{
            Node *newNode = (Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = height;
            root->right = newNode;
        }
    }
}

Node* search(Node *root, int data){

    if(root->data == data){
        return root;
    }else{
        if(root->data > data){
            if(root->left != NULL){
                printf("%d\n", root->data);
                search(root->left, data);
            }else{
                return NULL;
            }
            //search(root->left)
        }else{
            if(root->right != NULL){
                printf("%d\n", root->data);
                search(root->right, data);
            }else
                return NULL;
        }

    }


}

void deleteNode(Node *root, Node* parentNode, int data){

    if(root->data == data){
        if(root->right == NULL){
            parentNode->left = root->left;
        }else if(root->left == NULL){
            parentNode->right = root->right;
        }else{
            traversalInsert(root->left, root->right);
            parentNode->right = root->right;
        }
    }else{
        if(root->data > data){
            if(root->left != NULL){
                deleteNode(root->left, root, data);
            }else{
                printf("do not exist");
                return;
            }
        }else{
            if(root->right != NULL){
                deleteNode(root->right, root, data);
            }else {
                printf("do not exist");
                return;
            }
        }

    }


}

void traversal(Node *root){
    if(root->left != NULL){
        traversal(root->left);
    }
    printf("%d\n", root->data);
    if(root->right != NULL)
        traversal(root->right);

}

void traversalLRD(Node *root){
    if(root->left != NULL){
        traversalLRD(root->left);
    }
    //printf("%d\n", root->data);
    if(root->right != NULL)
        traversalLRD(root->right);
    printf("%d height = %d\n", root->data, root->height);
}

void traversalLRD2(Node *root, Node *temproot){
    if(root->left != NULL){
        traversalLRD2(root->left, temproot);
    }
    //printf("%d\n", root->data);
    if(root->right != NULL)
        traversalLRD2(root->right, temproot);
    //printf("%d height = %d\n", root->data, root->height);
    if((computeHeight(root->left) - computeHeight(root->right)) > 1){
        if(computeHeight(root->left->right) > 1){
            leftRightRotate(root->left, root->left->right, root);
        }else
            leftRotate(root, root->left, temproot);
        //printf("%d \n", root->data);
    }else if((computeHeight(root->left) - computeHeight(root->right)) < -1){
        if(computeHeight(root->right->left) > 1){
            rightLeftRotate(root->right, root->right->left, root);
        }else
            rightRotate(root, root->right, temproot);
        //printf("%d \n", root->data);
    }
}

void traversalInsert(Node *root, Node* root2){
    if(root->left != NULL){
        traversalInsert(root->left, root2);
    }
    insert(root2, root->data);
    //printf("%d\n", root->data);
    if(root->right != NULL)
        traversalInsert(root->right, root2);

}

int computeHeight(Node *node){

    int h1 = 0, h2 = 0, h = 0;
    if(node == NULL)
        h = 0;
    if(node !=  NULL){
        h1 = computeHeight(node->left);
        h2 = computeHeight(node->right);
        h = (h1>=h2?h1:h2) + 1;

    }
    return h;
}

int rightRotate(Node *hNode, Node *lNode, Node* root){

    if(hNode == root){
        lNode->left = hNode;
        root = lNode;
    }else{

    }

}
void leftRotate(Node *hNode, Node *lNode, Node* root){


}

void leftRightRotate(Node *k1, Node *k2, Node *k3){


}

void rightLeftRotate(Node *k1, Node *k2, Node *k3){


}

Node* findParent(Node *root, Node *node){

    return  NULL;
}

void checkAndChange(Node *root){



}

