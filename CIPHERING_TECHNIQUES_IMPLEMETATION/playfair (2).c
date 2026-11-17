/*
 * Playfair Cipher
 * Encrypts digraphs (pairs of letters) using a 5x5 key matrix.
 * 'J' is merged with 'I'.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];
int used[26];

void buildMatrix(char *keyword) {
    int i, j, k = 0;
    memset(used, 0, sizeof(used));
    used['J' - 'A'] = 1; // merge J with I

    // Fill keyword letters first
    for (i = 0; keyword[i] != '\0'; i++) {
        char c = toupper(keyword[i]);
        if (c == 'J') c = 'I';
        if (!used[c - 'A']) {
            used[c - 'A'] = 1;
            matrix[k / 5][k % 5] = c;
            k++;
        }
    }
    // Fill remaining letters
    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }
}

void printMatrix() {
    int i, j;
    printf("Playfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void findPos(char c, int *row, int *col) {
    int i, j;
    if (c == 'J') c = 'I';
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == c) { *row = i; *col = j; return; }
}

// Prepare plaintext: remove non-alpha, uppercase, handle duplicates, pad
int prepareText(char *in, char *out) {
    int i, len = 0;
    char temp[300];
    int t = 0;

    // Keep only alpha
    for (i = 0; in[i]; i++) {
        if (isalpha(in[i])) {
            char c = toupper(in[i]);
            if (c == 'J') c = 'I';
            temp[t++] = c;
        }
    }
    temp[t] = '\0';

    // Insert 'X' between duplicate pairs
    i = 0;
    while (i < t) {
        out[len++] = temp[i];
        if (i + 1 < t && temp[i] == temp[i + 1]) {
            out[len++] = 'X';
            i++;
        } else {
            if (i + 1 < t) out[len++] = temp[i + 1];
            i += 2;
        }
    }
    // Pad with 'X' if odd length
    if (len % 2 != 0) out[len++] = 'X';
    out[len] = '\0';
    return len;
}

void encrypt(char *prepared, char *cipher, int len) {
    int i, r1, c1, r2, c2;
    for (i = 0; i < len; i += 2) {
        findPos(prepared[i], &r1, &c1);
        findPos(prepared[i + 1], &r2, &c2);
        if (r1 == r2) {
            cipher[i]     = matrix[r1][(c1 + 1) % 5];
            cipher[i + 1] = matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipher[i]     = matrix[(r1 + 1) % 5][c1];
            cipher[i + 1] = matrix[(r2 + 1) % 5][c2];
        } else {
            cipher[i]     = matrix[r1][c2];
            cipher[i + 1] = matrix[r2][c1];
        }
    }
    cipher[len] = '\0';
}

void decrypt(char *cipher, char *plain, int len) {
    int i, r1, c1, r2, c2;
    for (i = 0; i < len; i += 2) {
        findPos(cipher[i], &r1, &c1);
        findPos(cipher[i + 1], &r2, &c2);
        if (r1 == r2) {
            plain[i]     = matrix[r1][(c1 + 4) % 5];
            plain[i + 1] = matrix[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            plain[i]     = matrix[(r1 + 4) % 5][c1];
            plain[i + 1] = matrix[(r2 + 4) % 5][c2];
        } else {
            plain[i]     = matrix[r1][c2];
            plain[i + 1] = matrix[r2][c1];
        }
    }
    plain[len] = '\0';
}

int main() {
    char keyword[100], plaintext[200];
    char prepared[300], ciphertext[300], decrypted[300];

    printf("=== Playfair Cipher ===\n");

    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    buildMatrix(keyword);
    printMatrix();

    int len = prepareText(plaintext, prepared);
    printf("Prepared Text : %s\n", prepared);

    encrypt(prepared, ciphertext, len);
    decrypt(ciphertext, decrypted, len);

    printf("Ciphertext    : %s\n", ciphertext);
    printf("Decrypted     : %s\n", decrypted);

    return 0;
}
