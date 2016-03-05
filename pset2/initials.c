#include <stdio.h>
#include <string.h>
#include <cs50.h>

void checkcap (char init);

int main (void)
{
    string name = GetString();
    checkcap(name[0]);
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ')
        {
            checkcap(name[i+1]);
        }
    }
    printf("\n");
}

void checkcap (char init)
{
    int n = init;
    if (n >= 97 && n <= 122)
        n = n - 32;
    init = n;
     printf("%c", init);
}