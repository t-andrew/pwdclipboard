#include "passwords.h"

char *pwds[10]; //Can store up to 10 passwords

void ListPwds(void) {
    int i = 0;
    do {
        std::cout<<"#"<<i<<"   "<<pwds[i]<<std::endl;
        i++;
    } while(pwds[i] != NULL);
}

int InitPwds(short verbose) {
    int i;
    char pwd[256];
    FILE *f = fopen("p.txt", "r");

    if(f == NULL)  {
        std::cerr<<"Password file not found!"<<std::endl;

        //Initialize the list with a password
        pwds[0] = new char[sizeof(char) * 4];
        strcpy(pwds[0], "1234");
        return -1;
    }

    i = 0;
    while(fgets(pwd, sizeof(pwd), f)) {

        pwd[strlen(pwd)-1] = '\0'; //Strip \n

        pwds[i] = new char[sizeof(char) * strlen(pwd) + 1];
        strcpy(pwds[i], pwd);

        i++;
        if(i>=10) break;
    }
    fclose(f);
    return 0;
}

int CpyPwd(int index) {

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