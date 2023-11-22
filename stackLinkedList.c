#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node *next;
};

//function to create new node for the linked list. It returns a pointer to new node
struct Node* createNode(){
	struct Node *x = (struct Node*) malloc(sizeof(struct Node));
	return x;
}

//initially the top will point to null as stack is empty
struct Node *top = NULL;

//Returns 1 if stack is EMPTY or 0 is stack is NOT EMPTY
int isEmpty(){
	if(top == NULL){
		return 1;
	}
	return 0;
}
//---------------------------------------------------------------------------------------------------
void push(int element){
	printf("Top before: %p", top);
	struct Node *node = createNode();
	node->data = element;
	node->next = top;
	top=node;
	printf("Top after: %p", top);
	printf("add in new node: %p", node->next);
}
//---------------------------------------------------------------------------------------------------
int pop(){
	int empty = isEmpty();
	if(empty == 1){
		printf("Stack is empty\n");
		return NULL;
	}
	struct Node *x = top->next;
	struct Node *toFree = top;
	int d = top->data;
	free(toFree);
	top = x;
	return d;
}
//---------------------------------------------------------------------------------------------------
int peek(){
	int empty = isEmpty();
	if(empty == 1){
		printf("Stack is empty\n");
		return NULL;
	}
	return top->data;
}
//---------------------------------------------------------------------------------------------------
void display(){
	int empty = isEmpty();
	if(empty == 1){
		printf("Stack is empty\n");
		return;
	}
	struct Node *x = top;
	while(x != NULL){
		printf("%d\t", x->data);
		x = x->next;
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------------
void main(){
	int option, flag=1, element;
	while(flag==1){
		printf("\nEnter the number associated to an operation\n1. Push\n2. Pop\n3. isEmpty\n4. Peek\n5. Display\nEnter any other number to exit\n>>");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("Enter the element to push: ");
				scanf("%d", &element);
				push(element);
				break;
			case 2:
				int popElement = pop();
				if(popElement != NULL){
					printf("%d got poped out of the stack.\n", popElement);
				}
				break;
			case 3:
				int empty = isEmpty();
				if(empty == 1) printf("Stack is empty!!\n");
				else printf("Stack is not empty");
				break;
			case 4:
				printf("%d is on top of the stack\n", peek());
				break;
			case 5:
				display();
				break;
			default:
				flag = 0;
				break;
		}
	}
}
