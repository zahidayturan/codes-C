// İsmet Zahid AYTURAN - 21060607 - OMÜ Bilgisayar Müh.
// Veri Yapıları Dersi Bağlı Liste ile Rehber Yapma Ödevi
//30.10.2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct rehber{
    char ad[MAX_LEN];
    char soyad[MAX_LEN];
    char tel[MAX_LEN];
    char mail[MAX_LEN];
    struct rehber *next;
};
struct rehber *first= NULL;

struct rehber *yeni(){
    return((struct rehber *)malloc(sizeof(struct rehber)));
}

struct rehber *ekle(){
    struct rehber *iter;
    struct rehber *yenilenecek;
        if(first!=NULL){   //varsaekle();
        struct rehber *iter;
        struct rehber *yenilenecek;
            yenilenecek = yeni();
            iter = first;
            while(iter->next!=NULL){
            iter=iter->next;
            }
            printf("AD: \n"); scanf("%s",&yenilenecek->ad);
            printf("SOYAD: \n"); scanf("%s",&yenilenecek->soyad);
            printf("TEL NO: \n"); scanf("%s",&yenilenecek->tel);
            printf("e-MAİL: \n"); scanf("%s",&yenilenecek->mail);
        iter -> next = yenilenecek;
        yenilenecek -> next = NULL;
        yazdir(first);
        }
        else{
            yenilenecek=yeni();
            first=yenilenecek;
            iter= first;
                printf("AD: \n"); scanf("%s",&yenilenecek->ad);
                printf("SOYAD: \n"); scanf("%s",&yenilenecek->soyad);
                printf("TEL NO: \n"); scanf("%s",&yenilenecek->tel);
                printf("e-MAİL: \n"); scanf("%s",&yenilenecek->mail);
        yenilenecek -> next= NULL;
        yazdir(first);
        }
}

void yazdir(struct rehber *first){
    struct rehber *iter;
    iter = first;
    int i =1;
    printf("-----------------------------REHBER------------------------------\n");
    if (iter == NULL){
        printf("!!! Rehber BOŞ!\n");}
    
    while(iter != NULL){
        printf("%d--> AD: %s - SOYAD: %s - TEL NO: %s - e-MAİL: %s \n", i, iter->ad, iter->soyad, iter->tel, iter->mail);
		iter = iter -> next;
        i++;
	}
	printf("\n");
}

struct rehber *sil(){
    struct rehber *iter =first;
    struct rehber *ekiter;
    struct rehber *ek2iter;

    if(first == NULL){
        printf("!!! Liste boş!\n");
        return first;  }

    char *silinecekad[MAX_LEN];
    printf("Silinecek Kişinin Adını Giriniz: ");
    scanf("%s",&silinecekad);
    char *silineceksoyad[MAX_LEN];
    printf("Silinecek Kişinin Soyadını Giriniz: ");
    scanf("%s",&silineceksoyad);

    if (first->next==NULL){
       if((strcmp(first->ad, silinecekad)==0)&&(strcmp(first->soyad, silineceksoyad)==0)){
        printf("Listenin tek elemanı olan %s %s silindi. Artık liste boş.\n",silinecekad, silineceksoyad);
        ekiter = first;
        first = NULL;
        iter =NULL;
        free(ekiter);
        return first;
        }
        else{
            printf("!!! Silmek istediğiniz kişi '%s %s' yok!\n",silinecekad,silineceksoyad);
            return first;
        } 
    }

    if (first->next->next==NULL){
            if((strcmp(first->ad, silinecekad)==0)&&(strcmp(first->soyad, silineceksoyad)==0)){
                printf("Listede bulunan %s %s silindi. Listede bir kişi kaldı.\n",silinecekad,silineceksoyad);
                ekiter = first;
                first = first ->next;
                iter = first;
                free(ekiter);
            return first;
        }
            else{
                printf("!!! Silmek istediğiniz kişi '%s %s' yok!\n",silinecekad,silineceksoyad);
                return first;
            }   
            if((strcmp(first->next->ad, silinecekad)==0)&&(strcmp(first->next->soyad, silineceksoyad)==0)){
                printf("Rehberde bulunan %s %s silindi. Rehberde bir kişi kaldı.\n",silinecekad, silineceksoyad);
                ekiter = first->next;
                free(ekiter);
                first ->next =NULL;
            return first;
        }
            else{
                printf("!!! Silmek istediğiniz kişi '%s %s' yok!\n",silinecekad,silineceksoyad);
                return first;    } 
    }
    
    while (iter != NULL){
            if ((strcmp(iter->ad, silinecekad)==0)&&(strcmp(iter->soyad, silineceksoyad)==0)){
                printf("Rehberde bulunan %s %s silindi.\n",silinecekad,silineceksoyad);
                ekiter = iter;
                iter = iter ->next;
                first = iter;
                free(ekiter);
            return first;
        }
            else{
                printf("!!! Silmek istediğiniz kişi '%s %s' yok!\n",silinecekad,silineceksoyad);
                return first;
            }
            if ((iter->next->next == NULL)&&((strcmp(iter->next-> ad, silinecekad)==0)&&(strcmp(iter->next->soyad, silineceksoyad)==0))){
                printf("Rehberde bulunan %s %s silindi.\n",silinecekad,silineceksoyad);
                ekiter = iter ->next;
                free(ekiter);
                iter -> next = NULL;
            return first;
        }
            else{
            printf("!!! Silmek istediğiniz kişi '%s %s' yok!\n",silinecekad,silineceksoyad);
            return first;
            }
            if ((strcmp(iter->next -> ad, silinecekad)==0)&&(strcmp(iter->next -> soyad, silineceksoyad)==0)){
                printf("Rehberde bulunan %s %s silindi.\n",silinecekad,silineceksoyad);
                ekiter = iter ->next;
                ek2iter = iter;
                iter = iter ->next ->next;
                ek2iter ->next = iter;
                free(ekiter);
            return first;
        }
            else{
            printf("!!! Silmek istediğiniz kişi '%s %s' yok!\n",silinecekad,silineceksoyad);
            return first;
            }
    iter = iter->next;
    }
}

void bul(){
    struct rehber *iter;
    char *bulunacakad[MAX_LEN],*bulunucaksoyad[MAX_LEN];
    iter=first;
        printf("Aranacak Adı girin: ");
        scanf("%s",&bulunacakad);
        printf("Aranacak Soyadı girin: ");
        scanf("%s",&bulunucaksoyad);
    if (first == NULL){
        printf("!!! Liste boş!");
    }
    else{
        while (iter != NULL){
            if ((strcmp(iter->ad, bulunacakad)==0) && (strcmp(iter->soyad, bulunucaksoyad)==0)){
                printf("Aradığınız Kişi '%s %s' bulundu.\n Bilgileri;",iter->ad, iter->soyad);
                printf(" AD: %s - SOYAD: %s - TEL NO: %s - e-MAİL: %s \n", iter->ad, iter->soyad, iter->tel, iter->mail);
            }
            else{
                printf("!!! Aradığınız Kişi Bulunamadı\n");
                break;
            }
            iter = iter ->next;
        } 
    }
}

int main(){
    int zhd,dhz;
    do{
        printf("Telefon Rehberi\n ");
        printf("\n(1)-->Kişi Eklemek\n(2)-->Kişi Görüntülemek\n(3)-->Kişi Silmek\n(4)-->Kişi Bulmak\n");
        printf("İşlemi seçiniz:");
        scanf("%d",&dhz);
        
        switch(dhz){
            case 1:
                ekle();
            break;
            case 2: 
                yazdir(first);
            break;
            case 3: 
                sil();
            break;
            case 4: 
                bul();
            break;
            default: printf("Yanlış Girdiniz. ");
        }
        printf("Devam etmek isterseniz 1, Çıkmak için 0 :\n ");  scanf("%d",&zhd);
    }while(zhd!=0); 
return 0;
}
