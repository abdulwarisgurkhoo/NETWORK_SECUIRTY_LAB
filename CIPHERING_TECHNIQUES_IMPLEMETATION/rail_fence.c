/*
 * Rail Fence Cipher
 * A transposition cipher that writes text in a zigzag pattern
 * across a number of "rails", then reads off row by row.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *plaintext, int rails, char *ciphertext) {
    int len = strlen(plaintext);
    // Create a 2D rail array
    char **fence = (char **)malloc(rails * sizeof(char *));
    int *idx = (int *)calloc(rails, sizeof(int));
    int i;

    for (i = 0; i < rails; i++)
        fence[i] = (char *)malloc((len + 1) * sizeof(char));

    // Fill the fence in zigzag order
    int rail = 0, dir = 1;
    for (i = 0; i < len; i++) {
        fence[rail][idx[rail]++] = plaintext[i];
        if (rail == 0) dir = 1;
        else if (rail == rails - 1) dir = -1;
        rail += dir;
    }

    // Read off row by row
    int k = 0;
    for (i = 0; i < rails; i++) {
        int j;
        for (j = 0; j < idx[i]; j++)
            ciphertext[k++] = fence[i][j];
        free(fence[i]);
    }
    ciphertext[k] = '\0';

    free(fence);
    free(idx);
}

void decrypt(char *ciphertext, int rails, char *plaintext) {
    int len = strlen(ciphertext);
    int *railLen = (int *)calloc(rails, sizeof(int));
    int i;

    // Calculate length of each rail
    int rail = 0, dir = 1;
    for (i = 0; i < len; i++) {
        railLen[rail]++;
        if (rail == 0) dir = 1;
        else if (rail == rails - 1) dir = -1;
        rail += dir;
    }

    // Split ciphertext into rails
    char **fence = (char **)malloc(rails * sizeof(char *));
    int pos = 0;
    for (i = 0; i < rails; i++) {
        fence[i] = (char *)malloc((railLen[i] + 1) * sizeof(char));
        strncpy(fence[i], ciphertext + pos, railLen[i]);
        fence[i][railLen[i]] = '\0';
        pos += railLen[i];
    }

    // Read off in zigzag order
    int *idx = (int *)calloc(rails, sizeof(int));
    rail = 0; dir = 1;
    for (i = 0; i < len; i++) {
        plaintext[i] = fence[rail][idx[rail]++];
        if (rail == 0) dir = 1;
        else if (rail == rails - 1) dir = -1;
        rail += dir;
    }
    plaintext[len] = '\0';

    for (i = 0; i < rails; i++) free(fence[i]);
    free(fence);
    free(railLen);
    free(idx);
}

int main() {
    char plaintext[200], ciphertext[200], decrypted[200];
    int rails;

    printf("=== Rail Fence Cipher ===\n");

    printf("Enter plaintext   : ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    if (rails < 2) {
        printf("Number of rails must be at least 2.\n");
        return 1;
    }

    encrypt(plaintext, rails, ciphertext);
    decrypt(ciphertext, rails, decrypted);

    printf("Plaintext : %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}
