#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute (base^exp) % modulus
int power(int base, int exp, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % modulus;
        exp = exp >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    // Prime number and primitive root
    int p, g;

    // Input prime number and primitive root from user
    printf("Enter the prime number (p): ");
    scanf("%d", &p);
    printf("Enter the primitive root (g): ");
    scanf("%d", &g);

    // Client and Server private keys
    int client_private_key, server_private_key;

    // Input private keys from user
    printf("Enter client's private key: ");
    scanf("%d", &client_private_key);
    printf("Enter server's private key: ");
    scanf("%d", &server_private_key);

    // Compute public keys
    int client_public_key = power(g, client_private_key, p);
    int server_public_key = power(g, server_private_key, p);

    // Exchange public keys (in a real-world scenario, this would be done over a secure channel)
    printf("Client's public key: %d\n", client_public_key);
    printf("Server's public key: %d\n", server_public_key);

    // Compute shared secret
    int client_shared_secret = power(server_public_key, client_private_key, p);
    int server_shared_secret = power(client_public_key, server_private_key, p);

    // Both client and server should have the same shared secret
    printf("Shared secret computed by client: %d\n", client_shared_secret);
    printf("Shared secret computed by server: %d\n", server_shared_secret);

    return 0;
}
