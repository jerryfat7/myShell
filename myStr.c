#include <stdlib.h>
#include <string.h>
#include "myStr.h"


char* copyStr(const char* oneStr){
    char* newStr = (char*)malloc(sizeof(oneStr)*strlen(oneStr));
    strcpy(newStr, oneStr);
    return newStr;
}