// Insert at beginning
// insert at end
//Delete node by value
//Display linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *start = NULL;

struct Node* createNode(){
	return (struct Node*)malloc(sizeof(struct Node));
}

int isEmpty(){
	if(start == NULL) return 1;
	return 0;
}

void insertBeginning(int element){
	struct Node *new = createNode();
	new->data = element;
	new->next = start;
	start = new;
}

void insertEnd(int element){
	struct Node *new = createNode();
	new->data = element;
	new->next = NULL;
	if(start==NULL){
		start = new;
		return;
	}
	struct Node *temp = start;
	while(temp->next!=NULL) temp = temp->next;
	temp->next = new;
	return;
}

void deleteNodeByValue(int element){
	if(start==NULL){
		printf("List is empty, cannot delete!!\n");
		return;
	}
	struct Node *tempCurrent = start;
	struct Node *tempPrevious = NULL;
	struct Node *tempNext = NULL;
	while(tempCurrent != NULL){
		if(tempCurrent->data == element){
			tempNext = tempCurrent->next;
			free(tempCurrent);
			if(tempPrevious==NULL) start = tempNext;
			else tempPrevious->next = tempNext;
			printf("Element Deleted!!\n");
			return;
		}
		tempPrevious = tempCurrent;
		tempCurrent = tempCurrent->next;
	}
	printf("Element not found\n");
	return;
}

void display(){
	if(start == NULL){
		printf("List is empty!!\n");
		return;
	}
	struct Node *temp = start;
	while(temp!=NULL){
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main(){
	int flag = 1;
	int option;
	int element;
	while(flag){
		printf("\n****************************************************************************************************\n");
		printf("Select from following\n1. Insert at Biginning\n2. Inser at End\n3. Delete by value\n4. Display\n>> ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("Enter the element to insert: ");
				scanf("%d", &element);
				insertBeginning(element);
				break;
			case 2:
				printf("Enter the element to insert: ");
				scanf("%d", &element);
				insertEnd(element);
				break;
			case 3:
				if(isEmpty() == 0){
					display();
					printf("Enter the element to insert: ");
					scanf("%d", &element);
					deleteNodeByValue(element);
				}
				else printf("Liste is empty!!\n");
				break;
			case 4:
				display();
				break;
			default:
				flag = 0;
		}
	}
}
