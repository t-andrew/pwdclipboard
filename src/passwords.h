#ifndef _PASSWORDS_
#define _PASSWORDS_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "clipboard.h"

void ListPwds(void);
int InitPwds(short verbose = 1);
int CpyPwd(int);

#endif //_PASSWORDS_