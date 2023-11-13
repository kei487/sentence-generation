#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DATA_NUM 100

struct let_data
{
    int rank;
    long int freq;
    double prob;
    int id;
    char let[3];
};

int print_char(int n);


int main(){
    FILE *fp1;
    char c1[10],c2[10],c3[10],c4[10],c5[10];
    int i,j,max_let,tmp;
    int let_list[1300000];
    long int mam;
    struct let_data data[DATA_NUM];
    
    srand((unsigned int)time(NULL)); 
    for(i=0;i<DATA_NUM;i++){
        data[i].let[0]=0;data[i].let[1]=0;data[i].let[2]=0;
    }

    if((fp1 = fopen("rslprog2","r"))==NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
	}

    fscanf(fp1,"%s,%s,%s,%s,%s",c1,c2,c3,c4,c5);
    i=0;
    do{
        fscanf(fp1,"%d,%ld,%lf,%d,%s",&data[i].rank,&data[i].freq,&data[i].prob,&data[i].id,data[i].let);
        mam+=data[i].freq;
    }while(data[i++].freq!=0); 
    max_let=i;

    j=0;tmp=0;
    for(i=0;i<max_let;i++){
        for( ; j < tmp + data[i].freq; j++){
            let_list[j]=data[i].id;
        }
        tmp=j;
    }
    printf("%ld\n",mam);
    for(i=0;i<100;i++){
        print_char(let_list[rand()%mam]);
    }puts(" ");

    fclose(fp1);
    
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