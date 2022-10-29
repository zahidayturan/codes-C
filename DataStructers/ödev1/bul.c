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
    printf("------------------------LİSTE-------------------------\n");
    while(iter != NULL){
        printf(" AD: %s \n", iter -> ad);
		iter = iter -> next;
	}
	printf("\n");
}

void bul()
{
    struct rehber *iter;
    char f[MAX_LEN];
    iter=first;
    int result;
    printf("Aranacak Adı girin: ");
    scanf("%s",&f);
    //result = strcmp(iter -> ad, f);
    while (iter != NULL){
        if (strcmp(iter -> ad, f)==0){
            printf("Aradığınız isim '%s' bulundu.\n",iter->ad);  
        }
        else{
            printf("Aradığınız isim Bulunamadı\n"); 
        }
     iter = iter ->next;
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
            case 4: 
                /*char a;
                printf("Bulunması için Ad giriniz: ");
                scanf("%c",&a);*/
                bul();
            break;
        }
        printf("Devam etmek isterseniz 1, Çıkmak için 0 :\n ");
        scanf("%d",&zhd);
    }while(zhd!=0); 
return 0;
}