#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void hillEncrypt(char *key, char *text, char *cipher) {
    int len = strlen(key);
    int n = (int)sqrt(len);
    
    if (n * n != len) {
        printf("Error: Key length must be a perfect square (e.g., 4, 9, 16).\n");
        return;
    }

    // Dynamic VLA (Variable Length Array) based on key size
    int k[n][n];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            k[i][j] = toupper(key[idx++]) - 'A';
        }
    }

    int textLen = strlen(text);
    int remainder = textLen % n;
    char paddedText[500];
    strcpy(paddedText, text);
    
    // Pad with 'X' if length is not a multiple of n
    if (remainder != 0) {
        int padLen = n - remainder;
        for (int i = 0; i < padLen; i++) {
            paddedText[textLen++] = 'X';
        }
        paddedText[textLen] = '\0';
    }

    int c_idx = 0;
    // Process text in blocks of size n
    for (int i = 0; i < textLen; i += n) {
        int p[n];
        for (int j = 0; j < n; j++) {
            p[j] = paddedText[i + j] - 'A';
        }

        // Matrix multiplication: C = K * P mod 26
        for (int r = 0; r < n; r++) {
            int sum = 0;
            for (int c = 0; c < n; c++) {
                sum += k[r][c] * p[c];
            }
            int val = sum % 26;
            if (val < 0) val += 26;
            cipher[c_idx++] = val + 'A';
        }
    }
    cipher[c_idx] = '\0';
}

int main() {
    char key[100], plaintext[500], cleanText[500], cipherText[500];

    printf("Enter key string (e.g., 4 letters for 2x2, 9 letters for 3x3): ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Clean plaintext: keep only alphabetic characters and convert to uppercase
    int j = 0;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            cleanText[j++] = toupper(plaintext[i]);
        }
    }
    cleanText[j] = '\0';

    hillEncrypt(key, cleanText, cipherText);

    if (strlen(cipherText) > 0) {
        printf("Ciphertext: %s\n", cipherText);
    }

    return 0;
}