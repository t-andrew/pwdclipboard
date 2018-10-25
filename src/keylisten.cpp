#include "keylisten.h"

void kListener(struct lFlags &lf) {
	SHORT KprevState = 0;
	SHORT HprevState = 0;
	SHORT TprevState = 0;

	while(1) {
		if(((GetAsyncKeyState(VK_CONTROL)) & (GetAsyncKeyState(VK_SHIFT)) & (0x8000) ) )
		{
			while((GetAsyncKeyState('K')) & (0x8000) ) { KprevState = 1; }
			while((GetAsyncKeyState('H'))  & (0x8000) ) { HprevState = 1; }
			while((GetAsyncKeyState('T')) & (0x8000) ) { TprevState = 1; }
			
			if(KprevState == 1) {
				break;
			}
			
			if(HprevState) {
				lf.exitNow = 1;
				lf.listenAgain = 0;
				lf.toggleVisibility = 0;
				break;
			}
			
			if(TprevState) {
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
	lf.toggleVisibility = 0;

}