#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp1;
    char a[1250000]={0};
    int i,ch;

    if((fp1 = fopen("franceis.txt","r"))==NULL){
		fprintf(stderr, "Can not open txte file\n");
		return -1;
	}
    //取得、再出力パート
    for(i=0;(i<1250000)&&((ch = fgetc(fp1))!=EOF);i++){
        a[i]=ch;
        if(((a[i]>=65)&&(a[i]<=90))||((a[i]>=97)&&(a[i]<=122))||(a[i]==32)||(a[i]==10)){
            printf("%c",a[i]);
        }
        else if(a[i]==195){
            if((ch=fgetc(fp1))!=EOF){
                i++;a[i]=ch;
                printf("%c%c",195,a[i]);
            }else{
                break;
            }
        }
        else if(a[i]==266){
            if(((a[++i]=fgetc(fp1))!=EOF)&&((a[++i]=fgetc(fp1))!=EOF)){
                if((a[i-1]==128)&&(a[i]==153)){
                    printf("%c%c%c",266,128,153);
                }else{
                    printf(" ");
                }
            }else{
                break;
            }
        }
        else{
            printf(" ");
        }
    }
    a[i]='\0';printf("%c",a[i]);

    fclose(fp1);
    
    return 0;
}