#include "fileIO.h"

void saveTextInFile(const char *text){
    freopen("save.txt", "w", stdout);
    printf("Hello?");    
}