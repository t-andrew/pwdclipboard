#ifndef _KEY_LISTEN
#define _KEY_LISTEN

#include <windows.h>
#include "passwords.h"


#define KPRESS(X) (((GetAsyncKeyState((int)(X+'0'))) & (0x8000))?(1):(0))
#define SELPWD(X) ((KPRESS(X))?(CpyPwd(X)):(0x00))


void kListener(struct lFlags &lf);
void selListener(void);
void resetFlags(struct lFlags &lf);

struct lFlags {
	short exitNow = 0;
	short listenAgain = 0;
};

#endif //_KEY_LISTEN