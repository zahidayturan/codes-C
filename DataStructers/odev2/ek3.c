// İsmet Zahid AYTURAN - 21060607 - OMÜ Bilgisayar Müh.
// Veri Yapıları Dersi - Stack ile html Tag Kontrolü Yapma Ödevi
//08.11.2022
//EKLEME YAPILACAKTIR.! Aynı dizinde olan a.txt ve b.txt ile çalışır.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 150

struct tags{
    char tag[MAX_LEN];
    struct tags *next;
};
struct tags *first=NULL;
struct tags *us=NULL;

struct tags2{
    char tag2[MAX_LEN];
    struct tags2 *next2;
};
struct tags2 *first2=NULL;
struct tags2 *us2=NULL;

struct tags3{
    char tag3[MAX_LEN];
    struct tags3 *next3;
};
struct tags3 *first3=NULL;
struct tags3 *us3=NULL;

struct tags*yenidu(char[]);
struct tags2*yenidu2(char[]);
struct tags3*yenidu3(char[]);
struct tags*push(char[]);
struct tags2*push2(char[]);
struct tags3*push3(char[]);
void yazdir();
void yazdir2();
void yazdir3();
void isaretkontrol();
void esle();
void oku();
void oku2();
void ekoku();
struct tags*pop(char[]);

struct tags *yenidu(char x[]){
    struct tags *yenidugum =(struct tags*)malloc(sizeof(struct tags));
    strcpy(yenidugum->tag, x);
    yenidugum -> next = NULL;
    return yenidugum;
}

struct tags2 *yenidu2(char x[]){
    struct tags2 *yenidugum2 =(struct tags2*)malloc(sizeof(struct tags2));
    strcpy(yenidugum2->tag2, x);
    yenidugum2 -> next2 = NULL;
    return yenidugum2;
}

struct tags3 *yenidu3(char x[]){
    struct tags3 *yenidugum3 =(struct tags3*)malloc(sizeof(struct tags3));
    strcpy(yenidugum3->tag3, x);
    yenidugum3 -> next3 = NULL;
    return yenidugum3;
}

struct tags *push(char x[]){
    struct tags *yeni =  yenidu(x);
    if (first == NULL){
        first = yeni;
    }
    else{
        struct tags *iter=first;
        while (iter ->next != NULL)
            iter = iter->next;
        iter->next = yeni;
    }            
}

struct tags2 *push2(char x[]){
    struct tags2 *yeni =  yenidu2(x);
    if (first2 == NULL){
        first2 = yeni;
    }
    else{
        struct tags2 *iter=first2;
        while (iter ->next2 != NULL)
            iter = iter->next2;
        iter->next2 = yeni;
    }            
}

struct tags3 *push3(char x[]){
    struct tags3 *yeni =  yenidu3(x);
    if (first3 == NULL){
        first3 = yeni;
    }
    else{
        struct tags3 *iter=first3;
        while (iter ->next3 != NULL)
            iter = iter->next3;
        iter->next3 = yeni;
    }            
}

struct tags *pop(char x[]){
    struct tags *iter =  first;
    struct tags *temp =  first;
    while (iter->next!=NULL){
        iter = iter->next;
    }
    while (temp->next->next!=NULL){
        temp = temp->next;
    }
    if (strcmp (iter->tag, x))
    {
        temp->next=NULL;
        free(iter);
    }         
}

void kontrol(){
    struct tags *iter = first;
    struct tags *temp = first;
    while (iter !=NULL){
        if (*iter->tag == '<' || *iter->tag == '>')
        {
            printf("< OLANLAR: %s\n",iter ->tag);
            push3(iter->tag);
        }
        else{
            printf("OLMAYANLAR: %s\n",iter->tag);
        }
        
        //printf("Şu anki iter %s\n",iter->tag);
        //printf("Şu anki temp %s\n",temp->tag);
    iter = iter->next;
    }      
}

void yazdir(struct tags *first){
    struct tags *iter = first;
    struct tags *us=first;
    while (us->next !=NULL){
        us=us->next;
    }
    printf("----------YIĞIN 1----------\n");
    printf("EN ÜSTTE Kelime:%s\n",us->tag);
    int i=0;
    int k=0;
    if (iter == NULL){
        printf("BOŞ!\n");
        }
    else{
    while(iter != NULL){
        i++;
        printf("%d.Kelime:%s\n",i,iter->tag);
		iter = iter -> next;
	}
	printf("\n");
    }
}

void yazdir2(struct tags2 *first2){
    struct tags2 *iter = first2;
    struct tags2 *us2=first2;
    int i=0; 
    while (us2->next2 !=NULL){
        us2=us2->next2;
    }
    printf("----------YIĞIN 2----------\n");
    printf("EN ÜSTTE Kelime:%s\n",us2->tag2);
    if (iter == NULL){
        printf("BOŞ!\n");
    }
    else{
    while(iter != NULL){
        i++;
        printf("%d.Kelime:%s\n",i,iter->tag2);
		iter = iter -> next2;
	}
	printf("\n");
    }
}

void yazdir3(struct tags3 *first3){
    struct tags3 *iter = first3;
    struct tags3 *us3=first3;
    while (us3->next3 !=NULL){
        us3=us3->next3;
    }
    int i=0;
    printf("----------YIĞIN 3----------\n");
    printf("EN ÜSTTE Kelime:%s\n",us3->tag3);
    if (iter == NULL){
        printf("BOŞ!\n");}
    else{
    while(iter != NULL){
        i++;
        printf("%d.Kelime:%s\n",i,iter->tag3);
		iter = iter -> next3;
	}
	printf("\n");
    }
}

void oku(){
FILE *dosya = fopen("a.txt", "r");
    if (fopen("a.txt","r")){
        printf("Dosya Açıldı\n");
    }    else{
        printf("Dosya Açılamadı\n");
    }
    char str[1000];
    while (fgets(str, sizeof(str), dosya)){
    char* kelime=NULL;
    kelime=strtok(str,"\n");
    kelime=strtok(str," ");

    while(kelime!=NULL){
        //printf("kelime: %s\n",kelime);
        push(kelime);
        kelime=strtok(NULL," ");      
        }
    }
    fclose(dosya);
}

void oku2(){
FILE *dosya = fopen("b.txt", "r");
    if (fopen("b.txt","r")){
        printf("Dosya Açıldı\n");
    }    else{
        printf("Dosya Açılamadı\n");
    }
    char str[1000];
    while (fgets(str, sizeof(str), dosya)){
    char* kelime=NULL;
    kelime=strtok(str,"\n");
    kelime=strtok(str," ");

    while(kelime!=NULL){
        //printf("kelime: %s\n",kelime);
        push2(kelime);
        kelime=strtok(NULL," ");      
        }
    }
    fclose(dosya);
}

void isaretkontrol(){
    FILE *dosya = fopen("a.txt", "r");
    char str[1000];
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    char ch1 = '<' ;
    char ch2 = '>' ;
    char ch3 = '/' ;
    while (fgets(str, sizeof(str), dosya)){  
    for (int i = 0; str[i] != '\0'; ++i) {
        if (ch1 == str[i]){
            ++count1;}
        else if (ch2 == str[i]){
            ++count2;}
        else if (ch3 == str[i]){
            ++count3;
            }
        }
    }    
    printf("Frequency of %c = %d\n", ch1, count1);
    printf("Frequency of %c = %d\n", ch2, count2);
    printf("Frequency of %c = %d\n", ch3, count3);
    if (count1 == count2){
        printf("Açılan bütün tagler kapanmış!\n");}
    else{
         printf("Açılmasında veya kapanmasında hata olan tag var!\n");
        }
         if ((count3)%2 != 0){
        printf("Kapanmayan tag var!\n");}
    else{
         printf("Tagler kapanmış!\n");}
    fclose(dosya);
}

void esle(){
    struct tags *iter = first;
    struct tags2 *temp = first2;
    int i =0;
    while (iter != NULL){
        while (temp !=NULL)
        {
            if (strcmp(iter->tag , temp->tag2)==0)
            {
                i++;
                printf("Eşleşti %d: %s - %s\n",i,iter->tag,temp->tag2);
                break;
            }
        temp = temp ->next2; 
        }        
    temp =first2;
    iter = iter->next;
    }
}

void ekoku(){
FILE *dosya = fopen("a.txt", "r");
    if (fopen("a.txt","r")){
        printf("Dosya Açıldı\n");
    }    else{
        printf("Dosya Açılamadı\n");
    }
    char str[1000];
    while (fgets(str, sizeof(str), dosya)){
    char *kelime=NULL;
    //kelime=strtok(str," ");
    kelime=strtok(str,"\n");
    //kelime=strtok(str,"/>");

    while(kelime!=NULL){
        //printf("kelime: %s\n",kelime);
        printf("Okunanlar:%s\n",kelime);
        kelime=strtok(NULL," ");      
        }
    }
    fclose(dosya);
}

int main(){
    printf("************ YIĞINLAR OLUŞTURULUYOR ************\n");
    oku();
    oku2();
    kontrol();
    ekoku();
    printf("************ YIĞINLAR YAZDIRILIYOR ************\n");
    yazdir(first);
    yazdir2(first2);
    yazdir3(first3);
    printf("************ TAGLER KONTROL EDİLİYOR ************\n");
    isaretkontrol();
    printf("************ TAG EŞLEŞMELERİ KONTROL EDİLİYOR ************\n");
    esle();
    return 0;
}
