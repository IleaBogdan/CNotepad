#include "fileIO.h"

void saveTextInFile(const char *text){
    if (text){
        FILE* file=fopen("save.txt", "w");
        if (file){
            fprintf(file, "%s", text);
            fclose(file);
            printf("Saved\n");
        } else printf("Failed file opening\n"); 
    } else printf("Null text\n");
}