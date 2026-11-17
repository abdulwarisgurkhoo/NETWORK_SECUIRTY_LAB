/*
 * One Time Pad (OTP) Cipher
 * XOR-based cipher using a random key of the same length as the plaintext.
 * Theoretically unbreakable when the key is truly random and used only once.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LEN 200

// Generate a random key of given length (only printable ASCII)
void generateKey(char *key, int len) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < len; i++) {
        key[i] = (char)(rand() % 26 + 'A'); // random uppercase letter
    }
    key[len] = '\0';
}

// Encrypt: shift each alpha char by corresponding key char
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j = 0;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int shift = toupper(key[j]) - 'A';
            ciphertext[i] = base + (plaintext[i] - base + shift) % 26;
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

// Decrypt: reverse the shift using the same key
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j = 0;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int shift = toupper(key[j]) - 'A';
            plaintext[i] = base + (ciphertext[i] - base - shift + 26) % 26;
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[MAX_LEN], key[MAX_LEN], ciphertext[MAX_LEN], decrypted[MAX_LEN];

    printf("=== One Time Pad Cipher ===\n");

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Count only alphabetic chars for key length
    int alphaCount = 0;
    for (int i = 0; plaintext[i]; i++)
        if (isalpha(plaintext[i])) alphaCount++;

    generateKey(key, alphaCount);
    printf("Generated Key  : %s\n", key);

    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, decrypted);

    printf("Plaintext      : %s\n", plaintext);
    printf("Ciphertext     : %s\n", ciphertext);
    printf("Decrypted      : %s\n", decrypted);

    return 0;
}
