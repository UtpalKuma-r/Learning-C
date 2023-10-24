#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
	char number[100];
	int flag = 1;
	printf("Enter your vehicle number: ");
	scanf("%s", number);

	int c = strlen(number);
	
	if (c == 10) {
		if (isalpha(number[0]) && isalpha(number[1]) && isdigit(number[2]) && isdigit(number[3]) && isalpha(number[4]) && isalpha(number[5]) && isdigit(number[6]) && isdigit(number[7]) && isdigit(number[8]) && isdigit(number[9])){
			flag = 0;
		}

	}
	
	if (flag == 0){
		printf("Correct\n");
	}
	else{
		printf("Wrong\n");
	}
}
