#include <stdio.h>

long long moves = 0;

void towerOfHanoi(int n, char s, char aux, char dest)
{
    if (n == 1)
    {
        printf("Move Disk %d from %c to %c\n", n, s, dest);
        moves++;
        return;
    }

    towerOfHanoi(n - 1, s, dest, aux);

    printf("Move Disk %d from %c to %c\n", n, s, dest);
    moves++;

    towerOfHanoi(n - 1, aux, s, dest);
}

int main()
{
    int n;

    printf("Enter Number of Disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    printf("Total Moves = %lld\n", moves);

    return 0;
}
