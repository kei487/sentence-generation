#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1250000
#define swap(x,y) {long int tmp=x;x=y;y=tmp;}

struct freq_one
{
    long int num;
};
struct freq_two
{
    struct freq_one first[42];
};
struct freq_three
{
    struct freq_two second[42];
};



int print_char(int n);


int main(){
    FILE *fp1;
    int a[3]={0};
    int i,j,k,num_letter,tmp;
    struct freq_three third[42];
    int rnk[42*42*42];
    
    for(i=0;i<42;i++){
        for(j=0;j<42;j++){
            for(k=0;k<42;k++){
                third[i].second[j].first[k].num=0;
                tmp=42*42*i + 42*j + k;
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
    
    for(i=0;i<42*42*42;i++){
        for(j=42*42*42-1;j>i;j--){
            if(third[rnk[j]/(42*42)].second[(rnk[j]/42)-42*(rnk[j]/(42*42))].first[rnk[j]%42].num > third[rnk[j-1]/(42*42)].second[(rnk[j-1]/42)-42*(rnk[j-1]/(42*42))].first[rnk[j-1]%42].num){
                swap(rnk[j],rnk[j-1]);
            }
        }
    }
    
    printf("順位,登場回数,登場率,文字番号組,文字組\n");
    for(i=0;i<42*42*42;i++){
        printf("%d,%ld,%lf,%d %d %d,",i,third[rnk[i]/(42*42)].second[(rnk[i]/42)-42*(rnk[i]/(42*42))].first[rnk[i]%42].num,(float)third[rnk[i]/(42*42)].second[(rnk[i]/42)-42*(rnk[i]/(42*42))].first[rnk[i]%42].num/(float)num_letter,rnk[i]/(42*42),(rnk[i]/42)-42*(rnk[i]/(42*42)),rnk[i]%42);print_char(rnk[i]/(42*42));print_char((rnk[i]/42)-42*(rnk[i]/(42*42)));print_char(rnk[i]%42);printf("\n");
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