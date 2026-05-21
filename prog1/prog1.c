/*The advantage of storing array of structures as binary files is that we can use fseek to go to specific record and get the record.
Write a program to store n records in binary file.
Write a function to get mth record and display.
Use fseek
Write a function to delete a record.
Deleting a record requires thinking.*/

#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "student.bin"


struct Student
{
    int roll;
    char name[30];
    float marks;
};
void storeRecords();
void getMthRecord(int m);
void deleteRecord(int delRoll);

int main()
{
    int choice, m, roll;

    while (1)
    {
        printf("\n====== MENU ======\n");
        printf("1. Store Records\n");
        printf("2. Get Mth Record\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                storeRecords();
                break;

            case 2:
                printf("Enter record number (m): ");
                scanf("%d", &m);
                getMthRecord(m);
                break;

            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteRecord(roll);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}


void storeRecords()
{
    FILE *fp;
    struct Student s;
    int n, i;

    fp = fopen(FILE_NAME, "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s.roll);

        printf("Name: ");
        scanf("%s", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

      
        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);

    printf("\nRecords stored successfully!\n");
}


void getMthRecord(int m)
{
    FILE *fp;
    struct Student s;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    
    fseek(fp, (m - 1) * sizeof(s), SEEK_SET);

   
    fread(&s, sizeof(s), 1, fp);

    printf("\n===== Mth Record =====\n");
    printf("Roll No : %d\n", s.roll);
    printf("Name    : %s\n", s.name);
    printf("Marks   : %.2f\n", s.marks);

    fclose(fp);
}


void deleteRecord(int delRoll)
{
    FILE *fp, *temp;
    struct Student s;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

   
    temp = fopen("temp.bin", "wb");

    
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == delRoll)
        {
            found = 1;
            continue;   // Skip writing this record
        }

        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

   
    remove(FILE_NAME);

    
    rename("temp.bin", FILE_NAME);

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nRecord not found!\n");
}