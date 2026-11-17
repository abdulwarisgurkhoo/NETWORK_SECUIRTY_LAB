#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to generate the 5x5 key matrix
void generateMatrix(char *key, char matrix[SIZE][SIZE]) {
    int visited[26] = {0};
    int r = 0, c = 0;
    visited['J' - 'A'] = 1; // 'J' is merged with 'I'

    // Insert unique characters from the key
    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (isalpha(ch) && !visited[ch - 'A']) {
            matrix[r][c++] = ch;
            visited[ch - 'A'] = 1;
            if (c == SIZE) {
                c = 0;
                r++;
            }
        }
    }

    // Insert remaining alphabet letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!visited[ch - 'A']) {
            matrix[r][c++] = ch;
            visited[ch - 'A'] = 1;
            if (c == SIZE) {
                c = 0;
                r++;
            }
        }
    }
}

// Function to find coordinates of a character in the matrix
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt plaintext using the Playfair rules
void encryptPlayfair(char matrix[SIZE][SIZE], char *text, char *cipher) {
    int len = strlen(text);
    int idx = 0;

    for (int i = 0; i < len; i += 2) {
        char first = text[i];
        char second = (i + 1 < len) ? text[i + 1] : 'X';

        // If duplicate letters in a pair, insert 'X' and adjust index
        if (first == second) {
            second = 'X';
            i--; 
        }

        int r1, c1, r2, c2;
        findPosition(matrix, first, &r1, &c1);
        findPosition(matrix, second, &r2, &c2);

        if (r1 == r2) {
            // Same row: shift right with wrap-around
            cipher[idx++] = matrix[r1][(c1 + 1) % SIZE];
            cipher[idx++] = matrix[r2][(c2 + 1) % SIZE];
        } else if (c1 == c2) {
            // Same column: shift down with wrap-around
            cipher[idx++] = matrix[(r1 + 1) % SIZE][c1];
            cipher[idx++] = matrix[(r2 + 1) % SIZE][c2];
        } else {
            // Rectangle rule: swap column coordinates
            cipher[idx++] = matrix[r1][c2];
            cipher[idx++] = matrix[r2][c1];
        }
    }
    cipher[idx] = '\0';
}

int main() {
    char key[100], plaintext[200], cleanText[200] = "", cipherText[400];
    char matrix[SIZE][SIZE];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Clean plaintext: keep only alphabetic characters and convert to uppercase
    int j = 0;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            cleanText[j++] = toupper(plaintext[i]);
        }
    }
    cleanText[j] = '\0';

    generateMatrix(key, matrix);
    encryptPlayfair(matrix, cleanText, cipherText);

    printf("\nGenerated 5x5 Key Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            printf("%c ", matrix[i][k]);
        }
        printf("\n");
    }

    printf("\nCiphertext: %s\n", cipherText);

    return 0;
}