#include "myStr.h"
#include <stdlib.h>
#include <string.h>

char* copyStr(const char* oneStr){
    char* newStr = (char*)malloc(sizeof(oneStr)*strlen(oneStr));
    strcpy(newStr, oneStr);
    return newStr;
}