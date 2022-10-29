#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct rehber{
    char *ad[MAX_LEN];
    struct rehber *next;
};

struct rehber *first= NULL;


struct rehber *yeni(){
    return(
        (struct rehber *)malloc(sizeof(struct rehber))
        );
}

struct rehber *ekle(){
    struct rehber *iter;
    struct rehber *yenilenecek;
        if(first!=NULL){
        struct rehber *iter;
        struct rehber *yenilenecek;
        yenilenecek = yeni();
        iter = first;
        while(iter->next!=NULL){
        iter=iter->next;
        }
        printf("AD: \n"); scanf("%s",&yenilenecek->ad);
        iter -> next = yenilenecek;
        yenilenecek -> next= NULL;
        yazdir(first);
        }
        else{
            yenilenecek=yeni();
            first=yenilenecek;
            iter= first;
                printf("AD: \n"); scanf("%s",&yenilenecek->ad);
            yenilenecek -> next= NULL;
            yazdir(first);
        }
};

void yazdir(struct rehber *first){
    struct rehber *iter;
    iter = first;
    int i=1;
    printf("------------------------LİSTE-------------------------\n");
    while(iter != NULL){
        printf("(%d.kişi) AD: %s \n",i, iter -> ad);
		iter = iter -> next;
        i++;
	}
	printf("\n");
}
struct rehber *sil(){
    struct rehber *iter =first;
    struct rehber *ekiter;
    struct rehber *ek2iter;
    //iter = first;

    if(first == NULL){
        printf("Liste boş!\n");
        return first;
    }

    char *silinecekad[MAX_LEN];
    printf("Silinecek Kişinin Adını Giriniz: ");
    scanf("%s",&silinecekad);
    
    if (first->next==NULL)
    {
       if(strcmp(first -> ad, silinecekad)==0){
        printf("Listenin tek elemanı olan %s silindi. Artık liste boş.\n",silinecekad);
        ekiter = first;
        first = NULL;
        iter =NULL;
        free(ekiter);
        return first;
        } 
    }

    if (first->next->next==NULL)
    {
       if(strcmp(first -> ad, silinecekad)==0){
        printf("Listede bulunan %s silindi. Listede bir kişi kaldı.\n",silinecekad);
        ekiter = first;
        first = first ->next;
        iter = first;
        free(ekiter);
        return first;
        } 
        if(strcmp(first-> next -> ad, silinecekad)==0){
        printf("Listede bulunan %s silindi. Listede bir kişi kaldı.\n",silinecekad);
        ekiter = first->next;
        free(ekiter);
        first ->next =NULL;
        return first;
        } 
    }
    
    while (iter != NULL){
        //if (strcmp(iter -> ad, silinecekad)==0){
            if (strcmp(iter -> ad, silinecekad)==0){
            printf("Silindi1 %s\n",silinecekad);
            ekiter = iter;
            iter = iter ->next;
            first = iter;
            free(ekiter);
            return first;
        }
            if ((iter->next->next == NULL)&&(strcmp(iter->next-> ad, silinecekad)==0)){
            printf("Silindi2 %s\n",silinecekad);
            ekiter = iter ->next;
            free(ekiter);
            iter -> next = NULL;
            return first;
        }
            if (strcmp(iter -> next -> ad, silinecekad)==0){
            printf("Silindi3 %s\n",silinecekad);
            ek2iter = iter;
            ekiter = iter ->next;
            iter = iter ->next ->next;
            free(ekiter);
            ek2iter ->next = iter;
            return first;
        }
        //}
    iter = iter->next;
    }
    struct rehber *ek3iter =first;
    while (ek3iter != NULL)
    {
        if (strcmp(ek3iter->ad, silinecekad)!=0){
            printf("Aradığınız kişi '%s' bulunamadı.",silinecekad);
            break;
        }
        ek3iter = ek3iter -> next;
    }
}

int main()
{
    int zhd,dhz;
    do{
        printf("Telefon Rehberi\n ");
        printf("\n(1)-->Kişi Eklemek\n(2)-->Kişi Görüntülemek\n(3)-->Kişi Silmek\n(4)-->Kişi Bulmak\n");
        printf("İşlemi seçiniz:");
        scanf("%d",&dhz);
        
        switch(dhz)
        {
            case 1:
                ekle();
            break;
            case 2: 
                yazdir(first);
            break;
            case 3: 
                /*char a;
                printf("Bulunması için Ad giriniz: ");
                scanf("%c",&a);*/
                sil();
            break;
        }
        printf("Devam etmek isterseniz 1, Çıkmak için 0 :\n ");
        scanf("%d",&zhd);
    }while(zhd!=0); 
return 0;
}