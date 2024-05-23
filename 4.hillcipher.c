#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

void encrypt(char *message, int key[][MAX_LEN], int n1, int n2) {
    int i, j, k;
    int len = strlen(message);
    int cipher[len];
    
    // Convert each character to its numerical equivalent (A=0, B=1, ..., Z=25)
    for (i = 0; i < len; i++) {
        cipher[i] = message[i] - 'A';
    }
    
    // Pad the message with 'X' to make its length a multiple of n2
    while (len % n2 != 0) {
        message[len] = 'X';
        cipher[len] = 23;  // 'X' is 23 in our number system
        len++;
    }
    
    
    for (i = 0; i < len; i += n2) {
        for (j = 0; j < n1; j++) {
            int sum = 0;
            for (k = 0; k < n2; k++) {
                sum += key[j][k] * cipher[i + k];
            }
            encrypted_message[i + j] = (sum % 26) + 'A';
        }
    }
    encrypted_message[len] = '\0';  // Null-terminate the encrypted message
 
}

int main() {
    char message[MAX_LEN];
    int n1, n2, i, j;

    // Input key matrix dimensions
    printf("Enter the number of rows in the key matrix: ");
    scanf("%d", &n1);
    printf("Enter the number of columns in the key matrix: ");
    scanf("%d", &n2);

    int key[MAX_LEN][MAX_LEN];
    printf("Enter the key matrix:\n");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            scanf("%d", &key[i][j]);
        }
    }

   
    // Input the message to encrypt
    printf("Enter the message you want to encrypt (uppercase letters only):\n");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove the newline character

    encrypt(message, key, n1, n2);

    printf("The encrypted message is: %s\n", message);
    return 0;
}
