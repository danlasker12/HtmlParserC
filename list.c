#include "list.h"

NODE* newNode(TAG* _tag){
	NODE* node;
	node = (NODE*)malloc(sizeof(NODE));
	node->tag = _tag;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

LINKEDLIST* newLinkedLlist(){
	LINKEDLIST* list;
	list = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));
	list->first = NULL;
	list->len = 0;
	return list;
}

NODE* appendNode(LINKEDLIST* list,TAG* _tag){
	NODE* temp;
	NODE* node;
	node = newNode(_tag);
	if(list->first == NULL){
		list->first = node;
		list->len++;
		return node;
	}

	for(temp = list->first;temp->next!=NULL;temp=temp->next);

	temp->next = node;
	node->prev = temp;

	list->len++;
	return node;
}

int deleteLastNode(LINKEDLIST* list){
	if(list->first == NULL){
		printf("No element to be deleted\n");
		return -1;
	}
	if(list->first->next == NULL){
		free(list->first);
		list->first = NULL;
		return 1;
	}
	NODE* temp = list->first;
	for(;temp->next->next!=NULL;temp=temp->next);
	free(temp->next);
	temp->next = NULL;
	list->len--;
	return 1;
}


void toStringList(LINKEDLIST* _list){
	NODE* temp;
	for(temp = _list->first; temp!=NULL; temp = temp->next){
		toStringTag(temp->tag);
	}
}

TAG* getPairTag(NODE* openingTagNode){
	TAG* tag;
	NODE* tempNode;
	char* name = openingTagNode->tag->nameTag;
	int deepness = 0;
	
	for(tempNode = openingTagNode->next;tempNode!=NULL;tempNode = tempNode->next){
		//printf("Checking %s:%s\n", name,tempNode->tag->nameTag);
		if(isPair(name,tempNode->tag->nameTag)){
			//printf("Is pair %s:%s\n", name,tempNode->tag->nameTag);
			if(deepness == 0){

			//	printf("FOUND!\n");
				return tempNode->tag;	
			}
			else{
			//	printf("DECREMENTING!\n");
				deepness--;
			}	
		} 
		else if(!strcmp(name,tempNode->tag->nameTag)){
			deepness++;
			//printf("Incrementing!\n");
		}	
		//printf("%d\n",deepness);
		//printf("NOT EQUAL %s:%s\n",name,tempNode->tag->nameTag);
	}
	printf("NOT CLOSING TAG FOUND\n");

	return NULL;
}

int isPair(char* str1,char* str2){
	int i,lim1 = strlen(str1), lim2 = strlen(str2);
	//int max = max(lim1,lim2);
	if(lim2 - lim1 != 1){
		return 0;
	}
	if(str2[1] != '/' || str1[1] == '/'){
		return 0;
	}
	for(i=1;i<lim1;i++){
		if(str1[i]!=str2[i+1]){
			return 0;
		}
	}
	return 1;
}
