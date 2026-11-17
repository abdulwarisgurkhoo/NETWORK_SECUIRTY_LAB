/*
 * Vigenere Cipher
 * A polyalphabetic cipher that uses a repeating keyword to shift letters.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j = 0;
    int keyLen = strlen(key);

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLen]) - 'A';
            ciphertext[i] = base + (plaintext[i] - base + shift) % 26;
            j++;
        } else {
            ciphertext[i] = plaintext[i]; // keep spaces/punctuation
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j = 0;
    int keyLen = strlen(key);

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLen]) - 'A';
            plaintext[i] = base + (ciphertext[i] - base - shift + 26) % 26;
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[200], key[100], ciphertext[200], decrypted[200];

    printf("=== Vigenere Cipher ===\n");

    printf("Enter plaintext : ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter key       : ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, decrypted);

    printf("\nPlaintext : %s\n", plaintext);
    printf("Key       : %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}
