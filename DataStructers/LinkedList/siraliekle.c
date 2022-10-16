#include <stdio.h>
#include <stdlib.h>
struct n{
 int x;
 struct n * next;
};
typedef struct n node;

void bastir(node *r){
 while(r!=NULL){
  printf("%d ",r->x);
  r=r->next;
 }
}
void ekle(node *r, int x){
 while(r->next!=NULL){
  r = r -> next;
 }
 r->next = (node*)malloc(sizeof(node));
 r->next->x = x;
 r->next->next = NULL;
}
node * ekleSirali(node * r, int x){
 if(r==NULL){//linklist bossa
  r=(node*)malloc(sizeof(node));
  r->next= NULL;
  r->x = x;
  return r;
 }
 if(r->x > x){ // ilk elemandan kucuk durumu
 // r degisiyor
  node * temp = (node*)malloc(sizeof(node));
  temp -> x = x;
  temp -> next = r;
  return temp;
 }
 node * iter = r;
 while (iter -> next != NULL && iter ->next-> x < x){
  iter= iter -> next;
 }
 node * temp = (node*)malloc(sizeof(node));
 temp -> next = iter -> next;
 iter -> next = temp;
 temp -> x = x;
 return r;
}
int main(){
 node * root;
 root = NULL;
 printf("5 DÜĞÜMLÜ İLK BAĞLI LİSTEYİ GİRİN");
 int z;
 int a;
 int h;
 int i;
 int d;
 scanf("%d",&z);
 scanf("%d",&a);
 scanf("%d",&h);
 scanf("%d",&i);
 scanf("%d",&d);
 root = ekleSirali(root,z);
 root = ekleSirali(root,a);
 root = ekleSirali(root,h);
 root = ekleSirali(root,i);
 root = ekleSirali(root,d);
 bastir(root);
}