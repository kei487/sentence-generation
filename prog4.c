#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1250000
#define NUM_CODE 42
#define swap(x,y) {long int tmp=x;x=y;y=tmp;}

struct freq_one
{
    long int num;
};
struct freq_two
{
    struct freq_one first[NUM_CODE];
};
struct freq_three
{
    struct freq_two second[NUM_CODE];
};



int print_char(int n);


int main(){
    FILE *fp1;
    int a[3]={0};
    int i,j,k,num_letter,tmp;
    struct freq_three third[NUM_CODE];
    int rnk[NUM_CODE*NUM_CODE*NUM_CODE];
    
    for(i=0;i<NUM_CODE;i++){
        for(j=0;j<NUM_CODE;j++){
            for(k=0;k<NUM_CODE;k++){
                third[i].second[j].first[k].num=0;
                tmp=NUM_CODE*NUM_CODE*i + NUM_CODE*j + k;
                rnk[tmp]=tmp;
            }
        }
    }
    
    if((fp1 = fopen("rsl2prog3n","r"))==NULL){
		fprintf(stderr, "Can not open data file\n");
		return -1;
    }
    
    fscanf(fp1,"%d",&a[0]);
    fscanf(fp1,"%d",&a[1]);
    for(i=2;i<1138081;i++){ //1138081
        fscanf(fp1,"%d",&a[2]);
        third[a[0]].second[a[1]].first[a[2]].num++;
        a[0]=a[1];a[1]=a[2];
    }
    num_letter=i;
    
    for(i=0;i<NUM_CODE*NUM_CODE*NUM_CODE;i++){
        for(j=NUM_CODE*NUM_CODE*NUM_CODE-1;j>i;j--){
            if(third[rnk[j]/(NUM_CODE*NUM_CODE)].second[(rnk[j]/NUM_CODE)-NUM_CODE*(rnk[j]/(NUM_CODE*NUM_CODE))].first[rnk[j]%NUM_CODE].num > third[rnk[j-1]/(NUM_CODE*NUM_CODE)].second[(rnk[j-1]/NUM_CODE)-NUM_CODE*(rnk[j-1]/(NUM_CODE*NUM_CODE))].first[rnk[j-1]%NUM_CODE].num){
                swap(rnk[j],rnk[j-1]);
            }
        }
    }
    
    printf("順位,登場回数,登場率,文字番号組,文字組\n");
    for(i=0;i<NUM_CODE*NUM_CODE*NUM_CODE;i++){
        printf("%d,%ld,%lf,%d %d %d,",i,third[rnk[i]/(NUM_CODE*NUM_CODE)].second[(rnk[i]/NUM_CODE)-NUM_CODE*(rnk[i]/(NUM_CODE*NUM_CODE))].first[rnk[i]%NUM_CODE].num,(float)third[rnk[i]/(NUM_CODE*NUM_CODE)].second[(rnk[i]/NUM_CODE)-NUM_CODE*(rnk[i]/(NUM_CODE*NUM_CODE))].first[rnk[i]%NUM_CODE].num/(float)num_letter,rnk[i]/(NUM_CODE*NUM_CODE),(rnk[i]/NUM_CODE)-NUM_CODE*(rnk[i]/(NUM_CODE*NUM_CODE)),rnk[i]%NUM_CODE);print_char(rnk[i]/(NUM_CODE*NUM_CODE));print_char((rnk[i]/NUM_CODE)-NUM_CODE*(rnk[i]/(NUM_CODE*NUM_CODE)));print_char(rnk[i]%NUM_CODE);printf("\n");
    }

    fclose(fp1);
    
    return 0;

}

int print_char(int n){
    if(n==0){
        printf("改行");
    }
    if(n==1){
        printf("空白");
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
    }
}