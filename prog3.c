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
    struct freq_one first[130];
};

int indx(FILE *fp1,char n){
    int ch;char a;
    if((n>=65)&&(n<=90)){
        return n-63;
    }else if((n>=97)&&(n<=122)){
        return n-69;
    }else if(n==10){
        return 0;
    }else if(n==32){
        return 1;
    }else if(n==-61){
        ch=fgetc(fp1);a=ch;
        return (int)a+182;
    }else if(n==-59){
        ch=fgetc(fp1);a=ch;
        return (int)a+228;
    }else if(n==-30){
    //'の時(3バイト文字)
        ch=fgetc(fp1);ch=fgetc(fp1);
        return 120;
    }
}

int print_char(int n){
    if(n==0){
        printf("改行");
    }
    if(n==1){
        printf("空白");
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

int main(){
    FILE *fp1,*fp2;
    char c0,c1;
    int a[MAX_NUM]={0};
    int i,j,ch,num_letter;
    struct freq_two second[130];
    int rnk[130*130];

    for(i=0;i<130;i++){
        for(j=0;j<130;j++){
            second[i].first[j].num=0;
            rnk[130*i+j]=130*i+j;
        }
    }

    if((fp1 = fopen("rslprog1","r"))==NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
    }
    if((fp2 = fopen("rsl2prog3","w"))==NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
    }

    ch=fgetc(fp1);c0=ch;a[0]=indx(fp1,c0);fprintf(fp2,"%d\n",a[0]);

    for(i=1;(i<MAX_NUM)&&((ch = fgetc(fp1))!=EOF);i++){
        c1=ch;a[i]=indx(fp1,c1); 
        fprintf(fp2,"%d\n",a[i]);
        second[a[i-1]].first[a[i]].num++;
    }
    num_letter=i;

    for(i=0;i<130*130;i++){
        for(j=130*130-1;j>i;j--){
            if(second[rnk[j]/130].first[rnk[j]%130].num > second[rnk[j-1]/130].first[rnk[j-1]%130].num){
                swap(rnk[j],rnk[j-1]);
            }
        }
    }
    printf("順位,登場回数,登場率,文字番号組,文字組\n");
    for(i=0;i<1200;i++){
        printf("%d,%ld,%lf,%d %d,",i,second[rnk[i]/130].first[rnk[i]%130].num,(float)second[rnk[i]/130].first[rnk[i]%130].num/(float)num_letter,rnk[i]/130,rnk[i]%130);print_char(rnk[i]/130);print_char(rnk[i]%130);printf("\n");
    }

    fclose(fp1);
    
    return 0;

}