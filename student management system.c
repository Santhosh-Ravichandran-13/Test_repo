#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUD 100
#define FILE "students.csv"

struct Student
{
    int roll;
    char name[30];
    int age;
    float marks;
};

struct Student sts[MAX_STUD];
int count = 0;

void loadStudents()
{
    FILE *fp = fopen(FILE, "r");

    if (fp == NULL)
        return;

    count = 0;

    while (count < MAX_STUD &&
           fscanf(fp, "%d,%29[^,],%d,%f\n",
                  &sts[count].roll,
                  sts[count].name,
                  &sts[count].age,
                  &sts[count].marks) == 4)
    {
        count++;
    }

    fclose(fp);
}

void saveStudents()
{
    FILE *fp = fopen(FILE, "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%d,%.2f\n",
                sts[i].roll,
                sts[i].name,
                sts[i].age,
                sts[i].marks);
    }

    fclose(fp);
}

int findStudent(int roll)
{
    for (int i = 0; i < count; i++)
    {
        if (sts[i].roll == roll)
            return i;
    }

    return -1;
}

void create()
{
    struct Student s;

    scanf("%d", &s.roll);
    scanf(" %29[^\n]", s.name);
    scanf("%d", &s.age);
    scanf("%f", &s.marks);

    sts[count++] = s;

    saveStudents();
}

void readStudents()
{
    for (int i = 0; i < count; i++)
    {
        printf("%d %s %d %.2f\n",
               sts[i].roll,
               sts[i].name,
               sts[i].age,
               sts[i].marks);
    }
}

void update()
{
    int roll;
    int index;

    scanf("%d", &roll);

    index = findStudent(roll);

    if (index == -1)
        return;

    scanf(" %29[^\n]", sts[index].name);
    scanf("%d", &sts[index].age);
    scanf("%f", &sts[index].marks);

    saveStudents();
}

void delete()
{
    int roll;
    int index;

    scanf("%d", &roll);

    index = findStudent(roll);

    if (index == -1)
        return;

    for (int i = index; i < count - 1; i++)
        sts[i] = sts[i + 1];

    count--;

    saveStudents();
}

int main()
{
    int choice;

    loadStudents();

    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                readStudents();
                break;

            case 3:
                update();
                break;

            case 4:
                delete();
                break;

            case 5:
                return 0;
        }
    }

    return 0;
}
