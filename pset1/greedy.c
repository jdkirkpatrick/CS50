#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        printf("How much change?\n");
        change = GetFloat();
    }while(change < 0.00);
    change = round(change * 100);
    int cents = change;
    int coins = 0;
    while(cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    while(cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    while(cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    while(cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    printf("%i\n", coins);
}