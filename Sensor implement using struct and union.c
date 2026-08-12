#include <stdio.h>
#include <stdlib.h>

union Reading
{
    int intRead;
    float floatRead;
};

struct Sensor
{
    int id;
    char name[30];
    int type;
    union Reading readValue;
};

struct Sensor *readSensor()
{
    struct Sensor *s;

    s = (struct Sensor *)malloc(sizeof(struct Sensor));

    if(s == NULL)
        exit(1);

    scanf("%d", &s->id);
    scanf("%s", s->name);
    scanf("%d", &s->type);

    if(s->type == 1)
        scanf("%d", &s->readValue.intRead);
    else
        scanf("%f", &s->readValue.floatRead);

    return s;
}

void displaySensor(struct Sensor *s)
{
    printf("%d\n", s->id);
    printf("%s\n", s->name);

    if(s->type == 1)
        printf("%d\n", s->readValue.intRead);
    else
        printf("%.2f\n", s->readValue.floatRead);
}

void updateSensor(struct Sensor *s)
{
    if(s->type == 1)
        scanf("%d", &s->readValue.intRead);
    else
        scanf("%f", &s->readValue.floatRead);
}

int main()
{
    struct Sensor *s;

    s = readSensor();

    displaySensor(s);

    updateSensor(s);

    displaySensor(s);

    free(s);

    return 0;
}
