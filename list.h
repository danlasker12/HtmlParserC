#pragma once 

#include "tag.h"

typedef struct _NODE
{
	struct _NODE* prev;
	TAG* tag;
	struct _NODE* next;
}NODE;

typedef struct _LINKEDLIST{
	NODE* first;
	int len;
}LINKEDLIST;

NODE* newNode(TAG* _tag);
LINKEDLIST* newLinkedLlist();
NODE* appendNode(LINKEDLIST* _list, TAG* _tag);
int deleteLastNode(LINKEDLIST* _list);
void toStringList(LINKEDLIST* _list);
int isPair(char* str1,char* str2);
TAG* getPairTag(NODE* openingTagNode);