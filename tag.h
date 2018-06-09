#pragma once 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_TAG_NAME 20

extern char* strFile;

typedef struct _TAG{
	char* nameTag;
	int location;
	int isOpenTag;
	int sizeTag;
}TAG;

TAG* newTag(char* _nameTag, int _location, int _isOpenTag);
char* makeNameTag(char* str);
TAG* makeTag(char* str,int location);
void toStringTag(TAG* _tag);
char* extractContent(TAG* _openingTag,TAG* _closingTag);