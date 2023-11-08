#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1250000
#define swap(x,y) {long int tmp=x;x=y;y=tmp;}

struct freq_letter
{
    long int num;
};


int main(){
    FILE *fp1;
    char a[1250000]={0};
    int i,j,ch,num_letter;
    struct freq_letter first[130];
    int rnk[130];

    for(i=0;i<130;i++){
        first[i].num=0;
        rnk[i]=i;
    }

    if((fp1 = fopen("rslprog1","r"))==NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
	}

    for(i=0;(i<MAX_NUM)&&((ch = fgetc(fp1))!=EOF);i++){
        a[i]=ch;
        if((a[i]>=65)&&(a[i]<=90)){
            first[a[i]-63].num++;
        }else if((a[i]>=97)&&(a[i]<=122)){
            first[a[i]-69].num++;
        }else if(a[i]==10){
            first[0].num++;
        }else if(a[i]==32){
            first[1].num++;
        }else if(a[i]==-61){
            ch=fgetc(fp1);a[++i]=ch;
            first[a[i]+182].num++;
        }else if(a[i]==-59){
            ch=fgetc(fp1);a[++i]=ch;
            first[a[i]+228].num++;
        }else if(a[i]==-30){
        //'の時(3バイト文字)
            ch=fgetc(fp1);a[++i]=ch;ch=fgetc(fp1);a[++i]=ch;
            first[120].num++;
        }
    }
    a[i]='\0';num_letter=i;

    for(i=0;i<130;i++){
        for(j=129;j>i;j--){
            if(first[rnk[j]].num > first[rnk[j-1]].num){
                swap(rnk[j],rnk[j-1]);
            }
        }
    }

    printf("順位,登場回数,登場率,文字番号,文字\n");
    for(i=0;i<130;i++){
        if(rnk[i]==0){
            printf("%d,%ld,%lf,%d,改行\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i]);
        }
        if(rnk[i]==1){
            printf("%d,%ld,%lf,%d,空白\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i]);
        }
        if((rnk[i]>=2)&&(rnk[i]<=27)){
            printf("%d,%ld,%lf,%d,%c\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i],rnk[i]+63);
        }
        if((rnk[i]>=28)&&(rnk[i]<=53)){
            printf("%d,%ld,%lf,%d,%c\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i],rnk[i]+69);
        }
        if((rnk[i]>=54)&&(rnk[i]<=117)){
          printf("%d,%ld,%lf,%d,%c%c\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i],-61,rnk[i]-182);  
        }
        if((rnk[i]==118)||(rnk[i]==119)){
          printf("%d,%ld,%lf,%d,%c%c\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i],-59,rnk[i]-228);  
        }
        if(rnk[i]==120){
          printf("%d,%ld,%lf,%d,%c%c%c\n",i,first[rnk[i]].num,(float)first[rnk[i]].num/(float)num_letter,rnk[i],-30,128,153);  
        }
    }

    fclose(fp1);
    
    return 0;

}