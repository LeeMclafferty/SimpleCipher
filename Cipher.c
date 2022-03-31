#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // use user command line input to get the key
    // ask for plain text to encrypty
    // us ceasar ciphar to encrypt


    string Encrypt(string plain, int key);

    int key = 0;
    string plain_text = "plain text";
    string cipher_text = "cipher text";

    if (argv[1] != NULL)
    {
        //For loop checks for non-numeric digits in argv[1]
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("\nUsage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]);
        printf("Int: %i\n", key);
    }
    else
    {
        printf("\nUsage: ./caesar key\n");
        return 1;
    }

    if (key > 0 && argv[2] == NULL)
    {
        plain_text = get_string("\nEnter your message: ");
        printf("plaintext: ");
        printf("%s\n", plain_text);
        printf("ciphertext: ");
        printf("%s\n", Encrypt(plain_text, key));
    }
    else
    {
        printf("\nUsage: ./caesar key\n");
        return 1;
    }
}

string Encrypt(string plain, int key)
{
    // cipher[i] = (plain_text[i] + k)%26
    string cipher = plain;
    for (int i = 0; i < strlen(plain); i++)
    {
        /* We need the alphabet to index a to 0 in order for us to loop back
        around when we hit the end. So we subtract the value of a putting each
        letter in the righ spot 0-26. But after we get the remiender, it has
        to be converted back to ascii, so we add the value back. */
        if (isupper(plain[i]))
        {
            cipher[i] = (plain[i] + key - 'A') % 26 + 'A';
        }
        if (islower(plain[i]))
        {
            cipher[i] = (plain[i] + key - 'a') % 26 + 'a';
        }
    }

    return cipher;
}