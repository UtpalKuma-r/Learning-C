/*
Student name, grade, subject, marks
calculate avg marks
assign grade
*/

#include <stdio.h>

struct SubjectDetails{
	char subject[20];
	int marks;
	char grade;
};

struct Student{
	int id;
	char name[20];
	struct SubjectDetails sub[5];
	int avgMarks;
	char avgGrade;
};

char gradeClaculator(int marks){
	if(marks>90) return 'A';
	else if(marks>80) return 'B';
	else if(marks>70) return'C';
	else if(marks>60) return 'D';
	else return 'F';
}

void main(){
	int numberOfStudents, sum=0;
	
	printf("Welcome to Student Record Manager\n");
	
	printf("Enter number of students: ");
	scanf("%d", &numberOfStudents);
	
	struct Student studentArr[numberOfStudents];
	
	struct Student *ptr = studentArr;
	
	for(int i=0; i<numberOfStudents; i++){
		printf("Enter details of student %d\n", i+1);
		
		printf("Name: ");
		scanf("%s", ptr->name);
		
		printf("ID: ");
		scanf("%d", &ptr->id);
		
		for(int j=0; j<5; j++){
			printf("Subject %d name: ", j+1);
			scanf("%s", ptr->sub[j].subject);
			
			printf("Marks: ");
			scanf("%d", &ptr->sub[j].marks);
			
			sum +=  ptr->sub[j].marks;
			
			ptr->sub[j].grade = gradeClaculator(ptr->sub[j].marks);
		}
		
		ptr->avgMarks = sum/5;
		ptr->avgGrade = gradeClaculator(ptr->avgMarks);
		
		sum = 0;
		ptr++;
	}
	
	ptr -= numberOfStudents;
	
	//Printing Student details
	for(int i=0; i<numberOfStudents; i++){
		printf("%d\t%s\t%d\t%c\n", ptr->id, ptr->name, ptr->avgMarks, ptr->avgGrade);
		for(int j=0; j<5; j++){
			printf("\t%s\t%d\t%c\n", ptr->sub[j].subject, ptr->sub[j].marks, ptr->sub[j].grade);
		}
		ptr++;
	}
}
