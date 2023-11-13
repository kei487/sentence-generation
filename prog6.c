#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DATA_NUM 760

struct let_data
{
    long int freq;
    int id[2];
};
struct let_list
{
    long int mam;
    int letter[22223];
};

int print_char(int n);


int main(){
    FILE *fp;
    char c1[10];
    int i,j,max_let,tmp,a1,a0,loop,flag,k[42]={0},atmp[42]={0};
    long int mam=0;
    struct let_list list[42];
    struct let_data data[DATA_NUM];
    char let[8];double prob;int rank;

    for(i=0;i<42;i++){
        list[i].mam=0;
    }
    
    srand((unsigned int)time(NULL)); 

    if((fp=fopen("rslprog3n","r")) == NULL){
		printf("Can not open txte file\n");
		return -1;
	}

    fscanf(fp,"%s,%s,%s,%s,%s",c1,c1,c1,c1,c1);
    i=0;
    do{
        fscanf(fp,"%d,%ld,%lf,%d %d,%s",&rank,&data[i].freq,&prob,&data[i].id[0],&data[i].id[1],let);
    }while((data[i++].freq!=0)&&(i<DATA_NUM)); 
    max_let=i;

    
    for(i=0;i<max_let;i++){
        for( ;k[data[i].id[0]]<atmp[data[i].id[0]]+data[i].freq/10; k[data[i].id[0]]++){
            list[data[i].id[0]].letter[k[data[i].id[0]]]=data[i].id[1];
        }
        list[data[i].id[0]].mam+=data[i].freq/10;
        atmp[data[i].id[0]]=k[data[i].id[0]];
    }

    for(i=0;i<42;i++){
        mam+=list[i].mam;
    }

    loop=rand()%mam;
    flag=0;j=0;tmp=0;
    for(i=0;i<121;i++){
        for( ;j<tmp+list[i].mam;j++){
            if(j==loop){
                print_char(i);
                print_char(list[i].letter[j-tmp]);
                a0=list[i].letter[j-tmp];
                flag=1;
                break;
            }
        }
        if(flag) break;
        tmp=j;
    }
    for(i=0;i<10000;i++){
        a1 = rand() % list[a0].mam;
        print_char(list[a0].letter[a1]);
        a0=list[a0].letter[a1];
    }printf("\n \n \n");

    fclose(fp);
    
    return 0;

}

int print_char(int n){
    if(n==0){
        printf("\n");
    }
    if(n==1){
        printf(" ");
    }
    if((n>=2)&&(n<=27)){
        printf("%c",n+95);
    }
    if(n==28){
        printf("%c%c",-61,-96);
    }
    if(n==29){
        printf("%c%c",-61,-89);  
    }
    if(n==30){
        printf("%c%c",-61,-88);  
    }
    if(n==31){
        printf("%c%c",-61,-87);  
    }
    if(n==32){
        printf("%c%c",-61,-86);  
    }
    if(n==33){
        printf("%c%c",-61,-76);  
    }
    if(n==34){
        printf("%c%c",-61,-94);  
    }
    if(n==35){
        printf("%c%c",-61,-85);  
    }
    if(n==36){
        printf("%c%c",-61,-82);  
    }
    if(n==37){
        printf("%c%c",-61,-81);  
    }
    if(n==38){
        printf("%c%c",-61,-71);  
    }
    if(n==39){
        printf("%c%c",-61,-69);  
    }
    if(n==40){
      printf("%c%c",-59,-109);  
    }
    if(n==41){
        printf("%c%c%c",-30,128,153);  
    }}