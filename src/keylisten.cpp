#include "keylisten.h"

void kListener(struct lFlags &lf) {
    while(1) {
        if(((GetAsyncKeyState(VK_CONTROL)) & (0x8000) ) && ((GetAsyncKeyState(VK_SHIFT)) & (0x8000) ))
        {
            if((GetAsyncKeyState('K')) & (0x8000) ) {
                break;
            }
            if ((GetAsyncKeyState('H')) & (0x8000) ) {
                lf.exitNow = 1;
				lf.listenAgain = 0;
				lf.toggleVisibility = 0;
                break;
            }
            if ((GetAsyncKeyState('T')) & (0x8000) ) {
                lf.listenAgain = 0;
				lf.exitNow = 0;
				lf.toggleVisibility = 1;
                break;
            }
        }
    }
}

void selListener(void) {
    int res;
    while(1) {
        res = SELPWD(0) || SELPWD(1) || SELPWD(2) || SELPWD(3) || SELPWD(4) || SELPWD(5) || SELPWD(6) || SELPWD(7) || SELPWD(8) || SELPWD(9);

        if(res > 0) {
            //User made a valid choice and the string has been copied to clipboard successfully
            break;
        }

    }
}

void resetFlags(struct lFlags &lf) {
	lf.exitNow = 0;
	lf.listenAgain = 0;
}