#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DATA_NUM 1200

struct let_data
{
    int rank;
    long int freq;
    double prob;
    int id[2];
    char let[8];
};
struct let_list
{
    int letter[10000];
    long int mam;
};

int print_char(int n);


int main(){
    FILE *fp;
    char c1[10],c2[10],c3[10],c4[10],c5[10];
    int i,j,max_let,tmp,a1,a0,k[130]={0},atmp[130]={0};
    long int mam=0;
    struct let_list list[130];
    struct let_data data[DATA_NUM];

    for(i=0;i<130;i++){
        list[i].mam=0;
    }
    
    srand((unsigned int)time(NULL)); 

    if((fp=fopen("rslprog3","r")) == NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
	}
    
    fscanf(fp,"%s,%s,%s,%s,%s",c1,c2,c3,c4,c5);
    i=0;
    do{
        fscanf(fp,"%d,%ld,%lf,%d %d,%s",&data[i].rank,&data[i].freq,&data[i].prob,&data[i].id[0],&data[i].id[1],data[i].let);
        mam+=data[i].freq;
        list[data[i].id[0]].mam+=data[i].freq;
    }while((data[i++].freq!=0)&&(i<DATA_NUM)); 
    max_let=i;
    
    //この下がやばそう
    for(i=0;i<max_let;i++){
        for( ;k[data[i].id[0]]<atmp[data[i].id[0]]+data[i].freq;k[data[i].id[0]]++){
            list[data[i].id[0]].letter[k[data[i].id[0]]]=data[i].id[1];
        }
        atmp[data[i].id[0]]=k[data[i].id[0]];
    }

    
    int loop=rand()%mam;
    printf("%d %ld\n",loop,mam);
    for(i=0;i<130;i++){
        
    }

    j=0;tmp=0;
    for(i=0;i<130;i++){
        for( ;j<tmp+list[i].mam;j++){
            if(j==loop){
                print_char(data[j].id[0]);
                print_char(data[j].id[1]);
                break;
            }
        }
        tmp=j;
    }
    for(i=0;i<10000;i++){
        a1=rand()%list[a0].mam;
        print_char(list[a0].letter[a1]);
        a0=a1;
    }puts(" ");

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
        printf("%c",n+63);
    }
    if((n>=28)&&(n<=53)){
        printf("%c",n+69);
    }
    if((n>=54)&&(n<=117)){
        printf("%c%c",-61,n-182);  
    }
    if((n==118)||(n==119)){
      printf("%c%c",-59,n-228);  
    }
    if(n==120){
        printf("%c%c%c",-30,128,153);  
    }
}