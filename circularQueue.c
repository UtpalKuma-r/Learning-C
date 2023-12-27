#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node *front = NULL;
struct Node *end = NULL;
int qlen = 5;
int nodeCount = 0;

struct Node* createNode(){	return (struct Node*) malloc(sizeof(struct Node));	} 

int isEmpty(){
	if(front == NULL || front->data==NULL) return 1;
	return 0;
}

int enqueue(int element){
	if(front != NULL && end->next->data == NULL){
		end->next->data = element;
		end = end->next;
		return 1;
	}
	else if(nodeCount<qlen){
		struct Node *newNode = createNode();
		newNode->data = element;
		if(front == NULL){
			front = newNode;
			newNode->next = front;
		}
		else{
			end->next = newNode;
			newNode->next = front;
		}
		end = newNode;
		nodeCount++;
		return 1;
	}
	else printf("Queue is full\n");
	return 0;
}

int dequeue(){
	int element = front->data;
	struct Node *newFront = front->next;
	if(newFront == front){
		newFront = NULL;
	}
	front->data = NULL;
	front = newFront;
	return element;
}

void display(){
	struct Node *temp = front;
	do{
		if(temp->data == NULL) return;
		printf("%d\t", temp->data);
		temp = temp->next;
	}while(temp != front);
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
				if (enqueue(element) == 1)	printf("%d added to queue\n\n", element);
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
