#include "encrypt.h"
#include <stdlib.h>

long long encrypt(int code){
    srand(code);
    long long a,b,c,d;
    for(int i=1;i<=233;i++)
        a=rand();
    b=rand();
    c=rand();
    d=rand();
    return (a<<48)|(b<<32)|(c<<16)|d;
}

int decrypt(long long codeint, int minint, int maxint){
    for(int i=minint;i<=maxint;i++)
        if(encrypt(i)==codeint)
            return i;
    return -1;
}

long long encrypt(QString str){
    int key=0;
    for(int i=0;i<str.size();i++)
        key=key*233+str[i].unicode();
    srand(key);
    long long a,b,c,d;
    for(int i=1;i<=666;i++)
        a=rand();
    b=rand();
    c=rand();
    d=rand();
    return (a<<48)|(b<<32)|(c<<16)|d;
}
