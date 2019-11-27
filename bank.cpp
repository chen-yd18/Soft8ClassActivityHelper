#include "bank.h"
int queryCoin()
{
    FILE *fp=fopen("footprint.s8","r");
    char *s=new char[32777];
    fscanf(fp,"%s",s);
    int coin=0;
    for(int bl=0;bl<1024;bl++){
        int xorsum=0;
        for(int j=1;j<=31;j++){
            xorsum^=(s[bl*32+j]-'0');
            coin+=10*(s[bl*32+j]-'0');
        }
        if(xorsum!=s[bl*32]-'0'){
            coin=-1;break;
        }
    }
    fclose(fp);
    return coin;
}
int queryRecord(int tp, int cl, int y, int m, int d){
    FILE *fp=fopen("footprint.s8","r");
    char *s=new char[32777];
    fscanf(fp,"%s",s);
    if(tp==ACTIVITY){
        int p=((cl-1)*48+(y-2019)*12+(m-1))*32+d;
        return s[p]-'0';
    }
    else if(tp==SHARE){
        int p=(432+cl*48+(y-2019)*12+(m-1))*32+d;
        return s[p]-'0';
    }
    else if(tp==QUIZ){
        int p=(720+cl*80)*32+y;
        return s[p]-'0';
    }
    else if(tp==PRIZE){
        //TBD
    }
    fclose(fp);
}
void addRecord(int tp, int cl, int y, int m, int d){
    FILE *fp=fopen("footprint.s8","r");
    char *s=new char[32777];
    fscanf(fp,"%s",s);
    if(tp==ACTIVITY){
        int p=((cl-1)*48+(y-2019)*12+(m-1))*32+d;
        if(s[p]=='0'){
            s[p]='1';
            s[p-d]^=1;
        }
    }
    else if(tp==SHARE){
        int p=(432+cl*48+(y-2019)*12+(m-1))*32+d;
        if(s[p]=='0'){
            s[p]='1';
            s[p-d]^=1;
        }
    }
    else if(tp==QUIZ){
        int p=(720+cl*80)*32+y;
        if(s[p]=='0'){
            s[p]='1';
            s[p/32*32]^=1;
        }
    }
    else if(tp==PRIZE){
        //TBD
    }
    fclose(fp);
    fp=fopen("footprint.s8","w");
    fprintf(fp,"%s",s);
    fclose(fp);
}
