#include <stdio.h>

int top = -1;
int stack[100];

void push(int element){
	if(top == 100){
		printf("Stack is full\n");
		return;
	}
	top++;
	stack[top] = element;
	printf("Element added\n");
}

void pop(){
	if(top == -1){
		printf("Stack is empty\n");
		return;
	}
	top --;
	printf("Element poped\n");
}

void display(){
	if(top == -1){
		printf("Stack is empty\n");
		return;
	}
	for(int i=0; i<=top; i++){
		printf("%d\t", stack[i]);
	}
	printf("\n");
}

void main(){
	int option, flag=1;
	while(flag==1){
		printf("\nEnter the number associated to an operation\n1. Push\n2. Pop\n3. Display\nEnter any other number to exit\n>>");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				int element;
				printf("Enter the element to push: ");
				scanf("%d", &element);
				push(element);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				flag = 0;
				break;
		}
	}
}
