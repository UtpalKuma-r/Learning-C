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
	int numberOfStudents, sum=0, userChoice;
	
	printf("Welcome to Student Record Manager\n");
	
	printf("Enter number of students: ");
	scanf("%d", &numberOfStudents);
	
	struct Student studentArr[numberOfStudents];
	
	for(int i=0; i<numberOfStudents; i++){
		printf("Enter details of student %d\n", i+1);
		
		printf("Name: ");
		scanf("%s", studentArr[i].name);
		
		printf("ID: ");
		scanf("%d", &studentArr[i].id);
		
		for(int j=0; j<5; j++){
			printf("Subject %d name: ", j+1);
			scanf("%s", studentArr[i].sub[j].subject);
			
			printf("Marks: ");
			scanf("%d", &studentArr[i].sub[j].marks);
			
			sum +=  studentArr[i].sub[j].marks;
			
			studentArr[i].sub[j].grade = gradeClaculator(studentArr[i].sub[j].marks);
		}
		
		studentArr[i].avgMarks = sum/5;
		studentArr[i].avgGrade = gradeClaculator(studentArr[i].avgMarks);
		
		sum = 0;
	}
	
	//Printing Student details
	for(int i=0; i<numberOfStudents; i++){
		printf("%d\t%s\t%d\t%c\n", studentArr[i].id, studentArr[i].name, studentArr[i].avgMarks, studentArr[i].avgGrade);
		for(int j=0; j<5; j++){
			printf("\t%s\t%d\t%c\n", studentArr[i].sub[j].subject, studentArr[i].sub[j].marks, studentArr[i].sub[j].grade);
		}
	}
}
