#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    struct n * next;
};
typedef struct n node;

void yazdir (node *r){
    while(r!=NULL){
        printf("%d ", r->x);
        r= r->next;
    }
}


void ekle (node*r, int x){
    while (r ->next!=NULL){
        r = r-> next;
        } 
        r ->next = (node*) malloc(sizeof(node));
        r ->next ->x = x;
        r ->next ->next =NULL;     
}

int main(){
    int i=0;
    node *root;
    root = (node*) malloc(sizeof(node));
    root ->next =NULL;
    root -> x = i;
    node * iter;
    iter = root;
    for(i=1;i<5;i++){
        ekle(root, i*10);
        /*iter ->next =(node*) malloc(sizeof(node));
        iter=iter->next;
        iter -> x = i*10;
        iter ->next = NULL;*/
    }
    yazdir(root);
}