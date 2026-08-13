#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "students.dat"

struct Student
{
    int roll;
    char name[50];
    int age;
    float marks;
};

void create()
{
    FILE *fp = fopen(FILE_NAME, "wb");

    if (fp == NULL)
    {
        printf("Cant open");
        return;
    }

    int n;
    struct Student st;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &st.roll);
        scanf(" %[^\n]", st.name);
        scanf("%d", &st.age);
        scanf("%f", &st.marks);

        fwrite(&st, sizeof(st), 1, fp);
    }

    fclose(fp);
}

void access()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("Cant open");
        return;
    }

    int n;

    scanf("%d", &n);

    long offset = (n - 1) * sizeof(struct Student);

    fseek(fp, offset, SEEK_SET);

    struct Student st;

    if (fread(&st, sizeof(st), 1, fp) == 1)
    {
        printf("%d\n", st.roll);
        printf("%s\n", st.name);
        printf("%d\n", st.age);
        printf("%.2f\n", st.marks);
    }

    fclose(fp);
}

void fileinfo()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("Cant open");
        return;
    }

    fseek(fp, 0, SEEK_END);

    long fs = ftell(fp);
    long rs = sizeof(struct Student);
    long ns = fs / rs;

    printf("%ld\n", fs);
    printf("%ld\n", rs);
    printf("%ld\n", ns);

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                access();
                break;

            case 3:
                fileinfo();
                break;

            case 4:
                return 0;
        }
    }

    return 0;
}
