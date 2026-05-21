#include <stdio.h>
#define MAX 100
#define FILENAME "students.dat"
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;
// Function declarations
void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

// Main
int main() {
    int n;
    printf("Enter the size:\n");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Invalid input");
        return 0;
    }

    Student students[MAX];

    // 1. Input
    inputStudents(students, n);

    // 5. Write to binary file
    writeToBinaryFile(students, n, FILENAME);

    // 6. Read from binary file
    int count = readFromBinaryFile(students, FILENAME);

    // 7. Print read data
    printf("\n--- Students read from Binary file ---\n");
    printStudents(students, count);

    return 0;
}

// Read input
void inputStudents(Student students[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }
}

// Write to binary file
void writeToBinaryFile(Student students[], int n, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error opening binary file for writing.\n");
        return;
    }
    fwrite(students, sizeof(Student), n, fp);
    fclose(fp);
}

// Read from binary file
int readFromBinaryFile(Student students[], const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening binary file for reading.\n");
        return 0;
    }
    int count = fread(students, sizeof(Student), MAX, fp);
    fclose(fp);
    return count;
}

// Print students
void printStudents(Student students[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}