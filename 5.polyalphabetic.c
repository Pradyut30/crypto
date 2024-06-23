#include <stdio.h>
#include <string.h>
#include <ctype.h>


void encrypt(char *plaintext, char *key)
{
    int i, j;
    int key_len = strlen(key);
    int plain_len = strlen(plaintext);

    for (i = 0, j = 0; i < plain_len; ++i, ++j) 
    {
        if (j == key_len)
            j = 0;

        
        if (isalpha(plaintext[i])) 
        {
      
            int shift = tolower(key[j]) - 'a';

       
            if (isupper(plaintext[i])) 
            {
                plaintext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
            } 
           
            else 
            {
                plaintext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
            }
        }
    }
}
void decrypt(char *ciphertext, char *key) 
{
    int i, j;
    int key_len = strlen(key);
    int cipher_len = strlen(ciphertext);

    for (i = 0, j = 0; i < cipher_len; ++i, ++j) 
    {
        if (j == key_len)
            j = 0;

        
        if (isalpha(ciphertext[i])) 
        {
           
            int shift = tolower(key[j]) - 'a';

            
            if (isupper(ciphertext[i])) 
            {
                ciphertext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
            } 
            
            else 
            {
                ciphertext[i] = ((ciphertext[i] - 'a' - shift + 26) % 26) + 'a';
            }
        }
    }
}
int main() {
    char plaintext[1000];
    char key[100];
    char ciphertext[1000];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    printf("Original text: %s\n", plaintext);
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);
    decrypt(ciphertext, key);
    printf("Decrypted text: %s\n", ciphertext);
    return 0;
}
