/*
Luke Welna
Lab 12
4-8-14
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct nodeNode{
	char nodeData;  // stores the char read in
	struct nodeNode *nextNode; // references the next node
} ofTypeNode;

ofTypeNode *headNode = NULL;  // initially sets the node to null
ofTypeNode *insertNode(ofTypeNode *headNode, char nodeData);
void insertRecurse(ofTypeNode *headNode,ofTypeNode *curNode);
void printLinkedList();
FILE *fr;

int main(){
	//puts("test1");
	fr = fopen("pangram.txt", "r"); // "r"  =  read only
	if(fr == NULL){
		puts("bad file");
		return 0;
	}
	//puts("test2");
	while(true){
		//puts("test3");
		int charRead = fgetc(fr);
		if(charRead == EOF){
			break;
		}
		else{
			//printf("%c", (char)charRead);
			//puts("test4");
			headNode = insertNode(headNode, (char)charRead);
		}
	}
printLinkedList(headNode);
	return 0;
}
ofTypeNode *insertNode(ofTypeNode *headNode, char nodeData){
	ofTypeNode *curNode;
	curNode = (ofTypeNode*)malloc(sizeof(ofTypeNode));
	curNode-> nodeData = nodeData;
	if(headNode == NULL){
		curNode->nextNode = NULL;
		return curNode;
	}
	else if(curNode->nodeData <= headNode->nodeData){//curent nodes data is less than head nodes data
		curNode->nextNode = headNode;
		return curNode;
	}
	else{
		insertRecurse(headNode, curNode);
		return headNode;
	}
}


void insertRecurse(ofTypeNode *headNode,ofTypeNode *curNode){
ofTypeNode *tempNode;
	if(headNode->nextNode == NULL){
		headNode->nextNode = curNode;
		curNode->nextNode = NULL;
		return;
	}
	if(((headNode->nextNode)->nodeData) >= (curNode->nodeData)){
		tempNode = headNode->nextNode;   
		headNode->nextNode = curNode;
		curNode->nextNode = tempNode;
		return;
	}
	insertRecurse(headNode->nextNode,curNode);
}

void printLinkedList(ofTypeNode *headNode){
	while(headNode != NULL){
		printf("%c", headNode->nodeData);
		headNode = headNode->nextNode;
	}
	return;
}

void bullshit(){
		/* /* /* 
	//puts("in insertNode");
	/* ofTypeNode *curNode;
	curNode = (ofTypeNode*)malloc(sizeof(ofTypeNode)); */
	//puts("after Malloc");
	/*
	curNode->nodeData = nodeData;
	//puts("curNode->nodeData = nodeData");
	if(headNode == NULL){ // seg fault is happening when i try to access headNode's data
		puts("headNode is null");
		headNode = curNode;
		printf("blashhhhhhhhhhhhhhhh");
		// return?
	}
	//printf("%c", curNode->nodeData);
	puts("after printing headNode");

	ofTypeNode *tempNode;
	puts("creating a tempNode pointer");
	fflush(stdout);
	 two cases
	1) i need to insert at beginning of list
	2) need to insert after a node if it is less than curNode.next 
	if(curNode->nodeData < headNode->nodeData){ // headNode.data still doesnt exist? seg fault
		puts("fdjasklfjdasklf");
		curNode->nextNode = headNode;
		puts("setting curNode.next to headNode");
	}
	puts("after first if");
	if(((headNode->nextNode)->nodeData) < (curNode->nodeData)){
		//set headNode.nextNodeNode to tempNode;
		//set the headNode.nextNode to curNode;
		//set curNode.nextNode to tempNode.nextNode;
		puts("gets into this bitch");
		tempNode = headNode->nextNode;   // possible seg fault in these 3 lines
		headNode->nextNode = curNode;
		curNode->nextNode= tempNode->nextNode;
	}
	else if(((headNode->nextNode)->nodeData) < (curNode->nodeData)){ // the place to insert was not found
		insertNode(headNode->nextNode,nodeData);
	}
	else { // the next node is null?
		headNode->nextNode = curNode;
	} 
*/
}