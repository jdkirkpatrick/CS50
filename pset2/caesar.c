#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int mod (int n);
string encrypt (string p, int k);

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You must enter one integer argument\n");
        return 1;
    }
    int k = atoi(argv[1]);
    if (k >= 26)
    {
        k = mod (k);
    }
    string p = GetString();
    string c = encrypt(p, k);
    printf("%s\n", c);
    return 0;
}

int mod (int n)
{
    do
    {
        n = n - 26;
    }while (n >= 26);
    return n;
}

string encrypt (string p, int k)
{
    string c = p;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        int t = p[i];
        if((t >= 65 && t <= 90) || (t >= 97 && t <= 122))
        {
            if((t >= 65 && t <= 90 && (t + k) > 90) || (t >= 97 && t <= 122 && (t + k) > 122))
            {
                t = t + k - 26;
            }
            else
            {
                t = t + k;
            }
        }
        c[i] = t;
    }
    return c;
}