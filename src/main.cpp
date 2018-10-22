#include <iostream>
#include <windows.h>

#include "keylisten.h"
#include "passwords.h"

using namespace std;

short consoleMode = 0;

int main(int argc, char **argv) {
    //Parse arguments
    if(argc>=2) {
        if(!strcmp(argv[1], "-c")) {
            consoleMode = 1;
        }
    }
	
	struct lFlags lf;

    InitPwds();

    if(!consoleMode) {
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
    }

    //Listen for key input
    do {
		resetFlags(lf);
		
        cout<<"Listening for activation key combination ..."<<endl;
        cout<<endl;
        cout<<"The following key combinations are valid:"<<endl;
        cout<<"\tCTRL + SHIFT + K  --  Allows password selection from list 0-9"<<endl;
        cout<<"\tCTRL + SHIFT + T  --  Displays a message. Useful for testing if the program is running"<<endl;
        cout<<"\tCTRL + SHIFT + H  --  Exits the program"<<endl;

        kListener(lf);

        if(lf.exitNow) break; //Check if the exitNow flag has been set
        if(lf.listenAgain) continue; //If the listenAgain flag is set, the loop should be restarted.

        cout<<"Choose a password:"<<endl;
        ListPwds();
        selListener();
    } while(!lf.exitNow);

    return 0;
}
