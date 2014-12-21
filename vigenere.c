/**
* vigenere.c
*
* cs50 problem set 2 
*
* Raymond Rupiah
*
*Implementation of a crypto program
*/
 
//include libraries and headers
#include <cs50.h>  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
 
int main (int argc, string argv[])
{
    //declare and initialize variables
    int key = 0;
    int b = 0;
    string k = argv[1];
    
    //ensure user entered a valid key
    if (argc != 2)
    {
        printf("Enter: /vigenere key\n");
        return 1;
    }
 
    else if (argv[1])
    {
        int l = strlen(argv[1]);
        for (int i = 0; i < l; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Enter: /vigenere key\n");
                return 1;
            }
        }
    }
    
    string plainTxt = GetString();
        
    //encrypt message
    for (int i = 0, n = strlen(plainTxt); i < n; i++)
        { 
            if (isalpha(plainTxt[i]))
            {
                key = b % strlen(k);
                if (islower(plainTxt[i]))
                {
                    if (islower(k[key]))
                    {
                        int small = ((plainTxt[i] - 97 + k[key] - 97) % 26) + 97;
                        printf("%c", small);
                    }
                    else
                    {
                        int small = ((plainTxt[i] - 97 + k[key] - 65) % 26) + 97;
                        printf("%c", small);
                    }
                }
                if (isupper(plainTxt[i]))
                {
                    if (islower(k[key]))
                    {
                        int big = ((plainTxt[i] - 65 + k[key] - 97) % 26) + 65;
                        printf("%c",  big);
                    }
                    else
                    {
                        int big = ((plainTxt[i] - 65 + k[key] - 65) % 26) + 65;
                        printf("%c", big);
                    }
                }
            b++;
            }
            else
            {
                //print encrypted message
                printf("%c", plainTxt[i]);
            }
        }
        printf("\n");
}