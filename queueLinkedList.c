#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node *front = NULL;
struct Node *end = NULL;

struct Node* createNode(){
	struct Node *new = (struct Node*) malloc(sizeof(struct Node));
	return new;
} 

int isEmpty(){
	if(front == NULL && end == NULL) return 1;
	return 0;
}

void enqueue(int element){
	struct Node *newNode = createNode();
	newNode->data = element;
	newNode->next = NULL;
	if(front == NULL) front = newNode;
	if(end != NULL) end->next = newNode;
	end = newNode;
}

int dequeue(){
	int element = front->data;
	struct Node *newFront = front->next;
	if(front == end) end = NULL;
	free(front);
	front = newFront;
	return element;
}

void display(){
	struct Node *temp = front;
	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}

void main(){
	int ch, flag=1;
	while(flag == 1){
		printf("Enter your selection:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n>> ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter an element to add to queue: ");
				int element;
				scanf("%d", &element);
				enqueue(element);
				printf("%d added to queue\n\n", element);
				break;
			case 2:
				if(isEmpty() == 0){
					element = dequeue();
					printf("%d was removed from the queue\n\n", element);
				}
				else printf("Queue is empty\n\n");
				break;
			case 3:
				if(isEmpty() == 0){
					printf("Elements in queue are: \n");
					display();
				}
				else printf("Queue is empty");
				printf("\n\n\n");
				break;
			case 4:
				flag = 0;
				break;
			default:
				printf("Wrong Input!! Retry.\n\n");
		}
	}
}
