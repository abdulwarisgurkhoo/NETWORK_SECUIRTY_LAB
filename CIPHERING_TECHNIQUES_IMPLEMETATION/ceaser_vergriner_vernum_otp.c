#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. Caesar Cipher
void caesarCipher(char text[], int shift) {
    printf("Caesar Encrypted: ");
    for(int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if(ch >= 'a' && ch <= 'z') printf("%c", (ch - 'a' + shift) % 26 + 'a');
        else if(ch >= 'A' && ch <= 'Z') printf("%c", (ch - 'A' + shift) % 26 + 'A');
        else printf("%c", ch);
    }
    printf("\n");
}

// 4. Vigenère Cipher
void vigenereCipher(char text[], char key[]) {
    int keyLen = strlen(key);
    printf("Vigenere Encrypted: ");
    for(int i = 0, j = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if(isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char keyBase = islower(key[j % keyLen]) ? 'a' : 'A';
            int shift = key[j % keyLen] - keyBase;
            printf("%c", (ch - base + shift) % 26 + base);
            j++;
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");
}

// 5 & 6. Vernam Cipher / One-Time Pad (OTP)
void vernamOTP(char text[], char key[]) {
    printf("Vernam/OTP Encrypted (Hex): ");
    for(int i = 0; text[i] != '\0'; ++i) {
        // XOR plaintext with key
        printf("%02X ", text[i] ^ key[i]); 
    }
    printf("\n");
}

int main() {
    char text[] = "hello";
    caesarCipher(text, 3);
    vigenereCipher(text, "key");
    vernamOTP(text, "apple"); // Key must be at least as long as text
    return 0;
}