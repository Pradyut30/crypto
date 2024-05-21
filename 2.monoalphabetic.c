#include <stdio.h>
#include <string.h>

char encryptChar(char ch, char key[]) {
    if (ch >= 'A' && ch <= 'Z') {
        return key[ch - 'A'];
    } else {
        return ch;
    }
}

char decryptChar(char ch, char key[]) {
    for (int i = 0; i < 26; i++) {
        if (ch == key[i]) {
            return 'A' + i;
        }
    }
    return ch;
}

void encryptMessage(char *plaintext, char *ciphertext, char *key) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        ciphertext[i] = encryptChar(plaintext[i], key);
    }
    ciphertext[length] = '\0';  // Null-terminate the ciphertext
}

void decryptMessage(char *ciphertext, char *plaintext, char *key) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        plaintext[i] = decryptChar(ciphertext[i], key);
    }
    plaintext[length] = '\0';  // Null-terminate the plaintext
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char decryptedtext[100];
    char key[27];

    // Prompt the user to enter the plaintext message
    printf("Enter the plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Prompt the user to enter the encryption key (26 uppercase letters)
    printf("Enter the encryption key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the plaintext message using the key
    encryptMessage(plaintext, ciphertext, key);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the ciphertext message back to plaintext using the key
    decryptMessage(ciphertext, decryptedtext, key);
    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}
