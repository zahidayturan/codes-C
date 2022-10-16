#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n* next;
};
typedef struct n node;

void wiew(struct n* r){
    while(r != NULL){
        printf("-%d- ", r->x);
        r = r->next;
    }
}

void add_node(struct n** ref, int new_x){
    struct n* temp = malloc(sizeof(struct n*));

    struct n *last = *ref;

    temp->x = new_x;
    temp->next = NULL;

    if(*ref == NULL){
        *ref = temp;
        return;
    }  

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;
    return;
};

struct n* del_first_node(struct n *head){
    if(head == NULL) printf("list is empty");
    else{
        struct n *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main(){
    int xnum, y = 1, taken_data;

    struct n* head = NULL;
    struct n* body = NULL;
    struct n* end = NULL;
    struct n* merged = NULL;

    head = malloc(sizeof(struct n*));
    body = malloc(sizeof(struct n*));
    end = malloc(sizeof(struct n*));
    merged = malloc(sizeof(struct n*));

    head = del_first_node(head);
    body = del_first_node(body);
    end = del_first_node(end);
    merged = del_first_node(merged);

    printf("3 Bağlı Liste Oluşturuldu.\n");
    printf("Bir bağlı listede kaç veri bulunsun: ");
    scanf("%d", &xnum);    
    printf("Birinci Liste Üzerinde Düzenleme Yapıyorsunuz\n");
    
    while(xnum >= y){
        printf("%d. veri ",y);
        scanf("%d", &taken_data);
        add_node(&head,taken_data);
        y++;
    }
    y = 1;
    
    printf("\nİkinci Liste Üzerinde Düzenleme Yapıyorsunuz\n");
    while(xnum >= y){
        printf("%d. veri ", y);
        scanf("%d", &taken_data);
        add_node(&body,taken_data);
        y++;
    }
    y = 1;
    
    printf("\nÜçüncü Liste Üzerinde Düzenleme Yapıyorsunuz\n");
    while(xnum >= y){
    printf("%d. veri ", y);
        scanf("%d", &taken_data);
        add_node(&end,taken_data);
        y++;
    }
   
    printf("\n1.Liste : ");
    wiew(head);
    printf("\n2.Liste : ");
    wiew(body);
    printf("\n3.Liste : ");
    wiew(end);

    while(head != NULL){
        add_node(&merged, head->x);
        head = head->next;
    }
    while(body != NULL){
        add_node(&merged,body->x);
        body = body->next;
    }
    while(end != NULL){
        add_node(&merged, end->x);
        end = end->next; 
    }
    printf("\nBirleştirilmiş: ");
    wiew(merged);
}