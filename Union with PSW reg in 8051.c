#include <stdio.h>

union PSW
{
    unsigned char reg;

    struct
    {
        unsigned char P   : 1;
        unsigned char     : 1;
        unsigned char OV  : 1;
        unsigned char RS0 : 1;
        unsigned char RS1 : 1;
        unsigned char F0  : 1;
        unsigned char AC  : 1;
        unsigned char CY  : 1;
    } bits;
};

int main()
{
    union PSW psw;
    char ch;

    psw.reg = 0x00;

    do
    {
        printf("\nEnter flag: ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case 'C':
                psw.bits.CY = 1;
                break;

            case 'A':
                psw.bits.AC = 1;
                break;

            case 'F':
                psw.bits.F0 = 1;
                break;

            case '1':
                psw.bits.RS1 = 1;
                break;

            case '0':
                psw.bits.RS0 = 1;
                break;

            case 'O':
                psw.bits.OV = 1;
                break;

            case 'P':
                psw.bits.P = 1;
                break;

            case 'D':
                printf("PSW : 0x%02X\n", psw.reg);
                break;

            case 'X':
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(ch != 'X');

    return 0;
}
