/* 
 * COP2220 
 * Nicolas Arcelin
 * November 30, 20223
 * Program 9: Sturcts 2
 */

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 25

//Variables
typedef struct {
    char firstName[SIZE];
    char lastName[SIZE];
    int ID;
    int numOfGradeEntries;
    double totalGradePoints;
    double avgGrade;
}student;

//function prototypes
//welcome the user to the grade app
void Greeting(void);

//initialize 5 students to the list
void FiveStudents(student list[]);

//Add one student to the list
int AddOneStudent(student list[], int studentCount);
//input: one student by COPY

//print the information for one student
void PrintOneStudent(student oneStudent);

//input: list and count

//print the list of students
void PrintStudentList(student list[], int studentCount);

//input: list and count

//display the students, have the user select the index, return the index
int SelectAndReturnIndex(student list[], int studentCount);

//run the menu
//input: none

//display menu choices, declare ask and get and return the char choice
char DisplayMenu();
//input the current student list and the selected index

//declare ask and get the points to add

//update the points
void AddPoints(student list[], int index);

//input the current student list and the selected index
//confirm that the count is not 0

//calculate and display the average
void CalculateAverage(student list[], int index);

int main(){
    student list[SIZE];
    FiveStudents(list); //Hard coding the first 5 students into the array
    Greeting();
        char userMenuSelection = toupper(DisplayMenu());
    switch (userMenuSelection){
        case 'P':
            printf("PRINT");
            break;
        case 'O':
            printf("PRINT");
            break;
        case 'S':
            printf("PRINT");
            break;
        case 'A':
            printf("PRINT");
            break;
        case 'C':
            printf("PRINT");
            break;
        case 'N':
            printf("PRINT");
            break;
        case 'Q':
            printf("PRINT");
            break;
        
        default:
            break;
    }

    return 0;
}

void Greeting(void){
    printf("\n Greetings professor. Here you can access all of your students information");
};

void FiveStudents(student list[]) { //Hard coding 5 students into the array
    strcpy(list[0].firstName, "Charles");
    strcpy(list[0].lastName, "Xavier");
    list[0].ID = 1001;
    list[0].numOfGradeEntries = 5;
    list[0].totalGradePoints = 240.5;
    list[0].avgGrade = 48.1;

    strcpy(list[1].firstName, "Jean");
    strcpy(list[1].lastName, "Grey");
    list[1].ID = 1002;
    list[1].numOfGradeEntries = 4;
    list[1].totalGradePoints = 200.0;
    list[1].avgGrade = 50.0;

    strcpy(list[2].firstName, "Scott");
    strcpy(list[2].lastName, "Summers");
    list[2].ID = 1003;
    list[2].numOfGradeEntries = 6;
    list[2].totalGradePoints = 300.0;
    list[2].avgGrade = 50.0;

    strcpy(list[3].firstName, "Ororo");
    strcpy(list[3].lastName, "Munroe");
    list[3].ID = 1004;
    list[3].numOfGradeEntries = 3;
    list[3].totalGradePoints = 150.5;
    list[3].avgGrade = 50.2;

    strcpy(list[4].firstName, "Logan");
    strcpy(list[4].lastName, "Howlett");
    list[4].ID = 1005;
    list[4].numOfGradeEntries = 5;
    list[4].totalGradePoints = 220.0;
    list[4].avgGrade = 44.0;
};

int AddOneStudent(student list[], int studentCount){
    return 0;
};

void PrintStudentList(student list[], int studentCount){};
int SelectAndReturnIndex(student list[], int studentCount){
    return 0;
};

char DisplayMenu(){
    char userInput;
    printf("Please select from the following:\n --- P --- to print the list of students and information onto the screen\n --- O --- to print the information about one student onto the screen\n --- S --- to select the current student in the list for grade calculation\n --- A --- to add the points for the current student\n --- C --- to calculate and display the average of the current student\n --- N --- to add a new student to the list\n --- Q --- to quit\n Input: ");
    scanf("%c", &userInput);
    return userInput;
};

void AddPoints(student list[], int index){};
void CalculateAverage(student list[], int index){};