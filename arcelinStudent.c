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
    int hasData; // = 1 if there is data
    int ID;
    char firstName[SIZE];
    char lastName[SIZE];
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
    int selectedStudentsIndex = -1;
    int addedPoints = 0;
    char userMenuSelection;
    FiveStudents(list); //Hard coding the first 5 students into the array
    Greeting();
    do {
        userMenuSelection = toupper(DisplayMenu());
        switch (userMenuSelection){
            case 'P': //print students onto screen
                PrintStudentList(list, 0);
                break;
            case 'S': //select student. "current student"
                selectedStudentsIndex = SelectAndReturnIndex(list, 0);
                break;
            case 'O': //print selected students information onto screen
                if(selectedStudentsIndex == -1){
                    printf("\nPlease select a student by using option 'S' in the menu");
                } else {
                    printf("--------------------\nIndex: %d\n ID: %d\n First Name: %s\n Last Name: %s\n Num of Graded Entries: %d\n Total Graded Points: %.2lf\n Avg Grade: %.2lf\n", selectedStudentsIndex, list[selectedStudentsIndex].ID, list[selectedStudentsIndex].firstName, list[selectedStudentsIndex].lastName, list[selectedStudentsIndex].numOfGradeEntries, list[selectedStudentsIndex].totalGradePoints, list[selectedStudentsIndex].avgGrade);
                }
                break;
            case 'A': //add point for selected student
                if(selectedStudentsIndex == -1){
                    printf("\nPlease select a student by using option 'S' in the menu");
                    break;
                } else {
                    printf("Add points for %s (Max 100): ", list[selectedStudentsIndex].firstName);
                    scanf(" %d", &addedPoints);
                    if(addedPoints > 100 || addedPoints < 0){
                        printf("\nPlease add a valid value between 0 and 100");
                    }
                    list[selectedStudentsIndex].totalGradePoints += addedPoints;
                    printf("%lf", list[selectedStudentsIndex].totalGradePoints);
                }
                break;
            case 'C': //calculate and display the avg of selected student
                printf("PRINT");
                break;
            case 'N': //add student to list
                AddOneStudent(list, 0);
                break;
            case 'Q': //quit program
                printf("Quitting Program");
                break;
            
            default:
                printf("\n\n !!! Select a valid input !!!\n\n");
                break;
        };
    } while (userMenuSelection != 'Q');

    return 0;
}

void Greeting(void){
    printf("\n Greetings professor. Here you can access all of your students information");
};

void FiveStudents(student list[]) { //Hard coding 5 students into the array
    list[0].hasData = 1;
    list[0].ID = 1001;
    strcpy(list[0].firstName, "Charles");
    strcpy(list[0].lastName, "Xavier");
    list[0].numOfGradeEntries = 5;
    list[0].totalGradePoints = 240.5;
    list[0].avgGrade = 48.1;

    list[1].hasData = 1;
    list[1].ID = 1002;
    strcpy(list[1].firstName, "Jean");
    strcpy(list[1].lastName, "Grey");
    list[1].numOfGradeEntries = 4;
    list[1].totalGradePoints = 200.0;
    list[1].avgGrade = 50.0;

    list[2].hasData = 1;
    list[2].ID = 1003;
    strcpy(list[2].firstName, "Scott");
    strcpy(list[2].lastName, "Summers");
    list[2].numOfGradeEntries = 6;
    list[2].totalGradePoints = 300.0;
    list[2].avgGrade = 50.0;

    list[3].hasData = 1;
    list[3].ID = 1004;
    strcpy(list[3].firstName, "Ororo");
    strcpy(list[3].lastName, "Munroe");
    list[3].numOfGradeEntries = 3;
    list[3].totalGradePoints = 150.5;
    list[3].avgGrade = 50.2;

    list[4].hasData = 1;
    list[4].ID = 1005;
    strcpy(list[4].firstName, "Logan");
    strcpy(list[4].lastName, "Howlett");
    list[4].numOfGradeEntries = 5;
    list[4].totalGradePoints = 220.0;
    list[4].avgGrade = 44.0;
};

void PrintStudentList(student list[], int studentCount){ //Prints students
    for(int i = 0; list[i].hasData == 1; i++){
        printf("--------------------\nIndex: %d\n ID: %d\n First Name: %s\n Last Name: %s\n Num of Graded Entries: %d\n Total Graded Points: %.2lf\n Avg Grade: %.2lf\n", i, list[i].ID, list[i].firstName, list[i].lastName, list[i].numOfGradeEntries, list[i].totalGradePoints, list[i].avgGrade);
    }
};

int SelectAndReturnIndex(student list[], int studentCount){
    int selectedStudentsIndex;
     printf("\nSelect students' index for other options: ");
        scanf(" %d", &selectedStudentsIndex);
        if(list[selectedStudentsIndex].hasData != 1){
            selectedStudentsIndex = -1;
            printf("\nPlease select a valid student value. Input 'P' to see your options");
        }
    return selectedStudentsIndex;
};

int AddOneStudent(student list[], int studentCount){
    int newStudentIndex;
    for(newStudentIndex = 0; list[newStudentIndex].hasData == 1; newStudentIndex++);
    printf(" %d", newStudentIndex);

    printf("\nADDING NEW STUDENT\n");
    list[newStudentIndex].hasData = 1;
    printf("Input new students ID: ");
    scanf(" %d", &list[newStudentIndex].ID);
    printf("Input new students first name: ");
    scanf(" %s", list[newStudentIndex].firstName);
    printf("Input new students last name: ");
    scanf(" %s", list[newStudentIndex].lastName);
    printf("Input new students # of grade entries: ");
    scanf(" %d", &list[newStudentIndex].numOfGradeEntries);
    printf("Input new students total grade points: ");
    scanf(" %d", &list[newStudentIndex].ID);

    printf(" %s dfasdfasdfasdf ====", list[newStudentIndex].firstName);

    return newStudentIndex;
};

char DisplayMenu(){
    char userInput;
    printf("\nPlease select from the following:\n --- P --- to print the list of students and information onto the screen\n --- S --- to select the current student in the list for grade calculation\n --- O --- to print the information about one student onto the screen\n --- A --- to add the points for the current student\n --- C --- to calculate and display the average of the current student\n --- N --- to add a new student to the list\n --- Q --- to quit\n Input: ");
    scanf(" %c", &userInput);
    return userInput;
};

void AddPoints(student list[], int index){};

void CalculateAverage(student list[], int index){};