#ifndef BANK_H
#define BANK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum type{ACTIVITY, SHARE, QUIZ, PRIZE};
int queryCoin();
int queryRecord(int tp, int cl, int y, int m=0, int d=0);
void addRecord(int tp, int cl, int y, int m=0, int d=0);
#endif // BANK_H
