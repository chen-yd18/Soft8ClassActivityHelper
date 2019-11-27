#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <QString>

long long encrypt(int code);
int decrypt(long long codeint, int minint, int maxint);

long long encrypt(QString str);

#endif // ENCRYPT_H
