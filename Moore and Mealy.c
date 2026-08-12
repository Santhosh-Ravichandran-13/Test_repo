#include <stdio.h>

typedef enum
{
    S0,
    S1,
    S2,
    S3
} MooreState;

typedef enum
{
    M0,
    M1,
    M2
} MealyState;

void moore(char input[])
{
    MooreState state = S0;
    int i;

    for(i = 0; input[i] != '\0'; i++)
    {
        switch(state)
        {
            case S0:
            {
                if(input[i] == '0')
                {
                    state = S0;
                }
                else
                {
                    state = S1;
                }

                break;
            }

            case S1:
            {
                if(input[i] == '0')
                {
                    state = S2;
                }
                else
                {
                    state = S1;
                }

                break;
            }

            case S2:
            {
                if(input[i] == '0')
                {
                    state = S0;
                }
                else
                {
                    state = S3;
                }

                break;
            }

            case S3:
            {
                if(input[i] == '0')
                {
                    state = S2;
                }
                else
                {
                    state = S1;
                }

                break;
            }
        }

        printf("%c S%d\n", input[i], state);
    }
}

void mealy(char input[])
{
    MealyState state = M0;
    int i;

    for(i = 0; input[i] != '\0'; i++)
    {
        switch(state)
        {
            case M0:
            {
                if(input[i] == '0')
                {
                    state = M0;
                }
                else
                {
                    state = M1;
                }

                break;
            }

            case M1:
            {
                if(input[i] == '0')
                {
                    state = M2;
                }
                else
                {
                    state = M1;
                }

                break;
            }

            case M2:
            {
                if(input[i] == '0')
                {
                    state = M0;
                }
                else
                {
                    state = M1;
                }

                break;
            }
        }

        printf("%c M%d\n", input[i], state);
    }
}

int main()
{
    char input[100];

    scanf("%s", input);

    moore(input);

    mealy(input);

    return 0;
}
