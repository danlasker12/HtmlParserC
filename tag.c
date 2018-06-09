#include "tag.h"

TAG* newTag(char* _nameTag, int _location, int _isOpenTag){
	TAG* tag;
	tag = (TAG*)malloc(sizeof(TAG));
	tag->nameTag = _nameTag;
	tag->location = _location;
	tag->isOpenTag = _isOpenTag;
	tag->sizeTag = strlen(_nameTag);
	return tag;
}

TAG* makeTag(char* str,int location){
	int _isOpenTag;
	char* name;

	name = makeNameTag(str);
	
	if(*(str+1) == '/'){
		_isOpenTag = 0;
	}
	else{
		_isOpenTag = 1;
	}
    return newTag(name,location,_isOpenTag);
}

char* makeNameTag(char* str){
	int i;
	char* pStr = (char*)malloc(MAX_LEN_TAG_NAME+2);
	for(i=0;i<MAX_LEN_TAG_NAME+2;i++){
		pStr[i] = str[i];
		if(str[i] == '>'){
			pStr[i+1] = '\0';
			return pStr;
		}
	}	
	printf("TAG Length too long\n");
	return NULL;
}


void toStringTag(TAG* _tag){
	char buffer[10];
	if(_tag->isOpenTag == 1){
		strcpy(buffer,"OPEN TAG");
	}
	else{
		strcpy(buffer,"CLOSE TAG");
	}

	printf("%s, %d, %s \n",_tag->nameTag, _tag->location, buffer);
}

char* extractContent(TAG* openingTag,TAG* closingTag){
	char* content;
	int i,j,locationContent = openingTag->location + openingTag->sizeTag;

	content = (char*)malloc(closingTag->location - locationContent + 50);

	for(j=0, i = locationContent; i < closingTag->location;i++,j++){
		content[j] = strFile[i]; 
	}
	content[j] = '\n';
	content[j+1] = '\0';
	return content;

}

