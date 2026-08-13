#include <stdio.h>

#define FRAMES 5
#define MAX_PROCESS 10

struct PageTable
{
    int Pid;
    int Pageno;
    int frameno;
};

struct PageTable pt[MAX_PROCESS];

int frame[FRAMES];
int totalentries = 0;

void initialize()
{
    int i;

    for(i = 0; i < FRAMES; i++)
    {
        frame[i] = 0;
    }
}

void allocatePage()
{
    int processid;
    int pagenumber;
    int i;

    scanf("%d", &processid);
    scanf("%d", &pagenumber);

    for(i = 0; i < FRAMES; i++)
    {
        if(frame[i] == 0)
        {
            frame[i] = 1;

            pt[totalentries].Pid = processid;
            pt[totalentries].Pageno = pagenumber;
            pt[totalentries].frameno = i;

            totalentries++;

            return;
        }
    }

    printf("Memory Full\n");
}

void deallocatePage()
{
    int processid;
    int pagenumber;
    int i;

    scanf("%d", &processid);
    scanf("%d", &pagenumber);

    for(i = 0; i < totalentries; i++)
    {
        if(pt[i].Pid == processid &&
           pt[i].Pageno == pagenumber)
        {
            frame[pt[i].frameno] = 0;

            pt[i] = pt[totalentries - 1];

            totalentries--;

            return;
        }
    }
}

void display()
{
    int i;

    for(i = 0; i < FRAMES; i++)
    {
        printf("%d ", frame[i]);
    }

    printf("\n");

    for(i = 0; i < totalentries; i++)
    {
        printf("%d %d %d\n",
               pt[i].Pid,
               pt[i].Pageno,
               pt[i].frameno);
    }
}

int main()
{
    int choice;

    initialize();

    while(1)
    {
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                allocatePage();
                break;
            }

            case 2:
            {
                deallocatePage();
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                return 0;
            }
        }
    }

    return 0;
}
