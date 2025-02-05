#include "fileIO.h"

char* loadTextFromFile(const char* filename){
    if (!(filename)) {
        printf("Empty filename");
        return "";
    }
    FILE* file=fopen(filename, "r");
    if (!(file)){
        printf("Failed to open file");
        return "";
    }
    char *reader, line[257];
    while (fgets(line, sizeof(line), file)){
        memcpy(reader+strlen(reader), line, strlen(line)+1);
        //printf("%s\n", reader);
        g_free(line);
    }
    fclose(file);
    g_free(line);
    return reader;
}