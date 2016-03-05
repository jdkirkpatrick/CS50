#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkinput (int n, string p);
//checks to make sure the user provided a single alphabetic value
void encrypt (string p, string k);
//encrypts plain text (p) using key (k)
int keyletternumber (char m);
//converts key ascii value to letter number

int main (int argc, string argv[])
{
    string key = argv[1];
    if (checkinput(argc, key))
    {
        return 1;
    }
    //get plain text to be encrypted
    string plain = GetString();
    //encrypt plain text
    encrypt (plain, key);
    
    return 0;
}

int checkinput (int n, string p)
{
    //checks for valid input
    //returns true (1) if invalid, returns false (0) if valid
    if (n != 2)
    {
        //checks that the user entered exactly one argument
        printf("You must enter one argument\n");
        return 1;
    }
    for (int i = 0, j = strlen(p); i < j; i++)
    {
        if (!isalpha (p[i]))
        {
            //checks that the provided argument contains only alphabetic characters
            printf("Please enter only alphabetic characters\n");
            return 1;
        }
    }
    return 0;
}

void encrypt (string p, string k)
{
    string c = p;
    //string to store encrypted text
    int j = 0;
    //incrementor for key string (k)
    int y;
    // store ascii value of text in below loop
    int z;
    //store ascii value of key in below loop
    for (int i = 0, n = strlen (p); i < n; i++)
    {
        if (isalpha (p[i]))
        {
            y = p[i];
            z = keyletternumber(k[j]);
            //check if the 
            if((y >= 65 && y <= 90 && (y + z) > 90) || (y >= 97 && y <= 122 && (y + z) > 122))
            {
                y = y + z - 26;
            }
            else
            {
                y = y + z;
            }
            //assign new character to encrpyted string
            c[i] = y;
            //increment location in key
            j++;
            //check if we've reached the end of the key
            if (j == strlen(k))
            {
                //reset the key if we've reached the end
                j = 0;
            }
        }
        else
        {
            c[i] = p[i];
        }
    }
    printf("%s\n", c);
}

int keyletternumber (char m)
{
    int q = m;
    if (q >= 65 && q <= 90)
    {
        q = q - 65;
    }
    else if (q >= 97 && q <= 122)
    {
        q = q - 97;
    }
    return q;
}