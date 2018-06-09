#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "list.h"

char* strFile;
int sizeFile;
LINKEDLIST* list;

int main(int argc, char *argv[])
{
	if(argc <= 1){
		printf("No parameters entered!\n");
		return -1;		
	}

	strFile = loadToRam(argv[1], &sizeFile);
	int i;
	NODE* tempNode;
	char* tempStrFile = strFile;
	char* tempTxt;

	tempTxt = (char*)malloc(sizeFile+1000);
	list = newLinkedLlist();
	memset(tempTxt,0,sizeFile);

	/* Beggining of the main Loop*/
	for(i=0;i<sizeFile;i++){
		if(tempStrFile[i] == '<'){
			tempNode = appendNode(list, makeTag(tempStrFile + i,i));
		}
	}

	toStringList(list);

	for(tempNode = list->first;tempNode->next!=NULL;tempNode=tempNode->next){
		if(tempNode->tag->isOpenTag == 1){
			strcat(tempTxt,extractContent(tempNode->tag,getPairTag(tempNode)));
		}
	}




	

	FILE* pFile = makeNewFile("output.txt");
	

	int test = writeToFile(pFile,tempTxt);

	return 0;
}
