#include <iostream>
#include <windows.h>

int Cpy2clip(int);
void kListener(void);
void shortcutListener(void);
void ListPwds(void);

#define KPRESS(X) (((GetAsyncKeyState((int)(X+'0'))) & (0x8000))?(1):(0))
#define SELPWD(X) ((KPRESS(X))?(Cpy2clip(X)):(0x00))

using namespace std;

short enableListen = 1;
short exitNow = 0;
short consoleMode = 0;
short reset = 0;

const char *pwds[] = {"1234!",
                        "muhpass",
                        "anotherPass",
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        NULL};

void kListener(void) {
    while(enableListen) {
        if(((GetAsyncKeyState(VK_CONTROL)) & (0x8000) ) && ((GetAsyncKeyState(VK_SHIFT)) & (0x8000) ))
        {
            if((GetAsyncKeyState('K')) & (0x8000) ) {
                enableListen = 0;
                break;
            }
            if ((GetAsyncKeyState('H')) & (0x8000) ) {
                enableListen = 0;
                exitNow = 1;
                break;
            }
            if ((GetAsyncKeyState('T')) & (0x8000) ) {
                MessageBox(NULL, "PwdClipboard v0.1 is running. Made by t-andrew.", "PwdClipboard", MB_OK|MB_ICONINFORMATION);
                reset = 1;
                enableListen = 0;
                break;
            }

        }
    }
}

void selListener(void) {
    int res;
    while(enableListen) {
        res = SELPWD(0) || SELPWD(1) || SELPWD(2) || SELPWD(3) || SELPWD(4) || SELPWD(5) || SELPWD(6) || SELPWD(7) || SELPWD(8) || SELPWD(9);

        if(res > 0) {
            //User made a valid choice and the string has been copied to clipboard successfully
            enableListen = 0;
            break;
        }

    }
}


void Cpy2clip(const char *str) {
    if((strlen(str) <= 0) || strlen(str) >= 64) {
        return;
    }

    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, strlen(str)+1);
    memcpy(GlobalLock(hMem), str, strlen(str)+1);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

int Cpy2clip(int index) {

    try {
        if(pwds[index] == NULL) {
            return 0;
        }
        Cpy2clip(pwds[index]);
        return 1; //Success
    } catch (int e) {
        return 0;
    }

}


void ListPwds(void) {
    int i = 0;
    do {
        cout<<"#"<<i<<"   "<<pwds[i]<<endl;
        i++;
    } while(pwds[i] != NULL);
}


int main(int argc, char **argv) {
    //Parse arguments
    if(argc>=2) {
        if(!strcmp(argv[1], "-c")) {
            consoleMode = 1;
        }
    }

    if(!consoleMode) {
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
    }


    //Listen for key input
    while(!exitNow) {
        cout<<"Listening for activation key combination ..."<<endl;
        cout<<endl;
        cout<<"The following key combinations are valid:"<<endl;
        cout<<"\tCTRL + SHIFT + K  --  Allows password selection from list 0-9"<<endl;
        cout<<"\tCTRL + SHIFT + T  --  Displays a message. Useful for testing if the program is running"<<endl;
        cout<<"\tCTRL + SHIFT + H  --  Exits the program"<<endl;

        kListener();
        if(exitNow) break; //Check if the exitNow flag has been set
        enableListen = 1; //Reset flag to 1 to be able to listen again in the future

        //If the reset flag is set, the loop should be restarted.
        if(reset) {
            reset = 0;
            continue;
        }

        cout<<"Choose a password:"<<endl;
        ListPwds();
        selListener();
        enableListen = 1;
    }

    return 0;
}
