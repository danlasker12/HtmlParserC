#include "utils.h"

char* loadToRam(char* nameFile, int* size){
	char* str;
	FILE* pFile;

	pFile = fopen(nameFile,"r");

	if(pFile == NULL){
		printf("Source File not found\n");
		return NULL;
	}

	fseek(pFile, 0, SEEK_END);
	*size = ftell(pFile);
	rewind(pFile);

	str = (char*)malloc(*size+1);
	str[*size] = 0;
	fread(str,1,*size,pFile);

	fclose(pFile);

	return str;
}

FILE* makeNewFile(char* name){
	FILE* pFile;
	pFile = fopen(name,"w");
	if(pFile == NULL){
		printf("Problem with creating file\n");
		return NULL;
	}

	return pFile;
}

int writeToFile(FILE* pFile,char* str){
	int writing = fputs(str,pFile);
	if(writing == 1){
		printf("[*] Writing data into file ...[*] \n");
		return 1;
	}
	else{
		printf("Error writing data into file\n");
		return -1;
	}
	fclose(pFile);
}