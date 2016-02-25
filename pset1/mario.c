#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("height: ");
        height = GetInt();
    }while(height < 0 || height > 23);
    int blocks = 2;
    for(int count = height; count > 0; count--)
    {
        for(int count1 = height - 1; count1 > 0; count1--)
        {
            printf(" ");
        }
        for(int count2 = blocks; count2 > 0; count2--)
        {
            printf("#");
        }
        printf("\n");
        blocks++;
        height--;
    }
}