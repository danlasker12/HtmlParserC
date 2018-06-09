#pragma once 

#include <stdio.h>
#include <stdlib.h>

char* loadToRam(char* name,int* size);
FILE* makeNewFile(char* name);
int writeToFile(FILE*,char*);