#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*A program that, given an amount of change into stdin, returns the lowest
amount of coins that would be necessary to make up that amount of money. */
int main(void)
{
    printf("Input the amount of change: ");
    float amt = round(100 * GetFloat());
    while (amt <= 0)
    {
        printf("Input the amount of change: ");
        amt = round(100 * GetFloat());
    }
    amt = (int) amt;
    int remaining = amt;
    int num = 0;
    while (remaining != 0)
    {
        if (remaining >= 25)
        {
            num++;
            remaining = remaining - 25;
        }
        else if (remaining >= 10)
        {
            num++;
            remaining = remaining - 10;
        }
        else if (remaining >= 5)
        {
            num++;
            remaining = remaining - 5;
        }
        else if (remaining >= 1)
        {
            num++;
            remaining = remaining - 1;
        }
    }
    printf("%d\n", num);
	return 0;
}

