/*
 * Monoalphabetic Cipher
 * Each letter in the plaintext is mapped to a fixed substitute letter.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fixed substitution key (26 letters mapped to 26 unique letters)
char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void encrypt(char *plaintext, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i]))
                ciphertext[i] = key[plaintext[i] - 'A'];
            else
                ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
    int i, j;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char ch = toupper(ciphertext[i]);
            for (j = 0; j < 26; j++) {
                if (key[j] == ch) {
                    plaintext[i] = isupper(ciphertext[i]) ? ('A' + j) : ('a' + j);
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[200], ciphertext[200], decrypted[200];

    printf("=== Monoalphabetic Cipher ===\n");
    printf("Substitution Key: %s\n\n", key);

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    encrypt(plaintext, ciphertext);
    decrypt(ciphertext, decrypted);

    printf("Plaintext : %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}
