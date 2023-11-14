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

int indx(FILE *fp1,char n){
    int ch;char a;
    if((n>=65)&&(n<=90)){
        return n-63;
    }else if((n>=97)&&(n<=122)){
        return n-95;
    }else if(n==10){
        return 0;
    }else if(n==32){
        return 1;
    }else if(n==-61){
        ch=fgetc(fp1);a=ch;
        if(a==-128||a==-96){
            return 28;
        }else if(a==-121||a==-89){
            return 29;
        }else if(a==-120||a==-88){
            return 30;
        }else if(a==-119||a==-87){
            return 31;
        }else if(a==-118||a==-86){
            return 32;
        }else if(a==-108||a==-76){
            return 33;
        }else if(a==-94){
            return 34;
        }else if(a==-85){
            return 35;
        }else if(a==-82){
            return 36;
        }else if(a==-81){
            return 37;
        }else if(a==-71){
            return 38;
        }else if(a==-69){
            return 39;
        }
    }else if(n==-59){
        ch=fgetc(fp1);a=ch;
        return 40;
    }else if(n==-30){
    //'の時(3バイト文字)
        ch=fgetc(fp1);ch=fgetc(fp1);
        return 41;
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

int main(){
    FILE *fp1,*fp2;
    char c0,c1;
    int a[MAX_NUM]={0};
    int i,j,ch,num_letter;
    struct freq_two second[NUM_CODE];
    int rnk[NUM_CODE*NUM_CODE];

    for(i=0;i<NUM_CODE;i++){
        for(j=0;j<NUM_CODE;j++){
            second[i].first[j].num=0;
            rnk[NUM_CODE*i+j]=NUM_CODE*i+j;
        }
    }

    if((fp1 = fopen("rslprog1","r"))==NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
    }
    if((fp2 = fopen("rsl2prog3n","w"))==NULL){
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
    
    for(i=0;i<NUM_CODE*NUM_CODE;i++){
        for(j=NUM_CODE*NUM_CODE-1;j>i;j--){
            if(second[rnk[j]/NUM_CODE].first[rnk[j]%NUM_CODE].num > second[rnk[j-1]/NUM_CODE].first[rnk[j-1]%NUM_CODE].num){
                swap(rnk[j],rnk[j-1]);
            }
        }
    }
    printf("順位,登場回数,登場率,文字番号組,文字組\n");
    for(i=0;i<NUM_CODE*NUM_CODE;i++){
        printf("%d,%ld,%lf,%d %d,",i,second[rnk[i]/NUM_CODE].first[rnk[i]%NUM_CODE].num,(float)second[rnk[i]/NUM_CODE].first[rnk[i]%NUM_CODE].num/(float)num_letter,rnk[i]/NUM_CODE,rnk[i]%NUM_CODE);print_char(rnk[i]/NUM_CODE);print_char(rnk[i]%NUM_CODE);printf("\n");
    }

    fclose(fp1);
    
    return 0;

}