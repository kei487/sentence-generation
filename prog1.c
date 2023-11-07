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
        if(((a[i]>=65)&&(a[i]<=90))||((a[i]>=97)&&(a[i]<=122))||(a[i]==10)){
            printf("%c",a[i]);
        }else if(a[i]==32){
            if((a[i-1]!=32)&&(a[i-1]!=10)){
                printf(" ");
            }
        }else if(a[i]==-61){
            if((ch=fgetc(fp1))!=EOF){
                i++;a[i]=ch;
                printf("%c%c",-61,a[i]);
            }else{
                break;
            }
        }else if(a[i]==-59){
            if((ch=fgetc(fp1))!=EOF){
                i++;a[i]=ch;
                printf("%c%c",-59,a[i]);
            }else{
                break;
            }
        }else if(a[i]==-30){
            if((ch=fgetc(fp1))!=EOF){
                i++;a[i]=ch;
                if((int)a[i]==-128){
                    if((ch=fgetc(fp1))!=EOF){
                        i++;a[i]=ch;
                        if(a[i]==-103){
                            printf("%c%c%c",a[i-2],a[i-1],a[i]);
                        }else{
                            a[i]=32;
                            if((a[i-3]!=32)&&(a[i-3]!=10)){
                                printf(" ");
                            }
                        }
                    }else{
                        break;
                    }
                }else{
                    if((ch=fgetc(fp1))!=EOF){
                        i++;a[i]=32;
                        if((a[i-2]!=32)&&(a[i-2]!=10)){
                            printf(" ");
                        }
                    }else{
                        break;
                    }
                }
            }else{
                break;
            }
        }else{
            a[i]=32;
            if((a[i-1]!=32)&&(a[i-1]!=10)){
                printf(" ");
            }
        }
    }
    a[i]='\0';

    fclose(fp1);
    
    return 0;
}