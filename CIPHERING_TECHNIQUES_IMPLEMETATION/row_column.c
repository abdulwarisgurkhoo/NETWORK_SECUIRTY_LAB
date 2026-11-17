/*
 * Row-Column (Columnar Transposition) Cipher
 * Writes plaintext row by row into a grid, then reads columns
 * in the order determined by the alphabetical rank of the keyword letters.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 300

// Get column order based on keyword (alphabetical rank)
void getOrder(char *key, int *order, int cols) {
    char sorted[cols + 1];
    int i, j;
    for (i = 0; i < cols; i++) sorted[i] = toupper(key[i]);
    sorted[cols] = '\0';

    // Simple selection-sort to find rank
    char temp[cols + 1];
    for (i = 0; i < cols; i++) temp[i] = sorted[i];

    for (i = 0; i < cols; i++) {
        char minChar = 'Z' + 1;
        int minIdx = -1;
        for (j = 0; j < cols; j++) {
            if (temp[j] < minChar) { minChar = temp[j]; minIdx = j; }
        }
        order[i] = minIdx;
        temp[minIdx] = 'Z' + 1; // mark as used
    }
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int cols = strlen(key);
    int len  = strlen(plaintext);
    int rows = (len + cols - 1) / cols;
    int order[cols];
    int i, j;

    // Fill grid with plaintext, pad with 'X'
    char grid[rows][cols];
    int k = 0;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            grid[i][j] = (k < len) ? plaintext[k++] : 'X';

    getOrder(key, order, cols);

    // Read columns in key order
    k = 0;
    for (i = 0; i < cols; i++)
        for (j = 0; j < rows; j++)
            ciphertext[k++] = grid[j][order[i]];
    ciphertext[k] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int cols = strlen(key);
    int len  = strlen(ciphertext);
    int rows = len / cols;
    int order[cols];
    int i, j;

    getOrder(key, order, cols);

    // Fill columns in key order
    char grid[rows][cols];
    int k = 0;
    for (i = 0; i < cols; i++)
        for (j = 0; j < rows; j++)
            grid[j][order[i]] = ciphertext[k++];

    // Read row by row
    k = 0;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            plaintext[k++] = grid[i][j];
    plaintext[k] = '\0';
}

int main() {
    char plaintext[MAX_LEN], key[50], ciphertext[MAX_LEN], decrypted[MAX_LEN];

    printf("=== Row-Column (Columnar Transposition) Cipher ===\n");

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter key      : ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, decrypted);

    printf("Plaintext : %s\n", plaintext);
    printf("Key       : %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}
